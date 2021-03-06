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
/* returns the newly constructed syntax tree
 */

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