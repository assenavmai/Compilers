/************************************************
* File: entry.h 
* linked list data structure specification
* Authors: Jasmine Kandloosi and Vanessa White
* March 2017
*************************************************/


#ifndef _ENTRY_H
#define _ENTRY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../globals.h"

struct Entry {

	char * key;
	enum ExpType type;
	int tokenValue;
	int lineno;
	int count;
	struct Entry * next;
};

/**
* struct Entry * createEntryList();
* Used in: entry.c
*
* Creates the new list with the entries
*
* @return new created list
**/
struct Entry * createEntryList();

/**
* void destroyEntries(struct Entry * entries);
* Used in: entry.c
*
* Destroys entry list
* 
* @param entries: list of entries
*
**/
void destroyEntries(struct Entry * entries);

/**
* struct Entry * newEntryNode(char * key, enum ExpType type, int tokenValue, int lineno);
* Used in: entry.c, hash.c
*
* Creates a new node that can be inserted into the hash tale
* 
* @param key: the lexical symbol
* @param type: the type specifier
* @param tokenValue: value of the token
* @param lineno: line number
*
* @return a new node 
**/
struct Entry * newEntryNode(char * key, enum ExpType type, int tokenValue, int lineno);

/**
* struct Entry * addToFront(struct Entry * entries, struct Entry * toAdd);
* Used in: entry.c
*
* Adds node to the front of the list
* 
* @param entries: list of entries
* @param toAdd: data to add to the entries
*
* @return the head of the entries list
**/
struct Entry * addToFront(struct Entry * entries, struct Entry * toAdd);

/**
* struct Entry * removeFromFront(struct Entry * entries);
* Used in: entry.c
*
* Adds node to the front of the list
* 
* @param entries: list of entries
*
* @return the head of the entries list
**/
struct Entry * removeFromFront(struct Entry * entries);

/**
* int isEmpty(struct Entry * entries);
* Used in: entry.c
*
* Checks if entries list is empty
* 
* @param entries: list of entries
*
* @return 1 if it is empty, otherwise 0
**/
int isEmpty(struct Entry * entries);

/**
* void printEntries(struct Entry * entries);
* Used in: entry.c
*
* Prints entire entries list
* 
* @param entries: list of entries
*
**/
void printEntries(struct Entry * entries);



#endif