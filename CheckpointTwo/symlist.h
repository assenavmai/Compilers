#ifndef _SYM_LIST_
#define _SYM_LIST_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scan.h"
#include "globals.h"

struct symlist {
  char key[MAXTOKENLEN];
  enum ExpType type;
  int token;
  int lineno;
  int scopelvl;
  int isDeleted;
  struct symlist * next;
};

struct symlist * createList();
struct symlist * addFront(struct symlist * list, struct symlist * toAdd);
struct symlist * initNode(char * key, enum ExpType type, int token, int lineno, int scopelvl);
void destroyList(struct symlist * list);
void printList(struct symlist * list);
struct symlist * removeFront(struct symlist * list);

#endif