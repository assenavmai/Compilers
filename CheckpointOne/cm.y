/************************************************
* File: cm.l 
* Yacc specification for CMinus
* Authors: Jasmine Kandloosi and Vanessa White
* February 2017
*************************************************/

%{
extern char * yytext;
    #define YYPARSER
    #define YYSTYPE char *
    #include "globals.h"

    void yyerror(const char *str)
    {
            fprintf(stderr,"error: %s\n",str);
    }

    int yywrap()
    {
            return 1;
    } 

    static int yylex(void)
    { return getToken(); }
  
    main()
    {

        yyparse();

        return 0;
    }


%}



%token ELSE IF INT RETURN VOID WHILE
%token ID NUM
%token PLUS MINUS MULT DIV LT GT LTEQ GTEQ DOUBEQ NEQ EQ SEMI COMMA LPAREN RPAREN LBRAC RBRAC LCURL RCURL 
%token ERROR

%nonassoc LT GT
%left PLUS MINUS
%left MULT DIV


%% /* Grammar for C- */

/***
    Issues:
        int x[10]; => int ID = x[  NEED TO FIX
*/
program         : decl_list
                ;

decl_list       : decl_list decl
                | decl
                ;

decl            : var_decl
                | fun_decl 
                ;

var_decl        : type_spec ID SEMI
                    { }
                | type_spec ID LBRAC NUM RBRAC SEMI
                    { }
                ;

type_spec       : INT 
                    { $$ = $1; }
                | VOID
                    { $$ = $1; }
                ;

fun_decl        : type_spec ID LPAREN params RPAREN compound_stmt
                    {}
                ;

params          : param_list 
                | VOID
                    {}
                ;

param_list      : param_list COMMA param
                    {}
                | param
                    {}
                ;

param           : type_spec ID 
                    {}
                | type_spec ID LBRAC RBRAC
                    {}
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

