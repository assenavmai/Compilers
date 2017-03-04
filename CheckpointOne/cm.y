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
            fprintf(stderr,"error: %s %d\n",str, lineno);
    }

    int yywrap()
    {
            return 1;
    } 

   static int yylex(void)
    { return getToken(); }
  
    main()
    {
        yyin = fopen("test", "r");
        yyparse();

        return 0;
    }

    struct TreeNode * parse(void) { 
    yyin = fopen("test", "r");
        yyparse();
        return syntaxTree;
    }


%}

%token ELSE IF INT RETURN VOID WHILE
%token ID NUM
%token PLUS MINUS MULT DIV LT GT LTEQ GTEQ DOUBEQ NEQ EQ SEMI COMMA LPAREN RPAREN LBRAC RBRAC LCURL RCURL 
%token ERROR

%nonassoc LT GT LTEQ GTEQ
%left PLUS MINUS
%left MULT DIV



%% /* Grammar for C- */


program         : decl_list
                    { syntaxTree = $1.tnode; } //root of tree
                ;

decl_list       : decl_list decl
                    /* sibling stuff */
                | decl
                    {  $$.tnode = $1.tnode; }
                ;

decl            : var_decl
                    { $$.tnode = $1.tnode; }
                | fun_decl 
                    { $$.tnode = $1.tnode; }
                ;

var_decl        : type_spec ID SEMI /*check type in tree */
                    { 
                        $$.tnode = newDeclNode(VarK);
                        $$.tnode->name = copyString(idString);
                        $$.tnode->type = $1.str;
                        $$.tnode->etype = $1.type;
                        $$.tnode->pos = lineno;
                    }
                | type_spec ID LBRAC NUM RBRAC SEMI
                    { 
                        $$.tnode = newDeclNode(VarK);
                        $$.tnode->type = copyString("Array");
                        $$.tnode->etype = Array;
                        $$.tnode->name = copyString(idString);
                        $$.tnode->val = atoi(numString);
                        $$.tnode->pos = lineno;
                    }
                ;

type_spec       : INT 
                    { 
                        $$.str = copyString(tokenString);
                        $$.type = Integer;
                    }
                | VOID
                    { 
                        $$.str = copyString(tokenString);
                        $$.type = Void;
                    }
                ;

fun_decl        : type_spec ID LPAREN params RPAREN compound_stmt
                    {
                        $$.tnode = newDeclNode(FunK);
                        $$.tnode->name = copyString(idString);
                        $$.tnode->etype = $1.type;
                        $$.tnode->type = $1.str;
                        $$.tnode->pos = lineno;
                        $$.tnode->child[0] = $4.tnode;
                        $$.tnode->child[1] = $6.tnode;
                    }   
                ;

params          : param_list
                    {
                        $$.tnode = $1.tnode;
                    } 
                | VOID
                    {

                    }
                ;

param_list      : param_list COMMA param
                    {
                        /* sibling stuff */
                    }
                | param
                    { 
                        $$.tnode = $1.tnode;
                    }
                ;

param           : type_spec ID 
                    {
                        $$.tnode = newDeclNode(ParamK);
                        $$.tnode->pos = lineno;
                        $$.tnode->name = copyString(idString);
                        $$.tnode->type = $1.str;
                        $$.tnode->etype = $1.type;
                    }
                | type_spec ID LBRAC RBRAC
                    {
                        $$.tnode = newDeclNode(ParamK);
                        $$.tnode->pos = lineno;
                        $$.tnode->name = copyString(idString);
                        $$.tnode->type = $1.str;
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
                    }
                | epsilon { $$.tnode = NULL; }
                ;

stmt_list       : stmt_list stmt
                    {
                        /* sibling stuff */
                    }
                | epsilon { $$.tnode = NULL; }
                ;

stmt            : expr_stmt
                    {

                    }
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

select_stmt     : IF LPAREN expr RPAREN stmt
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
                        $$.tnode->op = EQ;
                        $$.tnode->child[1] = $3.tnode;
                    }
                | simple_expr
                    { $$.tnode = $1.tnode; }
                ;

var             : ID
                    { 
                        /* check if undeclared */
                        $$.tnode = newExpNode(IdK);
                        $$.tnode->name = copyString(idString);
                    }
                | ID LBRAC expr RBRAC
                    {
                        $$.tnode = newExpNode(IdK);
                        $$.tnode->name = copyString(idString);
                        $$.tnode->pos = lineno;
                        $$.tnode->child[0] = $3.tnode;
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

call            : ID LPAREN args RPAREN
                    {
                        $$.tnode = newStmtNode(CallK);
                        $$.tnode->name = copyString(idString);
                        $$.tnode->child[0] = $3.tnode;
                        $$.tnode->pos = lineno;
                    }
                ;

args            : arg_list
                    { $$.tnode = $1.tnode; }
                | epsilon { $$.tnode = NULL; }
                ;

arg_list        : arg_list COMMA expr
                    {
                        /* siblng stuff */
                    }
                | expr
                    { $$.tnode = $1.tnode; }
                ;

epsilon         : ;                         
%%

