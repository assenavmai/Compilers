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
    #include "symhash.h"

    #define YYSTYPE tokenTypes

    extern FILE * yyin;
    static struct TreeNode * syntaxTree; /* save the syntax tree to be returned */
    static char * savedName; /* for use in assignments */
    static int savedLineNo;  /* ditto */

    typedef union tokenTypes
    {
        struct TreeNode * tnode;
        enum ExpType type;
        char * str;
        int op;
    }tokenTypes;


    void yyerror(char *str)
    {
            fprintf(stderr,"Line #%d: %s\t",lineno, str);
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

%nonassoc LT GT LTEQ GTEQ
%nonassoc NO_ELSE
%nonassoc ELSE
%left PLUS MINUS
%left MULT DIV



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

                        //insert
                        if(lookup(ht, savedName) != NULL)
                        {
                            printf("var_decl 1: line: %d: error: '%s' is previously declared\n", savedLineNo, savedName);
                        }
                        else
                        {
                            insert(ht, savedName, $1.type, 0, savedLineNo);
                        }

                    }
                | type_spec ID {    savedName = copyString(idString); 
                                    savedLineNo = lineno; } 
                    LBRAC NUM RBRAC SEMI
                    { 
                        $$.tnode = newDeclNode(VarK);
                        $$.tnode->val = atoi(numString);
                        $$.tnode->name = savedName;
                        $$.tnode->etype = $1.type;
                        $$.tnode->isArray = 1;

                        $$.tnode->pos = savedLineNo;

                        // insert
                        if(lookup(ht, savedName) != NULL)
                        {
                            printf("var_decl 2: %s is previously declared\n", savedName);
                        }
                        else
                        {
                            insert(ht, savedName, Array, $$.tnode->val, savedLineNo);
                        }
                    }
                ;

type_spec       : INT 
                    { $$.type = Integer; }
                | VOID
                    { $$.type = Void; }
                ;

fun_decl        : type_spec ID { $$.str = copyString(idString);
                                savedLineNo = lineno; } 
                    LPAREN params RPAREN compound_stmt
                    {
                        printf("New Scope - Function\n");
                        $$.tnode = newDeclNode(FunK);
                        $$.tnode->name = $3.str;
                        $$.tnode->etype = $1.type;
                        $$.tnode->pos = savedLineNo;
                        $$.tnode->child[0] = $5.tnode;
                        $$.tnode->child[1] = $7.tnode;

                        //insert
                        if(lookup(ht, $3.str) != NULL)
                        {
                            printf("fun_decl: %s is previously declared\n", $3.str);
                        }
                        else
                        {
                            printf("yas %d\n", savedLineNo);
                            insert(ht, $3.str, $1.type, 0, savedLineNo);
                        }

                        printf("Leaving %s scope...\n", $3.str);
                        printTable(ht);
                        typeCheck(ht);
                        
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

                    }
                | param
                    { $$.tnode = $1.tnode; }
                | error { fprintf(stderr, "Error in declaration (parameter list) statement\n");}
                ;

param           : type_spec ID 
                    {
                        $$.tnode = newDeclNode(ParamK);
                        $$.tnode->pos = lineno;
                        $$.tnode->name = copyString(idString);
                        $$.tnode->etype = $1.type;

                        // insert
                        if(lookup(ht, idString) != NULL)
                        {
                            printf("param 1: %s is previously declared\n", idString);
                        }
                        else
                        {
                            insert(ht, idString, $1.type, 0, savedLineNo);
                        }
                        
                    }
                | type_spec ID {    savedName = copyString(idString);
                                    savedLineNo = lineno; }
                    LBRAC RBRAC
                    {
                        $$.tnode = newDeclNode(ParamK);
                        $$.tnode->pos = savedLineNo;
                        $$.tnode->name = savedName;
                        $$.tnode->etype = $1.type;

                        // insert
                        if(lookup(ht, savedName) != NULL)
                        {
                            printf("param 2: %s is previously declared\n", savedName);
                        }
                        else
                        {
                            insert(ht, savedName, Array, 0, savedLineNo);
                        }

                    }
                ;

compound_stmt   : LCURL local_decl stmt_list RCURL
                    {
                        $$.tnode = newStmtNode(CmpdK);
                        $$.tnode->child[0] = $2.tnode;
                        $$.tnode->child[1] = $3.tnode;
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
                | epsilon { $$.tnode = NULL; printf("New Scope - Local Decl\n"); }
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
                    }
                | IF LPAREN expr RPAREN stmt ELSE stmt
                    {
                        $$.tnode = newStmtNode(IfK);
                        $$.tnode->child[0] = $3.tnode;
                        $$.tnode->child[1] = $5.tnode;
                        $$.tnode->child[2] = $7.tnode;
                    }
                | IF LPAREN error RPAREN { yyerrok; fprintf(stderr, "Error in selection (if) statement\n"); }
                ;

iter_stmt       : WHILE LPAREN expr RPAREN stmt
                    {
                        $$.tnode = newStmtNode(WhileK);
                        $$.tnode->child[0] = $3.tnode;
                        $$.tnode->child[1] = $5.tnode;
                    }
                | WHILE LPAREN error RPAREN { yyerrok; fprintf(stderr, "Error in iteration (while) statement\n"); }
                ;

return_stmt     : RETURN SEMI
                    {
                        $$.tnode = newStmtNode(ReturnK);
                        $$.tnode->child[0] = NULL;
                    }
                | RETURN expr SEMI
                    {
                        $$.tnode = newStmtNode(ReturnK);
                        $$.tnode->child[0] = $2.tnode;
                    }
                | RETURN error SEMI { yyerrok; fprintf(stderr, "Error in return statement\n"); }

                ;

expr            : var EQ expr
                    {
                        $$.tnode = newStmtNode(AssignK);
                        $$.tnode->child[0] = $1.tnode;
                        $$.tnode->op = EQ;
                        $$.tnode->child[1] = $3.tnode;
                    }
                | simple_expr
                    { $$.tnode = $1.tnode; }
                ;

var             : ID
                    { 
                        /* check if undeclared */
                        printf("Var: %s\n", idString);
                        if(lookup(ht, idString) == NULL)
                        {
                            printf("var 1 line: %d: error: '%s' is undeclared\n", lineno, idString);
                            insert(ht, idString, Undeclared, 0, 0);
                        } 

                        $$.tnode = newExpNode(IdK);
                        $$.tnode->name = copyString(idString);
                    }
                | ID {  savedName = copyString(idString);
                        savedLineNo = lineno; }
                    LBRAC expr RBRAC
                    {
                        printf("Line: %s[%s]\n", savedName, $4.str);
                        $$.tnode = newExpNode(IdK);
                        $$.tnode->name = savedName;
                        $$.tnode->pos = savedLineNo;
                        $$.tnode->child[0] = $4.tnode;

                        // insert
                        if(lookup(ht, savedName) == NULL)
                        {
                            printf("var 2 line: %d: error: '%s' is undeclared\n", lineno, idString);
                            insert(ht, savedName, Undeclared, 0, 0);
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
                        printf("Constant = %s\n", numString);
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
                    }
                | expr
                    { $$.tnode = $1.tnode; }
                ;

epsilon         : ;                         
%%

