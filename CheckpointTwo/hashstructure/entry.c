/************************************************
* File: entry.c
* Linked list functions
* Authors: Jasmine Kandloosi and Vanessa White
* March 2017
*************************************************/
#include "entry.h"

struct Entry * createEntryList() {

	struct Entry * entries;
	entries = NULL;

	return entries;
}

void destroyEntries(struct Entry * entries) {

	entries->type = 0;
	entries->tokenValue = 0;
	entries->lineno = 0;
	free(entries->key);
	free(entries);
}

struct Entry * newEntryNode(char * key, enum ExpType type, int tokenValue, int lineno) {

	struct Entry * newEntry = malloc(sizeof(struct Entry));

	if(!newEntry)
	{
		fprintf(stderr, "in entry.c: Out of memory\n");
		return NULL;
	}

	newEntry->key = malloc(sizeof(char) * strlen(key) + 1);
	strcpy(newEntry->key, key);
	newEntry->type = type;
	newEntry->tokenValue = tokenValue;
	newEntry->lineno = lineno;
	newEntry->next = NULL;	

	return newEntry;
}

struct Entry * addToFront(struct Entry * entries, struct Entry * toAdd) {

	if(isEmpty(entries) == 1)
	{
		entries = toAdd;
		entries->next = NULL;
	}
	else
	{
		toAdd->next = entries;
		entries = toAdd;
	}

	return entries;
}

struct Entry * removeFromFront(struct Entry * entries) {

	struct Entry *temp;

	temp = entries;

	if(isEmpty(entries) == 1)
	{
		fprintf(stderr, "in entry.c: List is empty, no head to remove.\n");
	}
	else
	{

		temp = entries;
		entries = entries->next;
		destroyEntries(temp);
	}

	return entries;
}

int isEmpty(struct Entry * entries) {

	if(!entries)
	{
		return 1;
	}

	return 0;
}


void printEntries(struct Entry * entries) {

	if(isEmpty(entries) == 1)
	{
		fprintf(stderr, "List is empty.\n" );
		return;
	}

	printf("key[%s]: type: %d token: %d line: %d\n", entries->key, entries->type, entries->tokenValue, entries->lineno);
	printEntries(entries->next);
}



