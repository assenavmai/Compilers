#ifndef _CODEGEN_H_
#define _CODEGEN_H_

#include "globals.h"
#include "symlist.h"
#include "util.h"
#include "emit.h"
#include "y.tab.h"

void codeGeneration(struct TreeNode * tree, char * file);
void cGen(struct TreeNode * tree);
void genStmt(struct TreeNode * tree);
void genDecl(struct TreeNode * tree);
void genExp(struct TreeNode * tree, int isAddress);
void genPrelude();
void genFinale();
void genPredefinedIO();
int genCmpdOffset(struct TreeNode * tree);


#endif