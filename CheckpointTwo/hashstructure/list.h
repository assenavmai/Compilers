/************************************************
* File: entry.h 
* linked list data structure specification
* Authors: Jasmine Kandloosi and Vanessa White
* March 2017
*************************************************/


#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../globals.h"
#include "../scan.h"

struct entryNode {
	char key[MAXTOKENLEN];
	enum ExpType type;
	int tokenValue;
	int lineno;
	int count;
	struct entryNode * next;
};

struct entryList {

	struct entryNode * head;
	int size;
	int id;
	char name[128];
};

struct entryNode * initnode(char * key, enum ExpType type, int tokenValue, int lineno);
struct entryNode * insertNode(struct entryNode * this, char * key, enum ExpType type, int tokenValue, int lineno);
struct entryNode * deleteNode(struct entryNode * this);

struct entryList * createList();
void destroyList(struct entryNode * this);
struct entryList * addToList(struct entryList * this, char * key, enum ExpType type, int tokenValue, int lineno);
void removeFromList(struct entryList * this);
void printList(struct entryNode * this);



#endif