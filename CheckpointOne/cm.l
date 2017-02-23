/************************************************
* File: cm.l 
* Lex specification for CMinus
* Authors: Jasmine Kandloosi and Vanessa White
* February 2017
*************************************************/

%{
	#include "globals.h"

	#include "globals.h"
%}

digit 					[0-9]
letter					[a-zA-z]
number					{digit}{digit}*
identifier				{letter}{letter}*
whitespace				[ \t\n]+


%%

"if"					{printf("IF\n");}
"else"					{printf("ELSE\n");}
"int"					{printf("INT\n");}
"return"				{printf("RETURN\n");}
"void"					{printf("VOID\n");}
"while"					{printf("WHILE\n");}
"+"						{printf("PLUS\n");}
"-"						{printf("MINUS\n");}
"*"						{printf("TIMES\n");}
"/"						{printf("DIV\n");}
"<"						{printf("LT\n");}
">"						{printf("GT\n");}
"<="					{printf("LTEQ\n");}
">="					{printf("GTEQ\n");}
"=="					{printf("DOUBEQ\n");}
"!="					{printf("NEQ\n");}
"="						{printf("EQ\n");}
";"						{printf("SEMI\n");}
","						{printf("COMMA\n");}
"("						{printf("LPAREN\n");}
")"						{printf("RPAREN\n");}
"["						{printf("LBRACK\n");}
"]"						{printf("RBRACK\n");}
"{"						{printf("LCURL\n");}
"}"						{printf("RCURL\n");}
"/*"					{printf("OPENCOMMENT\n");}
"*/"					{printf("CLOSECOMMENT\n");}
{identifier}			{printf("ID\n");}
{number}				{printf("NUM\n");}
{whitespace}			{ /* skip whitespace */ }


%%

main(int argc, char const *argv[]) {

    FILE * f;
    char * buffer[1024];

    f = fopen(argv[1], "r");

        
    if(argc == 2 && (f = fopen(argv[1], "r")))
    {
        yyin = f;
    }

    yylex();

    return 0;
}