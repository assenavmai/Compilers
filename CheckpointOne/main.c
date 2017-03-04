/************************************************
* File: main.c 
* Main program for CMinus
* Authors: Jasmine Kandloosi and Vanessa White
* February 2017
*************************************************/

#include "globals.h"

int main(int argc, char const *argv[])
{
	struct TreeNode * syntaxTree;
	
	syntaxTree = parse();
    fprintf(stdout,"\nSyntax tree:\n");
    printTree(syntaxTree);
	return 0;
}