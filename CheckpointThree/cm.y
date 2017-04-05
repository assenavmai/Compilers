/************************************************
* File: cm.l 
* Yacc specification for CMinus
* Authors: Jasmine Kandloosi and Vanessa White
* February 2017
*************************************************/

%{
    #define YYPARSER

    #include "globals.h"
    #include "util.h"
    #include "scan.h"
    #include "parse.h"
    #include "symlist.h"

    #define YYSTYPE tokenTypes

    extern FILE * yyin;
    static struct TreeNode * syntaxTree; /* save the syntax tree to be returned */
    static char * savedName; /* for use in assignments */
    static int savedLineNo;  /* ditto */
    static int lineFunc;
    struct symhash * checkOne, *checkTwo;
    static int invalidVoid = -1;
    static int returnValue = -1;
    static int varLoc = 0;
    static int amountParam = 0;
    static int amountArgs = 0;

    struct symlist * tempHead;
    enum StmtKind stmtCheck = -1;
    int inScope = -1;

    static int ofpLocation = 0;
    static int initLocation = -2;
    static int declOffset = 0;

    extern yychar;

    typedef union tokenTypes
    {
        struct TreeNode * tnode;
        enum ExpType type;
        char * str;
        int op;
    }tokenTypes;


    void yyerror()
    {
           //fprintf(stderr,"line %d: error: \t",lineno);
            fprintf(stderr, "\nline %d: syntax error at: current token: \t%s\n", lineno, currLine);
            //printToken(yychar, tokenString);

    }

    int yywrap()
    {
            return 1;
    } 

   static int yylex(void)
    { return getToken(); }

    struct TreeNode * parse(void) { 

        yyparse();
        return syntaxTree;
    }


%}

%token IF ELSE INT RETURN VOID WHILE
%token ID NUM
%token PLUS MINUS MULT DIV LT GT LTEQ GTEQ DOUBEQ NEQ EQ SEMI COMMA LPAREN RPAREN LBRAC RBRAC LCURL RCURL 
%token ERROR

%nonassoc LT GT LTEQ GTEQ NEQ DOUBEQ
%nonassoc NO_ELSE
%nonassoc ELSE
%left PLUS MINUS
%left MULT DIV
%right EQ

%% /* Grammar for C- */


program         : decl_list
                    { syntaxTree = $1.tnode; } //root of tree
                ;

decl_list       : decl_list decl
                    {
                        struct TreeNode * temp;
                        temp = $1.tnode; 

                        if(temp)
                        {
                            while(temp->sibling) // find the node without a sibling
                            {
                                temp = temp->sibling;
                            }
                            temp->sibling = $2.tnode; // make the sibling the 
                            $$.tnode = $1.tnode;
                        }
                        else
                        {
                            $$.tnode = $2.tnode;
                        }
                    }

                | decl
                    {  $$.tnode = $1.tnode; }
                ;

decl            : var_decl
                    { $$.tnode = $1.tnode; }
                | fun_decl 
                    { $$.tnode = $1.tnode; }
                | error { fprintf(stderr, "Error in declaration\n");}
                ;

var_decl        : type_spec ID {    savedName = copyString(idString); 
                                    savedLineNo = lineno; } 
                    SEMI 
                    { 
                        $$.tnode = newDeclNode(VarK);
                        $$.tnode->name = savedName;
                        $$.tnode->etype = $1.type;
                        $$.tnode->pos = savedLineNo;
                        $$.tnode->memoryLocation = ++varLoc;
                        printf("var decl param %s %d\n", savedName,$$.tnode->memoryLocation);

                        if(searchList(globalList, savedName))
                        {
                            fprintf(stderr, "line: %d: error: '%s' is previously declared\n", savedLineNo, savedName);
                        }
                        else
                        {
                            globalList->table = addToTable(globalList->table, savedName, $1.type, 0, savedLineNo, $$.tnode->memoryLocation);
                            stack->table = addToTable(stack->table, savedName, $1.type, 0, savedLineNo, $$.tnode->memoryLocation);
                        }
                    }
                | type_spec ID {    savedName = copyString(idString); 
                                    savedLineNo = lineno; } 
                    LBRAC NUM RBRAC SEMI
                    { 
                        $$.tnode = newDeclNode(VarK);
                        $$.tnode->name = savedName;
                        $$.tnode->etype = Array;
                        $$.tnode->val = atoi(numString);
                        $$.tnode->pos = savedLineNo;
                        $$.tnode->memoryLocation = ++varLoc;

                        if($$.tnode->val < 0)
                        {
                            fprintf(stderr, "line: %d: error: array %s has a index which is out of bounds\n", savedLineNo, savedName);
                        }

                        if(lookup(globalList->table, savedName))
                        {
                            fprintf(stderr, "line: %d: error: '%s' is previously declared\n", savedLineNo, savedName);
                        }
                        else
                        {
                            globalList->table = addToTable(globalList->table, savedName, Array, $$.tnode->val, savedLineNo, $$.tnode->memoryLocation);
                            stack->table = addToTable(stack->table, savedName, $1.type, 0, savedLineNo, $$.tnode->memoryLocation);
                        }
                    }
              //  | error SEMI {  yyerrok; yyclearin; fprintf(stderr, "\tVariable declaration is invalid\n");}
                ;

type_spec       : INT 
                    { $$.type = Integer; }
                | VOID
                    { $$.type = Void; }
              //  | error { yyerrok; yyclearin; fprintf(stderr, "\t Invalid type specifier\n"); }
                ;

fun_decl        : type_spec ID { $$.str = copyString(idString);
                                lineFunc = lineno; } 
                    LPAREN params RPAREN compound_stmt
                    {
                        $$.tnode = newDeclNode(FunK);

                        $$.tnode->name = $3.str;
                        $$.tnode->etype = $1.type;
                        $$.tnode->pos = lineFunc;
                        $$.tnode->child[0] = $5.tnode;
                        $$.tnode->child[1] = $7.tnode;
                        $$.tnode->params = amountParam;
                        $$.tnode->memoryLocation = ++varLoc + 1;

                        printf("func decl location %d\n", varLoc);

                        if(lookup(globalList->table, $3.str))
                        {
                            fprintf(stderr, "line: %d: error: '%s' is previously declared\n", savedLineNo, $3.str);
                        }
                        else
                        {
                            globalList->table = addToTable(globalList->table, $3.str, $1.type, 0, lineFunc, $$.tnode->memoryLocation);
                            stack->table = addToTable(stack->table, $3.str, $1.type, 0, lineFunc, $$.tnode->memoryLocation);
                        }

                        if(returnValue == 1 && $1.type == 0)
                        {
                            fprintf(stderr, "line: %d: error: void function '%s' cannot have a return of a value\n", savedLineNo, $3.str);
                        }
                        else if(returnValue != 1 && $1.type == 1)
                        {
                            fprintf(stderr, "line: %d: error: int function '%s' needs to have a return value\n", savedLineNo, $3.str);
                        }
                        returnValue = -1;
                        //printSymbolTable(globalList);
                        //globalList = deleteNode(globalList);


                    }
                    | LPAREN error RPAREN compound_stmt { fprintf(stderr, "Error in function declaration statement\n"); } 
                ;

params          : param_list
                    { $$.tnode = $1.tnode; } 
                | VOID
                    {}
                ;

param_list      : param_list COMMA param
                    {
                        /* sibling stuff */
                        struct TreeNode * temp;
                        temp = $1.tnode;

                        if(temp)
                        {
                            while(temp->sibling)
                            {
                                temp = temp->sibling;
                            }
                            temp->sibling = $3.tnode;
                            $$.tnode = $1.tnode;
                        }
                        else
                        {
                            $$.tnode = $3.tnode;
                        }

                         amountParam++;

                    }
                | param
                    {  amountParam++; $$.tnode = $1.tnode; }
                | error  { yyerrok; yyclearin; fprintf(stderr, "\tError in the parameter list:\n");} 
                ;

param           : type_spec ID 
                    {
                        varLoc = amountParam + 1;
                        printf("param %d\n", varLoc);
                        $$.tnode = newDeclNode(ParamK);
                        $$.tnode->pos = lineno;
                        $$.tnode->name = copyString(idString);
                        $$.tnode->etype = $1.type;
                        $$.tnode->memoryLocation = varLoc;

                        printf("%d memLoc param\n", $$.tnode->memoryLocation);

                        if(lookup(globalList->table, idString))
                        {
                            fprintf(stderr, "line: %d: error: '%s' is previously declared\n", lineno, idString);
                        }
                        else
                        {
                            globalList->table = addToTable(globalList->table, idString, $1.type, 0, lineno, varLoc);
                            stack->table = addToTable(stack->table, idString, $1.type, 0, lineno, varLoc);
                        }
                    }
                | type_spec ID {    savedName = copyString(idString);
                                    savedLineNo = lineno; }
                    LBRAC RBRAC
                    {
                        varLoc = amountParam + 1;
                        $$.tnode = newDeclNode(ParamK);
                        $$.tnode->pos = savedLineNo;
                        $$.tnode->name = savedName;
                        $$.tnode->etype = Array;
                        $$.tnode->memoryLocation = varLoc;


                        if(lookup(globalList->table, savedName))
                        {
                            fprintf(stderr, "line: %d: error: '%s' is previously declared\n", savedLineNo, savedName);
                        }
                        else
                        {
                            globalList->table = addToTable(globalList->table, savedName, $1.type, 0, savedLineNo, varLoc);
                            stack->table = addToTable(stack->table, savedName, $1.type, 0, savedLineNo, varLoc);
                        }
                    }
                ;

compound_stmt   : LCURL{
                            position++;
                            sPos++;
                            symtable[position] = createTable();
                            stackTable[sPos] = createTable();

                            globalList = addToList(globalList, symtable[position]);
                            stack = addToList(stack, stackTable[sPos]);
                        } 
                    local_decl stmt_list RCURL
                    {
                        $$.tnode = newStmtNode(CmpdK);
                        $$.tnode->child[0] = $3.tnode;
                        $$.tnode->child[1] = $4.tnode;

                        struct symlist * t;

                        globalList = deleteNode(globalList);

                        position--;
                    }
                | LCURL error RCURL { yyerrok; fprintf(stderr, "Error in compound statement\n"); } 
                ;

local_decl      : local_decl var_decl
                    {
                        /*sibling stuff */
                        struct TreeNode * temp;
                        temp = $1.tnode;

                        if(temp)
                        {
                            while(temp->sibling)
                            {
                                temp = temp->sibling;
                            }
                            temp->sibling = $2.tnode;
                            $$.tnode = $1.tnode;

                        }
                        else
                        {
                            $$.tnode = $2.tnode;
                        }
                    }
                | epsilon { $$.tnode = NULL; }
                ;

stmt_list       : stmt_list stmt
                    {
                        /* sibling stuff */
                        struct TreeNode * temp;
                        temp = $1.tnode;

                        if(temp)
                        {
                            while(temp->sibling)
                            {
                                temp = temp->sibling;
                            }
                            temp->sibling = $2.tnode;
                            $$.tnode = $1.tnode;
                        }
                        else
                        {
                            $$.tnode = $2.tnode;
                        }
                    }
                | epsilon { $$.tnode = NULL; }
                ;

stmt            : expr_stmt
                    { }
                | compound_stmt
                    { $$.tnode = $1.tnode; }
                | select_stmt
                    { $$.tnode = $1.tnode; }
                | iter_stmt
                    { $$.tnode = $1.tnode; }
                | return_stmt
                    { $$.tnode = $1.tnode; }
                ;

expr_stmt       : expr SEMI
                    { $$.tnode = $1.tnode; }
                | SEMI
                    {}
                ;

select_stmt     : IF LPAREN expr RPAREN stmt %prec NO_ELSE
                    {
                        $$.tnode = newStmtNode(IfK);
                        $$.tnode->child[0] = $3.tnode;
                        $$.tnode->child[1] = $5.tnode;

                        if(invalidVoid == 1)
                        {
                            fprintf(stderr, "line: %d: error: if statement condition must be of type int\n", lineno);
                        }
                        invalidVoid = -1;
                    }
                | IF LPAREN expr RPAREN stmt ELSE stmt
                    {
                        $$.tnode = newStmtNode(IfK);
                        $$.tnode->child[0] = $3.tnode;
                        $$.tnode->child[1] = $5.tnode;
                        $$.tnode->child[2] = $7.tnode;

                        if(invalidVoid == 1)
                        {
                            fprintf(stderr, "line: %d: error: if-else statement condition must be of type int\n", lineno);
                        }
                        invalidVoid = -1;
                    }
                | IF LPAREN error RPAREN { yyerrok; fprintf(stderr, "Error in selection (if) statement\n"); } 
                ;

iter_stmt       : WHILE LPAREN expr RPAREN stmt
                    {
                        $$.tnode = newStmtNode(WhileK);
                        $$.tnode->child[0] = $3.tnode;
                        $$.tnode->child[1] = $5.tnode;

                        if(invalidVoid == 1)
                        {
                            fprintf(stderr, "line: %d: error: while statement condition must be of type int\n", lineno);
                        }

                        invalidVoid = -1;
                    }
                | WHILE LPAREN error RPAREN { yyerrok; fprintf(stderr, "Error in iteration (while) statement\n"); }
                ;

return_stmt     : RETURN SEMI
                    {
                        $$.tnode = newStmtNode(ReturnK);
                        $$.tnode->child[0] = NULL;
                        returnValue = 0;
                    }
                | RETURN expr SEMI
                    {
                        $$.tnode = newStmtNode(ReturnK);
                        $$.tnode->child[0] = $2.tnode;
                        returnValue = 1;
                    }
                | RETURN error SEMI { yyerrok; fprintf(stderr, "Error in return statement\n"); }

                ;

expr            : var EQ expr
                    {
                        $$.tnode = newStmtNode(AssignK);
                        $$.tnode->child[0] = $1.tnode;
                        $$.tnode->op = EQ;
                        $$.tnode->child[1] = $3.tnode;

                        if(invalidVoid == 1)
                        {
                            fprintf(stderr, "line: %d: error: type of left-hand size of expression does not match type of right-hand side\n", lineno);
                        }
                        invalidVoid = -1;

                    }
                | simple_expr
                    { $$.tnode = $1.tnode; }
                ;

var             : ID
                    { 
                        /* check if undeclared */
                        $$.tnode = newExpNode(IdK);
                        $$.tnode->name = copyString(idString);
                        $$.tnode->memoryLocation = findMemoryLocation(globalList, savedName);

                        /*int l = findMemoryLocation(globalList, savedName);*/
                        printf("OK BOYS %s %d\n", idString, $$.tnode->memoryLocation);

                        if(!searchList(globalList, idString))
                        {

                            fprintf(stderr, "line: %d: error: '%s' is undeclared\n", lineno, idString);
                            globalList->table = addToTable(globalList->table, idString, Undeclared, 0, lineno, $$.tnode->memoryLocation);
                            
                        }

                        // check if the type being used is valid for the variable
                       // checkOne = lookup(globalList->table, idString);
                       checkOne = searchList(globalList, idString);

                        if(checkOne->type == 0)
                        {
                            invalidVoid = 1;
                        }

                    }
                | ID {  savedName = copyString(idString);
                        savedLineNo = lineno; }
                    LBRAC expr RBRAC
                    {
                        $$.tnode = newExpNode(IdK);
                        $$.tnode->name = savedName;
                        $$.tnode->pos = savedLineNo;
                        $$.tnode->isArr = 1;
                        $$.tnode->child[0] = $4.tnode;
                        $$.tnode->memoryLocation = findMemoryLocation(globalList, savedName);

                        if(!searchList(globalList, savedName))
                        {
                            fprintf(stderr, "line: %d: error: '%s' is undeclared\n", savedLineNo, savedName);
                            globalList->table = addToTable(globalList->table, savedName, Undeclared, 0, savedLineNo, -1000);
                        }

                        // check if the index being used for the array is of type int
                        //checkOne = lookup(globalList->table, $4.tnode->name);

                        checkOne = searchList(globalList, $4.tnode->name);
                        if(checkOne->type != 1)
                        {
                            fprintf(stderr, "line: %d: error: array '%s' needs an index of type int\n", savedLineNo, savedName);
                        }

                        // check if the type being used is valid for the variable
                       // checkOne = lookup(globalList->table, idString);

                       checkOne = searchList(globalList, idString);
                        if(checkOne->type == 0)
                        {
                            invalidVoid = 1;
                            //printf("%s is of type void\n", checkOne->key);
                        }
                    }
                ;

simple_expr     : additive_expr relop additive_expr
                    {
                        $$.tnode = newExpNode(OpK);
                        $$.tnode->child[0] = $1.tnode;
                        $$.tnode->op = $2.op;
                        $$.tnode->child[1] = $3.tnode;
                    }
                | additive_expr
                    { $$.tnode = $1.tnode; }

                ;

relop           : LTEQ
                    { $$.op = LTEQ; }
                | LT
                    { $$.op = LT; }
                | GT
                    { $$.op = GT; }
                | GTEQ
                    { $$.op = GTEQ; }
                | DOUBEQ
                    { $$.op = DOUBEQ; }
                | NEQ
                    { $$.op = NEQ; }
                ;

additive_expr   : additive_expr addop term
                    {
                        $$.tnode = newExpNode(OpK);
                        $$.tnode->child[0] = $1.tnode;
                        $$.tnode->op = $2.op;
                        $$.tnode->child[1] = $3.tnode;
                    }
                | term
                    { $$.tnode = $1.tnode; }
                ;

addop           : PLUS
                    { $$.op = PLUS; }
                | MINUS
                    { $$.op = MINUS; }
                ;

term            : term mulop factor
                    { 
                        $$.tnode = newExpNode(OpK);
                        $$.tnode->child[0] = $1.tnode;
                        $$.tnode->op = $2.op;
                        $$.tnode->child[1] = $3.tnode;
                    }
                | factor
                    { $$.tnode = $1.tnode; }
                ;

mulop           : MULT
                    { $$.op = MULT; }
                | DIV
                   { $$.op = DIV; }
                ;

factor          : LPAREN expr RPAREN
                    {
                        $$.tnode = $2.tnode;
                    }
                | var
                    { $$.tnode = $1.tnode; }
                | call
                    { $$.tnode = $1.tnode; }
                | NUM
                    {
                        $$.tnode = newExpNode(ConstK);
                        $$.tnode->val = atoi(numString);
                    }

                ;

call            : ID {  savedName = copyString(idString);
                        savedLineNo = lineno; }
                    LPAREN args RPAREN
                    {
                        $$.tnode = newStmtNode(CallK);
                        $$.tnode->name = savedName;
                        $$.tnode->child[0] = $4.tnode;
                        $$.tnode->pos = savedLineNo;
                        printf("Call %s\n", savedName);

                        // check arguments match with amount of parameters for function
                        // add input and output to sym table
                        // check is $$..params = args, if not error msg
                       
                        printf("amount args %s %d params %d\n", savedName, amountArgs, amountParam);

                    }
                ;

args            : arg_list
                    { $$.tnode = $1.tnode; }
                | epsilon { $$.tnode = NULL; }
                ;

arg_list        : arg_list COMMA expr
                    {
                        /* siblng stuff */
                        struct TreeNode * temp;
                        temp = $1.tnode;

                        if(temp)
                        {
                            while(temp->sibling)
                            {
                                temp = temp->sibling;
                            }
                            temp->sibling = $3.tnode;
                            $$.tnode = $1.tnode;
                        }
                        else
                        {
                            $$.tnode = $3.tnode;
                        }

                        amountArgs++;
                    }
                | expr
                    { amountArgs++; $$.tnode = $1.tnode; }
                ;

epsilon         : ;                    
%%

