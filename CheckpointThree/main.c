/************************************************
* File: main.c 
* Main program for CMinus
* Authors: Jasmine Kandloosi and Vanessa White
* February 2017
*************************************************/
#define STDOUT FALSE

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"
#include "symlist.h"
#include "codegen.h"

/* allocate global variables */
int lineno = 0;
int position = 0;
int sPos = 0;
FILE * source;
FILE * listing;
FILE * code;

int TraceCode = TRUE;

int main(int argc, char const *argv[])
{
	struct TreeNode * tree;
	char sourceFilename[120];
	char outFile[120];
	char * ext;
	char ch;
	int i = 0;
	int j = 0;

	//symtable = createTable();
	globalList = createList();
	symtable[position] = createTable();
	stackTable[sPos] = createTable();
	globalList = addToList(globalList, symtable[position]);
	stack = addToList(stack, stackTable[sPos]);
	//globalList->table = addToTable(globalList->table, "output", Void, )


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


	if(strcmp(argv[1], "-a") == 0) // print the abstract syntax tree to the file
	{
		strcat(outFile, ".abs");

		source = fopen(sourceFilename, "r"); // file with the code

		if(!source)
		{
			fprintf(stderr, "Error: File %s not found\n", sourceFilename);
			exit(1);
		}
		
		#if STDOUT
			listing = stdout;

		#else
		    listing = fopen(outFile, "w");	// file with abstract syntax tree
			if(!listing)
			{
				fprintf(stderr, "Error: File %s not found\n", outFile);
				exit(1);
			}
		#endif

		tree = parse();
		fprintf(listing,"\nSyntax tree:\n");
		printTree(tree);
	}
	else if(strcmp(argv[1], "-s") == 0) // print the symbol table to the file
	{
		strcat(outFile, ".sym");

		source = fopen(sourceFilename, "r"); // file with the code

		if(!source)
		{
			fprintf(stderr, "Error: File %s not found\n", sourceFilename);
			exit(1);
		}
		
		#if STDOUT
			listing = stdout;
		#else
		    listing = fopen(outFile, "w");	// file with abstract syntax tree
			if(!listing)
			{
				fprintf(stderr, "Error: File %s not found\n", outFile);
				exit(1);
			}

		#endif

		tree = parse();
		printSymbolTable(stack);
	}
	else if(strcmp(argv[1], "-c") == 0) // tm compilation
	{
		strcat(outFile, ".tm");

		source = fopen(sourceFilename, "r"); // file with the code

		if(!source)
		{
			fprintf(stderr, "Error: File %s not found\n", sourceFilename);
			exit(1);
		}
		
		    code = fopen(outFile, "w");	// file with abstract syntax tree
			if(!code)
			{
				fprintf(stderr, "Error: File %s not found\n", outFile);
				exit(1);
			}

		tree = parse();
		listing = stdout;
		printSymbolTable(stack);
		codeGeneration(tree, outFile);


	}
	
	return 0;
}