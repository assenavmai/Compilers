/************************************************
* File: hash.h 
* Hash table data structure specification
* Authors: Jasmine Kandloosi and Vanessa White
* March 2017
*************************************************/


#ifndef _HASH_H
#define _HASH_H_

#define MIN_TABLE_SIZE 1
#define MAXSIZE 19937
#define SHIFT 4

#include "../globals.h"
#include "list.h"

struct HTable {

	int size;
	int elements;
	struct entryList ** table;
};

/**
* struct HTable * create(int size);
* Used in: hash.c, cm.y
*
* Creates a new hash table
* 
* @param size: size for the hash table
*
* @return the new allocated hash table
**/
struct HTable * create(int size);

/**
* void destroyTable(struct HTable * table);
* Used in: hash.c
*
* destroy hash table
* 
* @param table: the hash table
*
**/
void destroyTable(struct HTable * table);


/**
* void insert(struct HTable * hashTable, char * key, enum ExpType type, int tokenValue, int lineno)
* Used in: hash.c, cm.y
*
* Inserts a node into the hash table
* 
* @param key: the lexical symbol
* @param type: the type specifier
* @param tokenValue: value of the token
* @param lineno: line number
*
**/
void insert(struct HTable * hashTable, char * key, enum ExpType type, int tokenValue, int lineno);

/**
* int hash(char * key);
* Used in: hash.c
*
* Hashing function: Add and Fold
* 
* @param key: the lexical symbol
*
* @return the hash value
**/
int hash(char * key);

/**
* struct entryList * lookup(struct HTable * table, char * key);
* Used in: hash.c, cm.y
*
* Looks up a node in the hash table
* 
* @param table: the hash table
* @param key: the lexical symbol
*
* @return the hashtable with the new node
**/
struct entryList * lookup(struct HTable * table, char * key);

/**
* void deleteKey(struct HTable * table, char * key);
* Used in: hash.c
*
* Deletes key in hash table
* 
* @param table: the hash table
* @param key: the lexical symbol
*
**/
void deleteKey(struct HTable * table, char * key);

/**
* void printTable(struct HTable * table);
* Used in: hash.c
*
* Prints out the hash table
* 
* @param table: the hash table
*
**/
void printTable(struct HTable * table);

void printHash(struct HTable * h);


#endif