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
	newTable->table = malloc(sizeof(struct Entry *) * size);

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
		newTable->table[i] = 0;
	}

	newTable->size = size;

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
		if(hashTable)
		{
			destroyEntries(hashTable->table[i]);
		}
	}

	free(hashTable->table);
	free(hashTable);
}

void insert(struct HTable * hashTable, char * key, enum ExpType type, int tokenValue, int lineno) {

	struct Entry *newEntry, *entries;
	int hashIndex = 0;

	newEntry = malloc(sizeof(struct Entry));

	if(!newEntry)
	{
		fprintf(stderr, "in hash.c: Out of memory.\n");
		exit(1);
	}

	hashIndex = hash(key);

	newEntry = newEntryNode(key, type, tokenValue, lineno);
	//newEntry->next = hashTable->table[hashIndex];
	//hashTable->table[hashIndex] = newEntry;
	
	entries = hashTable->table[hashIndex];
	newEntry = addToFront(entries, newEntry);
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

struct Entry * lookup(struct HTable * hashTable, char * key) {

	struct Entry * entries;
	int hashIndex = hash(key);

	entries = hashTable->table[hashIndex];

	if(!entries)
	{
		printf("in lookup: entries list is null.\n");
	}

	while(entries)
	{
		if(strcmp(key, entries->key) == 0)
		{
			return entries;
		}

		entries = entries->next;
	}

	return NULL;
}

void deleteKey(struct HTable * hashTable, char * key) {

	struct Entry * temp;
	int hashIndex = 0;

	temp = lookup(hashTable, key);
	hashIndex = hash(key);

	if(!temp)
	{
		return;
	}
	else
	{
		destroyEntries(temp);
		//hashTable->table[hashIndex];
		hashTable->size = hashTable->size - 1;
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
			printEntries(hashTable->table[i]);
		}
	}
}
