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
                    {}
                | VOID
                    {}
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
                | IF LPAREN expr RPAREN stmt ELSE stmt /*conflict - dangling else*/
                    {}
                ;

iter_stmt       : WHILE LPAREN expr RPAREN stmt
                   // {printf("%s\n", yytext);}
                ;

return_stmt     : RETURN SEMI
                   // {printf("17. %s %s\n", $1, $2);}
                | RETURN expr SEMI
                   // {printf("%s\n", yytext);}
                ;

expr            : var EQ expr
                  // {printf("%s\n", yytext);}
                | simple_expr
                   {printf("%s\n", yytext);}
                ;

var             : ID
                   // {printf("19. %s\n", $1);}
                | ID LBRAC expr RBRAC
                  //  {printf("%s\n", yytext);}
                ;

simple_expr     : additive_expr relop additive_expr
                   // {printf("%s\n", yytext);}
                | additive_expr
                    {printf("%s\n", yytext);}
                ;

relop           : LTEQ
                   //{printf("21. %s\n", $1);}
                | LT
                   // {printf("21. %s\n", $1);}
                | GT
                    //{printf("21. %s\n", $1);}
                | GTEQ
                  // {printf("21. %s\n", $1);}
                | DOUBEQ
                   // {printf("21. %s\n", $1);}
                | NEQ
                   // {printf("21. %s\n", $1);}
                ;

additive_expr   : additive_expr addop term
                   // {printf("%s\n", yytext);}
                | term
                    {printf("%s\n", yytext);}
                ;

addop           : PLUS
                   // {printf("23. %s\n", $1);}
                | MINUS
                   // {printf("23. %s\n", $1);}
                ;

term            : term mulop factor
                    //{printf("%s\n", yytext);}
                | factor
                    {printf("%s\n", yytext);}
                ;

mulop           : MULT
                    //{printf("25. %s\n", $1);}
                | DIV
                   // {printf("25. %s\n", $1);}
                ;

factor          : LPAREN expr RPAREN
                  // {printf("%s\n", yytext);}
                | var
                    //{printf("%s\n", yytext);}
                | call
                    //{printf("%s\n", yytext);}
                | NUM
                    {printf("26. %s\n", $1);}
                ;

call            : ID LPAREN args RPAREN
                   // {printf("%s\n", yytext);}
                ;

args            : arg_list
                    //{printf("%s\n", yytext);}
                | epsilon
                ;

arg_list        : arg_list COMMA expr
                   // {printf("%s\n", yytext);}
                | expr
                    //{printf("%s\n", yytext);}
                ;

epsilon         : ;                         
%%

