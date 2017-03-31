#ifndef _SYM_HASH_
#define _SYM_HASH_

#include "globals.h"
#include "symlist.h"

#define MIN_TABLE_SIZE 1
#define MAXSIZE 19937
#define SHIFT 4

struct symhash {

	int size;
	struct symlist ** table;
};

struct symhash* createTable();
void insert(struct symhash * tb, char * key, enum ExpType type, int token, int lineno, int scopelvl);
struct symlist * lookup(struct symhash *tb, char * key);
void printTable(struct symhash * tb);
int hash(char * key);
void update(struct symhash * tb, char * key, int newValue);
void deleteValue(struct symhash *tb, char * key);
void destroyTable(struct symhash *t);
#endif