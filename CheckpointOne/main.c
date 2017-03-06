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


void abstractSyntaxTree() {

	struct TreeNode * tree;

	tree = parse();
	printTree(tree);

}

FILE * openSourceFile(char * filename) {

	FILE * temp;
	temp = fopen(filename, "w");

	if (!temp)
	{ 
		fprintf(stderr,"File %s not found\n", filename);
		exit(1);
	}

	return temp;
}

int main(int argc, char const *argv[])
{
	char srcName[120];

	if(argc < 3)
	{
		fprintf(stderr,"usage: %s [-a] <filename>\n",argv[0]);
		exit(1);
	}

	strcpy(srcName, argv[2]);

	if(!strchr (srcName, '.'))
	{
		if(strcmp(argv[1], "-a") == 0)
		{
			strcat(srcName,".abs");
			printf("sjsjss %s\n", srcName);
			source = openSourceFile(srcName); 
			listing = source;
			abstractSyntaxTree();
		}
	}

	fclose(source);
	return 0;
}

