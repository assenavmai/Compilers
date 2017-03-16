/************************************************
* File: util.h
* Utility functions for CMinus
* Authors: Jasmine Kandloosi and Vanessa White
    Originally provided by Fei Song
* February 2017
*************************************************/
#ifndef _UTIL_H_
#define _UTIL_H_

/**
* [FUNCTION PROTOTYPE]
* Used in: [list files]
*
* [Line what the function does]
* 
* @param name: description
* @param name: description
* @param name: description
*
* @return
**/

/**
* void printToken( int token, const char* tokenString )
* Used in: util.c, cm.l
*
* prints the token that is scanned and parsed
* 
* @param token: token being processed
* @param tokenString: description
* @param name: description
*
* @return
**/
void printToken(int token, const char* tokenString);

/**
* void skipComments();
* Used in: cm.l
*
* Skips multiline comments in the CMinus language
*
* @return none
**/
void skipComments();

/**
* printTypeSpec(enum ExpType type)
* Used in: util.c
*
* Prints the type specifier related to the node
*
* @param type: the type associated with the node 
*
* @return none
**/
void printTypeSpec(enum ExpType type);

/**
* struct TreeNode * newDeclNode(enum DeclKind dec)
* Used in: util.c
*
* Creates a new node for a declaration
*
* @param dec: The type of kind
*
* @return the node containing the declaration information
**/
struct TreeNode * newDeclNode(enum DeclKind dec);

/**
* struct TreeNode * newExpNode(enum ExpKind exp)
* Used in: util.c
*
* Creates a new node for an expression
*
* @param dec: The type of kind
*
* @return the node containing the expression information
**/
struct TreeNode * newExpNode(enum ExpKind exp);

/**
* struct TreeNode * newStmtNode(enum StmtKind stmt)
* Used in: util.c
*
* Creates a new node for a statements
*
* @param dec: The type of kind
*
* @return the node containing the statement information
**/
struct TreeNode * newStmtNode(enum StmtKind stmt);

/**
* void printTree( struct TreeNode * tree )
* Used in: util.c
*
* Prints the syntax tree
*
* @param tree: The tree
*
**/
void printTree( struct TreeNode * tree );

/**
* char * copyString(char  * str)
* Used in: util.c
*
* Allocates memory and copies a string.
*
* @param str: String to be copied
*
* @return the new string
**/
char * copyString(char  * str);


/**
* void panicMode()
* Used in: cm.l
*
* Ignores multiline errors in the code until it reaches a semicolan in the CMinus
* 
*
* @return nothing
**/
void panicMode();

#endif


