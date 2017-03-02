/************************************************
* File: cm.l 
* Lex specification for CMinus
* Authors: Jasmine Kandloosi and Vanessa White
* February 2017
*************************************************/

%{

    #include "globals.h"
    #include "y.tab.h"
    #include "scan.h"
    #include "util.h"

    void yyerror(char *);

    char tokenString[MAXTOKENLEN+1];
%}

digit                   [0-9]
letter                  [a-zA-z]
number                  {digit}{digit}*
identifier              {letter}{letter}*
whitespace              [ \t\n]+


%%

"if"                    {return IF;}
"else"                  {return ELSE;}
"int"                   {return INT;}
"return"                {return RETURN;}
"void"                  {return VOID;}
"while"                 {return WHILE;}
"+"                     {return PLUS;}
"-"                     {return MINUS;}
"*"                     {return MULT;}
"/"                     {return DIV;}
"<"                     {return LT;}
">"                     {return GT;}
"<="                    {return LTEQ;}
">="                    {return GTEQ;}
"=="                    {return DOUBEQ;}
"!="                    {return NEQ;}
"="                     {return EQ;}
";"                     {return SEMI;}
","                     {return COMMA;}
"("                     {return LPAREN;}
")"                     {return RPAREN;}
"["                     {return LBRAC;}
"]"                     {return RBRAC;}
"{"                     {return LCURL;}
"}"                     {return RCURL;}
"/*"                    {printf("OPENCOMMENT\n");}
"*/"                    {printf("CLOSECOMMENT\n");}
{identifier}            {return ID;}
{number}                {return NUM;}
{whitespace}            { /* skip whitespace */ }
.                       {printf("ERROR\n");}

%%

int getToken(void)
{ 
    int currentToken;

    currentToken = yylex();
    strncpy(tokenString, yytext, MAXTOKENLEN);

    printToken(currentToken,tokenString);

    return currentToken;
}
