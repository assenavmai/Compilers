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

struct TreeNode * newDeclNode(enum DeclKind dec);
struct TreeNode * newExpNode(enum ExpKind exp);
struct TreeNode * newStmtNode(enum StmtKind stmt);
struct TreeNode * newTypeSpecNode(enum TypeSpec ts);
void printTree( struct TreeNode * tree );
char * allocateString(char  * str);

#endif


