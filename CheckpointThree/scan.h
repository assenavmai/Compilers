/************************************************
* File: scan.h 
* Scanner interface for CMinus
* Authors: Jasmine Kandloosi and Vanessa White
    Originally provided by Fei Song
* February 2017
*************************************************/

#ifndef _SCAN_H_
#define _SCAN_H_

/* MAXTOKENLEN is the maximum size of a token */
#define MAXTOKENLEN 40
#define MAXARRLEN 512

/* tokenString array stores the lexeme of each token */
extern char tokenString[MAXTOKENLEN+1];
extern char idString[MAXTOKENLEN+1];
extern char numString[MAXTOKENLEN+1];
extern char currLine[256];
extern struct symlist * globalList;
extern struct symlist * stack;
extern struct symhash * symtable[MAXARRLEN];
extern struct symhash * stackTable[MAXARRLEN];



/**
* [FUNCTION PROTOTYPE]
* Used in: [list files]
*
* [Line what the function does]
* 
* @param name: description
* @param name: description
* @param name: description
*
* @return
**/

#endif