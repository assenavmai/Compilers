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

/**
* struct symhash * createTable()
*
* Creates the hash table
*
* @return the null head of the hash table
**/
struct symhash * createTable();

/**
* struct symhash * addToTable(struct symhash * table, char * key, enum ExpType type, int token, int lineno, int memloc)
*
* Adds to the symbol table
* 
* @param table: the hash table
* @param key: the key
* @param type: the type
* @param token: the token val
* @param lineno: the line number
* @param memloc: memory location
*
* @return the hash table
**/
struct symhash * addToTable(struct symhash * table, char * key, enum ExpType type, int token, int lineno, int memloc);

/**
* struct symhash * lookup(struct symhash * table, char * key)
*
* Looks up in the lookup
*
* @param table: hash table
* @param key: key
* @return the hash table
**/
struct symhash * lookup(struct symhash * table, char * key);

/**
* struct symhash * deleteElement(struct symhash * table, char * key)
*
* Delete an element
*
* @param table: hash table
* @param key: key
*
* @return the hash table
**/
struct symhash * deleteElement(struct symhash * table, char * key);

/**
* void deleteTable(struct symhash * table)
*
* Delete Table
*
* @param table: hash table
**/
void deleteTable(struct symhash * table);

/**
* void printTable(struct symhash * table)
*
* prints the table
*
* @param table: hash table
**/
void printTable(struct symhash * table);



#endif