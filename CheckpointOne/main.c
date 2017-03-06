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

/* allocate global variables */
int lineno = 0;
FILE * source;
FILE * listing;
FILE * code;

int main(int argc, char const *argv[])
{
	struct TreeNode * tree;

	source = fopen("test.cm", "r"); // file with the code
	listing = fopen("test.abs", "w");
	
	tree = parse();
    fprintf(stdout,"\nSyntax tree:\n");
    printTree(tree);
	return 0;
}