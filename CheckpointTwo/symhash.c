#include "symhash.h"

int hash(char * key) {

	int temp = 0;
	int i = 0;

	while(key[i] != '\0')
	{
		temp = ((temp << SHIFT) + key[i]) % MAXSIZE;
		i++;
	}

	return temp;
}

struct symhash * createTable() {

	struct symhash * tb;
	int i;

	tb = malloc(sizeof(struct symhash));
	tb->table = malloc(sizeof(struct symlist *) * MAXSIZE);

	if(!tb || !tb->table)
	{
		fprintf(stderr, "createTable(): Out of memory. Aborting.\n");
		exit(1);
	}

	if(MAXSIZE < MIN_TABLE_SIZE)
	{
		fprintf(stderr, "createTable(): Table size cannot be < 1. Aborting.\n");
		exit(1);
	}

	for(i = 0; i < MAXSIZE; i++)
	{
		tb->table[i] = createList();
	}

	tb->size = MAXSIZE;
}

void insert(struct symhash * tb, char * key, enum ExpType type, int token, int lineno, int scopelvl) {

	struct symlist * list = NULL;
	int index = 0;

	index = hash(key);

	list = addFront(list, initNode(key, type, token, lineno, scopelvl));
	list->next = tb->table[index];
	tb->table[index] = list;

}

void printTable(struct symhash * tb) {

	struct symlist* list, *temp, *node;
	int i;

	printf("Name\t\tType\t\tValue\t\tLine\t\tScope\n");
	for(i = 0; i < MAXSIZE; i++)
	{
		list = tb->table[i];
		temp = list;

		while(list)
		{
			node = list;
			if(node->type != Undeclared)
			{
				printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\n", node->key, node->type, node->token, node->lineno, node->scopelvl);
			}
			list = list->next;
		}
		list = temp;
	}
}

void deleteValue(struct symhash *tb, char * key) {
	
	struct symlist * ptr;

	ptr = lookup(tb, key);

	if(!ptr)
	{
		return;
	}
	else
	{
		ptr->isDeleted = 1;
	}
}

void destroyTable(struct symhash *tb) {

		struct symlist* list, *temp, *node;
	int i;

	//printf("Name\t\tType\t\tValue\t\tLine\t\tScope\n");
	for(i = 0; i < MAXSIZE; i++)
	{
		list = tb->table[i];
		temp = list;

		while(list)
		{
			node = list;
			if(node->type != Undeclared)
			{
				node->isDeleted = 1;
				//printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\n", node->key, node->type, node->token, node->lineno, node->scopelvl);
			}
			list = list->next;
		}
		list = temp;
	}
}

struct symlist * lookup(struct symhash *tb, char * key) {

	struct symlist * list;
	int index = 0;

	if(!key)
	{
		return NULL;
	}
	index = hash(key);

	list = tb->table[index];

	if(!list)
	{
		return NULL;
	}

	while(list)
	{
		if(strcmp(key, list->key) == 0)
		{
			return list;
		}

		list = list->next;
	}

	return NULL;
}
