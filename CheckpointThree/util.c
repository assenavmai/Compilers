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

struct TreeNode * newErrorNode() {

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
		node->nodeKind = Err;
		node->pos = lineno;
	}

	return node;
}

char * copyString(char  * str) {

	char * newString;

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

void printTypeSpec(enum ExpType type)
{
	switch(type)
	{
		case Void:
			fprintf(listing, "void ");
			break;
		case Integer:
			fprintf(listing, "int ");
			break;
	}
}

void printToken(int token, const char* tokenString)
{ 
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

// used by printTree to store current number of spaces to indent
static indentno = 0;

/* macros to increase/decrease indentation */
#define INDENT indentno +=4
#define UNINDENT indentno -=4

/* printSpaces indents by printing spaces */
static void printSpaces(void)
{ 

	int i;
  	for (i=0;i<indentno;i++)
    	fprintf(listing," ");
}

void printTree(struct TreeNode * tree)
{ 
	int i;
	INDENT;
	
	while (tree != NULL) 
	{
		printSpaces();

		if (tree->nodeKind == StmtKind)
		{ 
			switch (tree->kind.stmt) 
			{
			    case IfK:
			      fprintf(listing,"If\n");
			      break;
			    case ReturnK:
			      fprintf(listing,"Return\n");
			      break;
			    case WhileK:
			      fprintf(listing,"While");
			      break;
			    case CmpdK:
			      fprintf(listing,"Compound:\n");
			      break;
			    case AssignK:
			      fprintf(listing,"Assign operation: ");
			      printToken(tree->op, "\0");
			      break;
			    case CallK:
			    	fprintf(listing, "Call: %s()\n", tree->name);
			    	break;
			    default:
			      fprintf(listing,"Unknown StmtNode kind %s %d\n", tree->name, tree->op);
			      break;
			  }
		}
		else if (tree->nodeKind == ExpKind)
		{ 
			switch (tree->kind.exp) 
			{
			    case OpK:
			      fprintf(listing,"Op: ");
			      printToken(tree->op,"\0");
			      break;
			    case ConstK:
			      fprintf(listing,"Const: %d\n",tree->val);
			      break;
			    case IdK:
			      fprintf(listing,"Id: %s\n",tree->name);
			      break;
			    default:
			      fprintf(listing,"Unknown ExpNode kind\n");
			      break;
		  	}
		}
		else if(tree->nodeKind == DeclKind)
		{
			switch(tree->kind.dec)
			{
				case VarK:
					if(tree->etype == Array)
					{
						fprintf(listing, "int %s[%d]\n", tree->name, tree->val);
					}
					else
					{
						fprintf(listing, "Var: ");
						printTypeSpec(tree->etype);
						fprintf(listing, "%s\n", tree->name);
					}
					break;
				case FunK:
					fprintf(listing, "Function: ");
					printTypeSpec(tree->etype);
					fprintf(listing, "%s()\n",tree->name);
					break;
				case ParamK:
					fprintf(listing, "Params: ");
					printTypeSpec(tree->etype);
					fprintf(listing, "%s\n", tree->name);
					break;
				default:
			      fprintf(listing,"Unknown DeclNode kind\n");
			      break;
			}
		}
		else 
		{
			fprintf(listing,"Unknown node kind\n");
		}

		for (i=0;i<MAXCHILDREN;i++)
		{
		    printTree(tree->child[i]);
		}

		tree = tree->sibling;
	}
	UNINDENT;
}

void symTable(struct symhash * table) {

	struct symhash * t;

	if(!table)
	{
		printf("Table is empty\n");
		return;
	}

	for(t = table; t != NULL; t = (struct symhash *)(t->hh.next))
	{
		fprintf(listing, "%3s\t\t", t->key);
		printTypeSpec(t->type);
		fprintf(listing, "\t\t%5d\t\t%5d\t\t%5d\n", t->lineno, t->token, t->memLocation);
	}
}

void printSymbolTable(struct symlist * head) {

	struct symlist * temp;

	fprintf(listing, "Name\t\tType\t\tLine\t\tValue\t\tLocation\n");

	LL_FOREACH(head, temp)
	{
		symTable(temp->table);
	}
}

int findMemoryLocation(struct symlist * head, char * key) {

	struct symlist * l, *temp;
	struct symhash * t;
	int flag = 0;

	LL_FOREACH(head, l)
	{
		HASH_FIND_STR(l->table, key, t);
		
		if(t)
		{
			//printf("%s is declared\n", key);
			return t->memLocation;
		}
	}

	return -5000;
}


void addIOFunctions() {

	struct TreeNode * funcDecl, *cmpdStmt, * params;

	// input function
	funcDecl = newDeclNode(FunK);
	funcDecl->name = "input";
	funcDecl->etype = Integer;
	funcDecl->pos = 0;
	funcDecl->params = 0;
	funcDecl->scope = Predefined;
	funcDecl->memoryLocation = 0;
	funcDecl->child[0] = NULL; // no parameters

	cmpdStmt = newStmtNode(CmpdK);
	cmpdStmt->child[0] = NULL; // no local variables
	cmpdStmt->child[1] = NULL; // no statements

	funcDecl->child[1] = cmpdStmt;

	globalList->table = addToTable(globalList->table, "input", Integer, 0, -1, 0);

	// output function
	funcDecl = newDeclNode(FunK);
	funcDecl->name = "output";
	funcDecl->etype = Void;
	funcDecl->pos = 0;
	funcDecl->params  = 1;
	funcDecl->scope = Predefined;
	funcDecl->memoryLocation = 0;

	params = newDeclNode(ParamK);
	params->name = "arg";

	funcDecl->child[0] = NULL; // no parameters

	cmpdStmt = newStmtNode(CmpdK);
	cmpdStmt->child[0] = NULL;
	cmpdStmt->child[1] = NULL;

	funcDecl->child[1] = cmpdStmt;
}
