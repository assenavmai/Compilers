#ifndef _CODEGEN_H_
#define _CODEGEN_H_

#include "globals.h"
#include "symlist.h"
#include "util.h"
#include "emit.h"
#include "y.tab.h"

/**
* void codeGeneration(struct TreeNode * tree, char * file)
*
* Generates the code to the function
* 
* @param tree: syntax tree
* @param file: TM file
**/
void codeGeneration(struct TreeNode * tree, char * file);

/**
* void cGen(struct TreeNode * tree);
*
* Generates blocks code
* 
* @param tree: syntax tree
**/
void cGen(struct TreeNode * tree);

/**
* void genStmt(struct TreeNode * tree);
*
* Generates statement code
* 
* @param tree: syntax tree
**/
void genStmt(struct TreeNode * tree);

/**
* void genDecl(struct TreeNode * tree);
*
* Generates declaration code
* 
* @param tree: syntax tree
**/
void genDecl(struct TreeNode * tree);

/**
* void cGen(struct TreeNode * tree);
*
* Generates expression code
* 
* @param tree: syntax tree
* @param isAddress: flag to know if we should load an address
**/
void genExp(struct TreeNode * tree, int isAddress);

/**
* void genPrelude()
*
* generates the prelude
* 
**/
void genPrelude();

/**
* void genFinale()
*
* generates the finale
* 
**/
void genFinale();

/**
* void genPredefinedIO()
*
* generates the input and output function
* 
**/
void genPredefinedIO();

/**
* void genCmpdOffset()
* generates the offset for the cmpd statement
*
* @param: tree: tree node structure
* 
**/
int genCmpdOffset(struct TreeNode * tree);


#endif