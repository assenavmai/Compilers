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

    #define YYSTYPE struct TreeNode *

    extern FILE * yyin;
    static struct TreeNode * syntaxTree; /* save the syntax tree to be returned */
    static char * savedName; /* for use in assignments */
    static int savedLineNo;  /* ditto */

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
                    { syntaxTree = $1; } //root of tree
                ;

decl_list       : decl_list decl
                    /* sibling stuff */
                | decl
                    { $$ = $1; }
                ;

decl            : var_decl
                    { $$ = $1; }
                | fun_decl 
                    { $$ = $1; }
                ;

var_decl        : type_spec ID SEMI /*check type in tree */
                    { 
                        printf("Var ID: %s\n", idString);
                        savedName = allocateString(idString);
                        savedLineNo = lineno;
                        $$ = newDeclNode(VarK);
                        $$->attr.name = savedName;
                        $$->pos = savedLineNo;
                        $$->child[0] = $1;
                    }
                | type_spec ID LBRAC NUM RBRAC SEMI
                    { 
                        printf("Var(Array) ID: %s\n", idString);
                        savedName = allocateString(idString);
                        savedLineNo = lineno;
                        $$ = newDeclNode(VarK);
                        $$->attr.name = savedName;
                        $$->pos = savedLineNo;
                        $$->child[0] = $1;
                    }
                ;

type_spec       : INT 
                    { 
                        $$ = newTypeSpecNode(Integer);
                        $$->type = Integer;
                        /* $$->type = Integer; segfaults */
                    }
                | VOID
                    { 
                        $$ = newTypeSpecNode(Void);
                        $$->type = Void;
                        /* $$->type = Void; segfaults */
                    }
                ;

fun_decl        : type_spec ID { savedName = allocateString(idString);
                                 savedLineNo = lineno; } 
                    LPAREN params RPAREN compound_stmt
                    {

                        $$ = newDeclNode(FunK);
                        $$->child[0] = $1;
                        $$->child[1] = $4;
                        $$->child[2] = $6;
                        $$->attr.name = savedName;
                        $$->pos = savedLineNo;
                        printf("Function name: %s\n", $$->attr.name);
                    }   
                ;

params          : param_list
                    { $$ = $1; } 
                | VOID
                    {
                        $$ = newDeclNode(ParamK);
                        $$->type = Void;
                    }
                ;

param_list      : param_list COMMA param
                    {
                        $$ = newDeclNode(ParamK);
                        $$->child[0] = $1;
                        $$->child[1] = $3;
                    }
                | param
                    { $$ = $1; }
                ;

param           : type_spec ID 
                    {
                        savedName = allocateString(idString);
                        savedLineNo = lineno;
                        $$ = newDeclNode(ParamK);
                        $$->attr.name = savedName;
                        $$->pos = lineno;
                        printf("Function Param: %s\n",idString);

                        $$->child[0];

                    }
                | type_spec ID LBRAC RBRAC
                    {

                    }
                ;

compound_stmt   : LCURL local_decl stmt_list RCURL
                    {}
                ;

local_decl      : local_decl var_decl
                    {}
                | epsilon
                ;

stmt_list       : stmt_list stmt
                    {}
                | epsilon
                ;

stmt            : expr_stmt
                    {}
                | compound_stmt
                    {}
                | select_stmt
                    {}
                | iter_stmt
                    {}
                | return_stmt
                    {}
                ;

expr_stmt       : expr SEMI
                    {}
                | SEMI
                    {}
                ;

select_stmt     : IF LPAREN expr RPAREN stmt
                    {}
                | IF LPAREN expr RPAREN stmt ELSE stmt
                    {}
                ;

iter_stmt       : WHILE LPAREN expr RPAREN stmt
                    {}
                ;

return_stmt     : RETURN SEMI
                    {}
                | RETURN expr SEMI
                    {}
                ;

expr            : var EQ expr
                    {}
                | simple_expr
                    {}
                ;

var             : ID
                    {}
                | ID LBRAC expr RBRAC
                    {}
                ;

simple_expr     : additive_expr relop additive_expr
                    {}
                | additive_expr
                    {}
                ;

relop           : LTEQ
                    {}
                | LT
                    {}
                | GT
                    {}
                | GTEQ
                    {}
                | DOUBEQ
                    {}
                | NEQ
                    {}
                ;

additive_expr   : additive_expr addop term
                    {}
                | term
                    {}
                ;

addop           : PLUS
                    {}
                | MINUS
                    {}
                ;

term            : term mulop factor
                    {}
                | factor
                    {}
                ;

mulop           : MULT
                    {}
                | DIV
                   {}
                ;

factor          : LPAREN expr RPAREN
                    {}
                | var
                    {}
                | call
                    {}
                | NUM
                    {}
                ;

call            : ID LPAREN args RPAREN
                    {}
                ;

args            : arg_list
                    {}
                | epsilon
                ;

arg_list        : arg_list COMMA expr
                    {}
                | expr
                    {}
                ;

epsilon         : ;                         
%%

