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


struct TreeNode * newDeclNode(enum DeclKind dec) {

	FILE * listing = stdout; 

	struct TreeNode * node = (struct TreeNode *)malloc(sizeof(struct TreeNode));

	int i;

	if(!node)
	{
		fprintf(listing, "error: Out of memory at line %d\n", lineno);
	}
	else
	{
		for(i = 0; i < MAXCHILDREN; i++)
		{
			node->child[i] = NULL;
		}


		node->sibling = NULL;
		node->nodeKind = DeclKind;
		node->kind.dec = dec;
		node->pos = lineno;
	}

	return node;
}


struct TreeNode * newExpNode(enum ExpKind exp) {

	FILE * listing = stdout; 

	struct TreeNode * node = (struct TreeNode *)malloc(sizeof(struct TreeNode));

	int i;

	if(!node)
	{
		fprintf(listing, "error: Out of memory at line %d\n", lineno);
	}
	else
	{
		for(i = 0; i < MAXCHILDREN; i++)
		{
			node->child[i] = NULL;
		}

		node->sibling = NULL;
		node->nodeKind = ExpKind;
		node->kind.exp = exp;
		node->pos = lineno;
	}

	return node;
}

struct TreeNode * newStmtNode(enum StmtKind stmt) {

	FILE * listing = stdout; 

	struct TreeNode * node = (struct TreeNode *)malloc(sizeof(struct TreeNode));

	int i;

	if(!node)
	{
		fprintf(listing, "error: Out of memory at line %d\n", lineno);
	}
	else
	{
		for(i = 0; i < MAXCHILDREN; i++)
		{
			node->child[i] = NULL;
		}


		node->sibling = NULL;
		node->nodeKind = StmtKind;
		node->kind.stmt = stmt;
		node->pos = lineno;
	}

	return node;
}

char * copyString(char  * str) {

	char * newString;
	FILE * listing = stdout;

	if(!str)
	{
		return NULL;
	}

	newString = malloc(sizeof(str) * strlen(str) + 1);

	if(!newString)
	{
		fprintf(listing, "error: Out of memory at line %d\n", lineno);
	}
	else
	{
		strcpy(newString, str);
	}

	return newString;
}

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
