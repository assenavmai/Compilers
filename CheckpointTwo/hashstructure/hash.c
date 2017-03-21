/************************************************
* File: hash.c
* Hash table functions
* Authors: Jasmine Kandloosi and Vanessa White
* March 2017
*************************************************/
#include "hash.h"

struct HTable * create(int size) {

	struct HTable * newTable;
	int i;

	newTable = malloc(sizeof(struct HTable));
	newTable->table = malloc(sizeof(struct entryList *) * size);

	if(!newTable || !newTable->table)
	{
		fprintf(stderr, "in hash.c: Out of memory.\n");
		exit(1);
	}

	if(size < MIN_TABLE_SIZE)
	{
		fprintf(stderr, "in hash.c: Size of table cannot be less than 1.\n");
		exit(1);
	}

	for(i = 0; i < size; i++)
	{
		newTable->table[i] = createList();
	}

	newTable->size = size;
	newTable->elements = 0;

	return newTable;
}

//incomplete
void destroyTable(struct HTable * hashTable) {

	int i = 0;

	if(!hashTable)
	{
		return;
	}

	for(i = 0; i < hashTable->size; i++)
	{
		//destroyList(hashTable->table[i]);
		hashTable->table[i] = NULL;
	}

	free(hashTable->table);
	free(hashTable);
}

void insert(struct HTable * hashTable, char * key, enum ExpType type, int tokenValue, int lineno) {

	struct entryList *newNode, *list;
	int hashIndex = 0;

	hashIndex = hash(key);
	
	list = hashTable->table[hashIndex];
	addToList(list, key, type, tokenValue, lineno);

}

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

struct entryList * lookup(struct HTable * hashTable, char * key) {

	struct entryList * entries;
	int hashIndex = hash(key);

	entries = hashTable->table[hashIndex];

	if(!entries)
	{
		printf("in lookup: entries list is null.\n");
	}

	while(entries->head)
	{
		if(strcmp(key, entries->head->key) == 0)
		{
			return entries;
		}

		entries->head = entries->head->next;
	}

	return NULL;
}

void deleteKey(struct HTable * hashTable, char * key) {

	struct entryList * entries;
	int hashIndex = 0;

	hashIndex = hash(key);
	entries = hashTable->table[hashIndex];

	while(entries->head)
	{
		if(strcmp(key, entries->head->key) == 0)
		{
			removeFromList(entries);
		}
		//printf("After remove %s\n", entries->head->next->key);

		entries->head = entries->head->next;
	}
}

void printTable(struct HTable * hashTable) {

	int i = 0;

	if(!hashTable)
	{
		fprintf(stderr, "Hashtable is empty, will not print.\n");
	}

	for(i = 0; i < hashTable->size; i++)
	{
		if(hashTable->table[i])
		{
			printList(hashTable->table[i]);
		}
	}
}

void printHash(struct HTable * h) {

	struct entryNode * temp, *check;
	struct entryList * list;
	int i = 0;

	if(!h)
	{
		printf("table empty\n");
	}

	for(i = 0; i < h->size; i++)
	{
		list = h->table[i];
		temp = list->head;

		while(list->head)
		{
			check = list->head;
			printf("%s %d %d %d\n", check->key, check->type, check->tokenValue, check->lineno);

			list->head = list->head->next;
		}
		list->head = temp;
	}

}
