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


    void yyerror(const char *str)
    {
            fprintf(stderr,"error: %s %d %s\n",str, lineno, tokenString);
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
                ;

var_decl        : type_spec ID {    savedName = copyString(idString); 
                                    savedLineNo = lineno; } 
                    SEMI 
                    { 
                        $$.tnode = newDeclNode(VarK);
                        $$.tnode->attr.name = savedName;
                        $$.tnode->etype = $1.type;
                        $$.tnode->pos = savedLineNo;
                    }
                | type_spec ID {    savedName = copyString(idString); 
                                    savedLineNo = lineno; } 
                    LBRAC NUM RBRAC SEMI
                    { 
                        $$.tnode = newDeclNode(VarK);
                        $$.tnode->attr.name = savedName;
                        $$.tnode->etype = Array;
                        $$.tnode->attr.val = atoi(numString);
                        $$.tnode->pos = savedLineNo;
                    }
                ;

type_spec       : INT 
                    { $$.type = Integer; }
                | VOID
                    { $$.type = Void; }
                ;

fun_decl        : type_spec ID { savedName = copyString(idString);
                                savedLineNo = lineno; } 
                    LPAREN params RPAREN compound_stmt
                    {
                        $$.tnode = newDeclNode(FunK);

                        $$.tnode->attr.name = savedName;
                        $$.tnode->etype = $1.type;
                        $$.tnode->pos = savedLineNo;
                        $$.tnode->child[0] = $5.tnode;
                        $$.tnode->child[1] = $7.tnode;
                    }   
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
                ;

param           : type_spec ID 
                    {
                        $$.tnode = newDeclNode(ParamK);
                        $$.tnode->pos = lineno;
                        $$.tnode->attr.name = copyString(idString);
                        $$.tnode->etype = $1.type;
                    }
                | type_spec ID {    savedName = copyString(idString);
                                    savedLineNo = lineno; }
                    LBRAC RBRAC
                    {
                        $$.tnode = newDeclNode(ParamK);
                        $$.tnode->pos = savedLineNo;
                        $$.tnode->attr.name = savedName;
                        $$.tnode->etype = Array;
                    }
                ;

compound_stmt   : LCURL local_decl stmt_list RCURL
                    {
                        $$.tnode = newStmtNode(CmpdK);
                        $$.tnode->child[0] = $2.tnode;
                        $$.tnode->child[1] = $3.tnode;
                    }
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
                    }
                | IF LPAREN expr RPAREN stmt ELSE stmt
                    {
                        $$.tnode = newStmtNode(IfK);
                        $$.tnode->child[0] = $3.tnode;
                        $$.tnode->child[1] = $5.tnode;
                        $$.tnode->child[2] = $7.tnode;
                    }
                ;

iter_stmt       : WHILE LPAREN expr RPAREN stmt
                    {
                        $$.tnode = newStmtNode(WhileK);
                        $$.tnode->child[0] = $3.tnode;
                        $$.tnode->child[1] = $5.tnode;
                    }
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
                ;

expr            : var EQ expr
                    {
                        $$.tnode = newStmtNode(AssignK);
                        $$.tnode->child[0] = $1.tnode;
                        $$.tnode->attr.op = EQ;
                        $$.tnode->child[1] = $3.tnode;
                    }
                | simple_expr
                    { $$.tnode = $1.tnode; }
                ;

var             : ID
                    { 
                        /* check if undeclared */
                        $$.tnode = newExpNode(IdK);
                        $$.tnode->attr.name = copyString(idString);
                    }
                | ID {  savedName = copyString(idString);
                        savedLineNo = lineno; }
                    LBRAC expr RBRAC
                    {
                        $$.tnode = newExpNode(IdK);
                        $$.tnode->attr.name = savedName;
                        $$.tnode->pos = savedLineNo;
                        $$.tnode->child[0] = $4.tnode;
                    }
                ;

simple_expr     : additive_expr relop additive_expr
                    {
                        $$.tnode = newExpNode(OpK);
                        $$.tnode->child[0] = $1.tnode;
                        $$.tnode->attr.op = $2.op;
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
                        $$.tnode->attr.op = $2.op;
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
                        $$.tnode->attr.op = $2.op;
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
                        $$.tnode->attr.val = atoi(numString);
                    }
                ;

call            : ID {  savedName = copyString(idString);
                        savedLineNo = lineno; }
                    LPAREN args RPAREN
                    {
                        $$.tnode = newStmtNode(CallK);
                        $$.tnode->attr.name = savedName;
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

