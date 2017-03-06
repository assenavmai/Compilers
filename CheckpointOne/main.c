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
	char srcName[120];

	if(argc < 3)
	{
		fprintf(stderr,"usage: %s [-a] <filename>\n",argv[0]);
		exit(1);
	}

	strcpy(srcName, argv[2]); /* get the file name without the extension */

	if(!strchr (srcName, '.'))
	{
		if(strcmp(argv[1], "-a") == 0) /* output abstract syntax tree to the file */
		{
			strcat(srcName,".abs");
			source = openSourceFile(srcName); 
			listing = source;
			abstractSyntaxTree();
		}
	}

	fclose(source);
	return 0;
}

