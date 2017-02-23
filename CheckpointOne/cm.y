/************************************************
* File: cm.l 
* Yacc specification for CMinus
* Authors: Jasmine Kandloosi and Vanessa White
* February 2017
*************************************************/

%{
    #define YYPARSER
    #include "globals.h"
%}

%token ELSE IF INT RETURN VOID WHILE
%token ID NUM
%token PLUS MINUS TIMES DIV LT GT LTEQ GTEQ DOUBEQ NEQ EQ SEMI COMMA LPAREN RPAREN LBRAC RBRAC LCURL RCURL 
%token ERROR

%nonassoc LT GT
%left PLUS MINUS
%left TIMES DIV

%% /* Grammar for C- */

program     : IF
                { printf("yah");}
            ;

%%

int main(int argc, char const *argv[])
{
    FILE * f = fopen(argv[1], "r");

    yyparse();
    
    return 0;
}