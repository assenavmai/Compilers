#include "symlist.h"

struct symlist * createList() {

	struct symlist * l;

	l = NULL;
	return l;
}

struct symlist * addToList(struct symlist * head, struct symhash * t) {

	struct symlist * element;

	element = (struct symlist*)malloc(sizeof(struct symlist));
	element->table = t;

	LL_PREPEND(head, element);

	return head;
}

struct symlist * deleteNode(struct symlist * head) {

	struct symlist * l;

	l = head;

	deleteTable(l->table);
	LL_DELETE(head, l);
	free(l);

	return head;
}

void printList(struct symlist * head) {

	struct symlist * temp;
	LL_FOREACH(head, temp)
	{
		printTable(temp->table);
	}
}

void deleteList(struct symlist * head) {

	struct symlist * l, *temp;

	LL_FOREACH_SAFE(head, l, temp)
	{
		deleteTable(l->table);
		LL_DELETE(head, l);
		free(l);
	}
}

struct symhash * searchList(struct symlist * head, char * key) {

	struct symlist * l, *temp;
	struct symhash * t;
	int flag = 0;

	//printf("SEARCHLIST\n");
	LL_FOREACH(head, l)
	{
		HASH_FIND_STR(l->table, key, t);
		
		if(t)
		{
			return t;
		}
	}
	

	return NULL;
}
