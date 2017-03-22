#include "symlist.h"

struct symlist * createList() {

	struct symlist * head;

	head = NULL;

	return head;
}

struct symlist * initNode(char * key, enum ExpType type, int token, int lineno) {

	struct symlist * node = malloc(sizeof(struct symlist));

	if(!node)
	{
		fprintf(stderr, "Out of memory error\n");
		return NULL;
	}

	strcpy(node->key, key);
	node->type = type;
	node->token = token;
	node->lineno = lineno;
	node->next = NULL;

	return node;
}

struct symlist * addFront(struct symlist * list, struct symlist * toAdd) {

	struct symlist * node;

	node = NULL;

	if(!list)
	{
		list = toAdd;
		//list->next = NULL;
	}
	else
	{
		toAdd->next = list;
		list = toAdd;
	}

	return list;
}

struct symlist * removeFront(struct symlist * list) {

	struct symlist * temp;

	temp = list;

	if(!list)
	{
		fprintf(stderr, "removeFront(): list empty, no head to remove.\n");
		return NULL;
	}

	list = list->next;
	free(temp);

	return list;
}

void destroyList(struct symlist * list) {

	struct symlist * temp;

	if(!list)
	{
		fprintf(stderr, "destroyList(): list empty, nothing to free.\n");
		return;
	}

	while(list)
	{
		temp = list;
		list = list->next;
		free(temp);
	}

	list = NULL;
}

void printList(struct symlist * list) {

	if(!list)
	{
		fprintf(stderr, "printList(): list is empty\n");
		return;
	}

	printf("key: %s type: %d token: %d lineno: %d\n", list->key, list->type, list->token, list->lineno);
	printList(list->next);
}