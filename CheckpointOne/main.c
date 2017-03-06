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
	char sourceFilename[120];
	char outFile[120];
	char * ext;
	char ch;
	int i = 0;
	int j = 0;

	if(argc < 3)
	{
		fprintf(stderr,"usage: %s [-a] <filename>\n",argv[0]);
		exit(1);
	}

	strcpy(sourceFilename, argv[2]);
	ext = strchr(sourceFilename, '.');

	/* Making sure the file is a valid file */
	if(!ext)
	{
		fprintf(stderr, "Error: File has no extension\n");
		exit(1);
	}
	else
	{
		if(strcmp(ext +1, "cm") != 0)
		{
			printf("Error: Extension has to be '.cm'\n");
			exit(1);
		}
	}

	ch = sourceFilename[i];
	while(ch != '.') //get the source file name to add the '.abs' to it
	{
		outFile[j++] = ch;
		i++;
		ch = sourceFilename[i];
	}
	outFile[j++] = '\0';


	if(strcmp(argv[1], "-a") == 0)
	{
		strcat(outFile, ".abs");

		source = fopen(sourceFilename, "r"); // file with the code

		if(!source)
		{
			fprintf(stderr, "Error: File %s not found\n", sourceFilename);
			exit(1);
		}

		listing = fopen(outFile, "w");	// file with abstract syntax tree

		if(!listing)
		{
			fprintf(stderr, "Error: File %s not found\n", listing);
			exit(1);
		}
		
		tree = parse();
	    fprintf(stdout,"\nSyntax tree:\n");
	    printTree(tree);
	}
	
	return 0;
}