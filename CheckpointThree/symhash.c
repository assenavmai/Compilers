#include "symhash.h"

struct symhash * createTable() {

	struct symhash * t;
	t = NULL;

	return t;
}

struct symhash * addToTable(struct symhash * table, char * key, enum ExpType type, int token, int lineno, int memloc) {

	struct symhash * t;

	HASH_FIND_STR(table, key, t);

	if(!t)
	{
		t = (struct symhash*)malloc(sizeof(struct symhash) * 4);
		strcpy(t->key, key);
		HASH_ADD_STR(table, key, t);
	}

	t->type = type;
	t->token = token;
	t->lineno = lineno;
	t->memLocation = memloc;
	t->i  = 0;
	t->y = 0;

	return table;
}


struct symhash * lookup(struct symhash * table, char * key) {

	struct symhash * t;

	HASH_FIND_STR(table, key, t);
	//printf("boys\n");

	return t;
}


struct symhash * deleteElement(struct symhash * table, char * key) {

	struct symhash * t;

	HASH_FIND_STR(table, key, t);
	HASH_DEL(table, t);
	free(t);

	return table;
}

void deleteTable(struct symhash * table) {

	struct symhash *curr, *temp;

	HASH_ITER(hh, table, curr, temp)
	{
		HASH_DEL(table, curr);
		free(curr);
	}

}


void printTable(struct symhash * table) {

	struct symhash * t;

	if(!table)
	{
		printf("Table is empty\n");
		return;
	}
	for(t = table; t != NULL; t = (struct symhash *)(t->hh.next))
	{
		printf("key %s type %d token %d lineno %d\n", t->key, t->type, t->token, t->lineno);
	}
}