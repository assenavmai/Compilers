/************************************************
* File: main.c 
* Main program for CMinus
* Authors: Jasmine Kandloosi and Vanessa White
* February 2017
*************************************************/

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"

int main(int argc, char const *argv[])
{
	struct TreeNode * tree;
	
	tree = parse();
    fprintf(stdout,"\nSyntax tree:\n");
    printTree(tree);
	return 0;
}