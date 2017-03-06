/************************************************
* File: parse.h 
* Parse interface for CMinus
* Authors: Jasmine Kandloosi and Vanessa White
    Originally provided by Fei Song
* February 2017
*************************************************/

#ifndef _PARSE_H_
#define _PARSE_H_

/**
* struct TreeNode * parse(void)
* Used in: cm.y, main.c
*
* Returns the newly constructed syntax tree
*
* @return the syntax tree created
**/
struct TreeNode * parse(void);

#endif