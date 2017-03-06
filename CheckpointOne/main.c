/************************************************
* File: main.c 
* Main program for CMinus
* Authors: Jasmine Kandloosi and Vanessa White
* February 2017
*************************************************/
/* set NO_PARSE to TRUE to get a scanner-only compiler */
#define NO_PARSE FALSE

#include "globals.h"
#include "util.h"
#if NO_PARSE
#include "scan.h"
#else
#include "parse.h"
#endif

/* allocate global variables */
int lineno = 0;
FILE * source;
FILE * listing;
FILE * code;

/* allocate and set tracing flags */
int TraceScan = TRUE;
int TraceParse = TRUE;
int TraceAnalyze = FALSE;
int TraceCode = FALSE;

int main(int argc, char const *argv[])
{
	char srcName[120];
	int ttype;
	struct TreeNode * tree;

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
			listing = stdout;
			#if NO_PARSE
				while( (ttype = getToken())!= 0 )
					printToken( ttype, tokenString );
			#else
				tree = parse();
				if (TraceParse)
				{
					fprintf(listing,"\nSyntax tree:\n");
					abstractSyntaxTree();
	  			}
			#endif
		}
		else
		{
			fprintf(stderr,"usage: %s [-a] <filename>\n",argv[0]);
			exit(1);
		}
	}

	return 0;
}

