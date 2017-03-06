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
    char idString[MAXTOKENLEN+1];
    char numString[MAXTOKENLEN+1];

%}

%x COMMENT

digit                   [0-9]
letter                  [a-zA-Z]
number                  {digit}{digit}*
identifier              {letter}{letter}*
newline                 \n
whitespace              [ \t]+


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
"/*"                    { skipComments(); }
{newline}               {lineno++;}
{identifier}            { strcpy(idString, yytext); return ID;}
{number}                { strcpy(numString, yytext); return NUM;}
{whitespace}            { /* skip whitespace */ }
.                       { panicMode(); }

%%

int getToken(void)
{ 
    int currentToken;

    currentToken = yylex();
    strncpy(tokenString, yytext, MAXTOKENLEN);

    return currentToken;
}

void skipComments()
{
    char c;
    int done = 0;
    do
    {
        c = input();

        switch(c)
        {
            case EOF:
                break;
            case '\n':
                lineno++;
            case '*':
                if((c = input()) == '/')
                {
                    done = 1;
                }
                else
                {
                    unput(c);
                }
                break;
            default:
                break;
        }
    }while(done != 1);

}

void panicMode()
{
    char c;
    int done = 0;
    
    fprintf(stderr, "Error at line %d from Token: %s. \n", lineno, yytext);

    do
    {
        c = input();

        switch(c)
        {
            case EOF:
                done = 1;
                break;
            case '\n':
                lineno++;
            case ';':
                done = 1;
                break;
            default:
                break;
        }
    }while(done != 1);

    printf("Restarting tokenizing at line %d\n", lineno);
}
