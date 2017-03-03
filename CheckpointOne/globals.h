/************************************************
* File: globals.h
* Global types and variables for CMinus
* Authors: Jasmine Kandloosi and Vanessa White
    Originally provided by Fei Song
* February 2017
*************************************************/

#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#define MAXCHILDREN 3 /* max amount of children the root can have */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


extern int lineno; /* source line number for listing */

/* The type of statements for the CMinus language */
enum NodeType { StmtType, ExpType, DeclType };
enum StmtKind { IfK, ReturnK, WhileK, CmpdK };
enum ExpKind  { OpK, ConstK, IdK, CallK, SubsK };
enum DeclKind { VarK, FunK, ParamK };

struct TreeNode {

	struct TreeNode * child[MAXCHILDREN];
	struct TreeNode * sibling;

	int pos;

	enum NodeType nodeType;

	union {
		enum StmtKind stmt;
		enum ExpKind exp;
	}kind;

	union {
		int op;
		int val;
		char * name;
	}attr;

};


#endif