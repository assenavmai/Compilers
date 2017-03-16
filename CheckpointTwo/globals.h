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


extern FILE* source; /* source code text file */
extern FILE* listing; /* listing output text file */
extern FILE* code; /* code text file for TM simulator */
extern int lineno; /* source line number for listing */

/* The type of statements for the CMinus language */
enum NodeKind { StmtKind, ExpKind, DeclKind, SpecKind };
enum StmtKind { IfK, ReturnK, WhileK, CmpdK, AssignK, CallK };
enum ExpKind  { OpK, ConstK, IdK};
enum DeclKind { VarK, FunK, ParamK };

enum ExpType {Void,Integer, Array};  /* Type specifiers */

struct TreeNode {

	struct TreeNode * child[MAXCHILDREN];
	struct TreeNode * sibling;

	int pos;
	int op;
	int val;
	char * name;
	enum NodeKind nodeKind;
	enum ExpType etype;
	union {
		enum StmtKind stmt;
		enum ExpKind exp;
		enum DeclKind dec;
	}kind;

	//causes segfaults
	/*union {
		int op;
		int val;
		char * name;
	}attr;*/

	// enum TypeSpec type; 

};

/**************************************************/
/***********   Flags for tracing       ************/
/**************************************************/

/* TraceScan = TRUE causes token information to be
 * printed to the listing file as each token is
 * recognized by the scanner
 */
extern int TraceScan;

/* TraceParse = TRUE causes the syntax tree to be
 * printed to the listing file in linearized form
 * (using indents for children)
 */
extern int TraceParse;

/* TraceAnalyze = TRUE causes symbol table inserts
 * and lookups to be reported to the listing file
 */
extern int TraceAnalyze;

/* TraceCode = TRUE causes comments to be written
 * to the TM code file as code is generated
 */
extern int TraceCode;


#endif