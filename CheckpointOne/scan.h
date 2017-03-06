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

/* tokenString array stores the lexeme of each token */
extern char tokenString[MAXTOKENLEN+1];
extern char idString[MAXTOKENLEN+1];
extern char numString[MAXTOKENLEN+1];

/**
* int getToken(void)
* Used in: cm.l, cm.y
*
* Gets the current token being processed
*
* @return the current token
**/
int getToken(void);

#endif