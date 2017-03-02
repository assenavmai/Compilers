/************************************************
* File: util.c 
* Utility functions implementation for CMinus
* Authors: Jasmine Kandloosi and Vanessa White
    Originally provided by Fei Song
* February 2017
*************************************************/
#include "globals.h"
#include "util.h"
#include "y.tab.h"

/* prints a token and its lexeme to the listing file
 */
void printToken(int token, const char* tokenString)
{ 
	FILE * listing = stdout;
	switch (token)
  	{ 
	  	case IF:
	    case ELSE:
	    case INT:
	    case VOID:
	    case RETURN:
	    case WHILE:
	      fprintf(listing, "reserved word: %s\n",tokenString);
	      break;
	    case PLUS: 		fprintf(listing,"+\n"); break;
	    case MINUS: 	fprintf(listing,"-\n"); break;
	    case MULT: 		fprintf(listing,"*\n"); break;
	    case DIV: 		fprintf(listing,"/\n"); break;
	    case LT: 		fprintf(listing,"<\n"); break;
	    case LTEQ: 		fprintf(listing,"<=\n"); break;
	    case GT: 		fprintf(listing,">\n"); break;
	    case GTEQ: 		fprintf(listing,">=\n"); break;
	    case DOUBEQ: 	fprintf(listing,"==\n"); break;
	    case NEQ: 		fprintf(listing,"!=\n"); break;
	    case EQ: 		fprintf(listing,"=\n"); break;
	    case SEMI: 		fprintf(listing,";\n"); break;
	    case COMMA: 	fprintf(listing,",\n"); break;
	    case LPAREN: 	fprintf(listing,"(\n"); break;
	    case RPAREN: 	fprintf(listing,")\n"); break;
	    case LBRAC: 	fprintf(listing,"[\n"); break;
	    case RBRAC: 	fprintf(listing,"]\n"); break;
	    case LCURL: 	fprintf(listing,"{\n"); break;
	    case RCURL: 	fprintf(listing,"}\n"); break;

	    case NUM:
	      fprintf(listing,
	          "NUM, val= %s\n",tokenString);
	      break;
	    case ID:
	      fprintf(listing,
	          "ID, name= %s\n",tokenString);
	      break;
	    case ERROR:
	      fprintf(listing,
	          "ERROR: %s\n",tokenString);
	      break;
	    default: /* should never happen */
	      fprintf(listing,"Unknown token: %d\n",token);
  }
}