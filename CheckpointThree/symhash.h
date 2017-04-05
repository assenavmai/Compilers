#ifndef _SYMHASH_H_
#define _SYMHASH_H_

#include "scan.h"
#include "globals.h"
#include "uthash.h"


struct symhash {
	char key[MAXTOKENLEN];
	enum ExpType type; //enum
	int token;
  	int lineno;
  	int memLocation;
  	int i;
  	int y;
  	//enum Scope scope;
  	UT_hash_handle hh;
};

//struct symhash * table = NULL;
struct symhash * createTable();
struct symhash * addToTable(struct symhash * table, char * key, enum ExpType type, int token, int lineno, int memloc);
struct symhash * lookup(struct symhash * table, char * key);
struct symhash * deleteElement(struct symhash * table, char * key);
void deleteTable(struct symhash * table);
void printTable(struct symhash * table);

/**
stack->table = addToTable(stack->table, "input", Integer, 0, -1, 0);
stack->table = addToTable(stack->table, "input", Integer, 0, -1, 0);
**/

#endif