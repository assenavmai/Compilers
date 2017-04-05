#ifndef _SYMLIST_H_
#define _SYMLIST_H_

#include "utlist.h"
#include "symhash.h"

struct symlist {

	struct symhash * table;
	struct symlist * next;
};

struct symlist * createList();
struct symlist * addToList(struct symlist * head, struct symhash * t);
struct symlist * deleteNode(struct symlist * head);
void printList(struct symlist * head);
void deleteList(struct symlist * head);
struct symhash * searchList(struct symlist * head, char * key);

#endif