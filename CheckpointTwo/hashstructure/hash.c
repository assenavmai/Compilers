/************************************************
* File: hash.c
* Hash table functions
* Authors: Jasmine Kandloosi and Vanessa White
* March 2017
*************************************************/
#include "hash.h"

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