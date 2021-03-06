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
    #include "symlist.h"

    char tokenString[MAXTOKENLEN+1];
    char idString[MAXTOKENLEN+1];
    char numString[MAXTOKENLEN+1];
    char currLine[256];
    struct symlist * globalList;
    struct symlist * stack;
    struct symhash * symtable[MAXARRLEN];
    struct symhash * stackTable[MAXARRLEN];

%}

%x COMMENT

digit                   [0-9]
letter                  [a-zA-Z]
number                  -?{digit}{digit}*
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
{newline}               {memset(currLine, 0,256); lineno++; }
{identifier}            { strcpy(idString, yytext); return ID;}
{number}                { strcpy(numString, yytext); return NUM;}
{whitespace}            { strcat(currLine, yytext); /* skip whitespace */ }
.                       { printf("%s faals\n", yytext); panicMode(); return ERROR; }

%%

int getToken(void)
{ 
    static int firstTime = TRUE;
    int currentToken;
  
    if (firstTime)
    { 
        firstTime = FALSE;
        lineno++;
        yyin = source;
        yyout = listing;
    }

    currentToken = yylex();
    strcat(currLine, yytext);
   // printf("YYTEXT: %s\n", yytext);
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
                memset(currLine, 0, 256);
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
    fprintf(stderr, "Error at line %d from Token: %s. \n", lineno, yytext);
    char c;
    int done = 0;
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
