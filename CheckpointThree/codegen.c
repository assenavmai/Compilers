#include "codegen.h"

#define ofpFO 0
#define retFO -1
#define initFO -2

static int globalOffset = 0;
static int entry = 0;
static int numParams = 0;
static int localOffset = initFO;
static int inFunction = FALSE;
static int isReturn = FALSE;
static char codestr[256];


int genCmpdOffset(struct TreeNode * tree) {

	int offset = 0;

	if(tree)
	{
		if(tree->nodeKind == DeclKind)
		{
			struct TreeNode * temp = tree;

			while(temp)
			{
				switch(temp->kind.dec)
				{
					case VarK:
						if(temp->etype == Array)
						{
							offset += temp->val;
						}
						else
						{
							++offset;
						}
						break;
					case ParamK:
						++offset;
						break;
					default:
						break;
				}

				temp = temp->sibling;
			}
		}
	}

	return offset;
}

void genPrelude() {
	emitComment("Standard prelude: ");
	emitRM("LD", gp, 0, ac, "load gp with maxaddress");
	emitRM("LDA", fp, 0, gp, "copy gp to fp");
	emitRM("ST", ac, 0, ac, "clear location 0");
}

void genPredefinedIO() {

	emitComment("Jump around i/o routines here");
	emitComment("code for input routine");
	int savedLoc = emitSkip(1);
	emitRM("ST", ac, retFO, fp, "store return");
	emitRO("IN", 0, 0, 0, "input");
	emitRM("LD", pc, retFO, fp, "return to caller");

	emitComment("code for output routine");
	emitRM("ST", ac, retFO, fp, "store return");
	emitRM("LD", ac, initFO, fp, "load output value");
	emitRO("OUT", 0, 0, 0, "output");
	emitRM("LD", pc, retFO, fp, "return to caller");


	int savedLoc2 = emitSkip(0);
	emitBackup(savedLoc);
	emitRM_Abs("LDA", pc, savedLoc2, "jump around i/o code");
	emitRestore();
}

void genFinale() {

	emitRM("ST", fp, globalOffset+ofpFO, fp, "push ofp");
	emitRM("LDA", fp, globalOffset, fp, "push frame");
	emitRM("LDA", ac, 1, pc, "load ac with ret ptr");
	printf("Entry %d\n", entry);
	emitRM_Abs("LDA", pc, entry, "jump to main loc");
	emitRM("LD", fp, ofpFO, fp, "pop frame");
	emitComment("End of execution.");
	emitRO("HALT", 0, 0, 0, "");
}

void genStmt(struct TreeNode * tree) {

	struct TreeNode * child1, * child2, *child3;
	int savedLoc, savedLoc2, savedLoc3, offset;
	int numArgs = 0;
	int loc;

	if(tree)
	{
		switch(tree->kind.stmt)
		{
			case IfK:
				printf("\tif\n");

				if(TraceCode)
				{
					emitComment("-> if");
				}

				child1 = tree->child[0];
				child2 = tree->child[1];
				child3 = tree->child[2];

				// conditional expression
				cGen(child1);

				savedLoc = emitSkip(1);
				emitComment("if: jump to else belongs here");

				// if condition is true then body is executed
				cGen(child2);

				savedLoc2 = emitSkip(1);
				emitComment("if: jump to end belongs here");

				savedLoc3 = emitSkip(0);
				emitBackup(savedLoc);
				emitRM_Abs("JEQ", ac, savedLoc3, "if: jmp to else");
				emitRestore();

				// else condition
				cGen(child3);

				savedLoc3 = emitSkip(0);
				emitBackup(savedLoc2);
				emitRM_Abs("LDA", pc, savedLoc3, "jmp to end");
				emitRestore();

				if(TraceCode)
				{
					emitComment("<- if");
				}
				break;
			case ReturnK:
				printf("\treturn\n");
				isReturn = TRUE;
				if(TraceCode)
				{
					emitComment("-> return");
				}

				child1 = tree->child[0];

				// return expression
				cGen(child1);
				emitRM("LD", pc, retFO, fp, "return to caller");

				if(TraceCode)
				{
					emitComment("<- return");
				}
				break;
			case WhileK:
				printf("\twhile\n");

				if(TraceCode)
				{
					emitComment("-> while");
				}

				child1 = tree->child[0];
				child2 = tree->child[1];

				savedLoc = emitSkip(0);
				emitComment("while: jump after body comes back here");

				// conditional expression
				cGen(child1);

				savedLoc2 = emitSkip(1);
				emitComment("while: jump to end belongs here");

				// while body
				cGen(child2);
				emitRM_Abs("LDA", pc, savedLoc, "while: absolute jmp to test");

				//backpatch while
				savedLoc3 = emitSkip(0);
				emitBackup(savedLoc2);
				emitRM_Abs("JEQ", ac, savedLoc3, "while: jmp to end");
				emitRestore();

				if(TraceCode)
				{
					emitComment("<- while");
				}
				break;
			case CmpdK:
				printf("\tcmpd\n");

				if(TraceCode)
				{
					emitComment("-> compound statement");
				}
				child1 = tree->child[0];
				child2 = tree->child[1];

				// get offset for local declarations for ch
				//offset = genCmpdOffset(child1);
				//localOffset -= offset;
				cGen(child1);

				// code body
				cGen(child2);

				//restore offset
				//localOffset -= offset;

				if(TraceCode)
				{
					emitComment("<- compound statement");
				}
				break;
			case AssignK:
				printf("\tassign\n");

				if(TraceCode)
				{
					emitComment("-> assign");
				}

				child1 = tree->child[0];
				child2 = tree->child[1];

				// generate left-hand side of expression
				genExp(child1, TRUE);
				emitRM("ST", ac, localOffset--, fp, "assign: push left");

				//cGen(child1);
				cGen(child2);

				// load lhs
				emitRM("LD", ac1, ++localOffset, fp, "assign: load left");
				emitRM("ST", ac, 0, ac1, "assign: store value");

				if(TraceCode)
				{
					emitComment("<- assign");
				}
				break;
			case CallK:
				printf("\tcall\n");

				if(TraceCode)
				{
					sprintf(codestr, "-> call of function %s", tree->name);
					emitComment(codestr);
				}

				numArgs = 0;
				child1 = tree->child[0];

				while(child1)
				{
					if(tree->etype == Array)
					{
						printf("call array\n");
						genExp(child1, TRUE);
					}
					else
					{
						printf("call non array\n");
						genExp(child1, FALSE);
					}

					emitRM("ST", ac, localOffset + initFO - (numArgs++),fp, "store arg val");	
					printf("\t\t\tnum args %d\n", numArgs);
					child1 = child1->sibling;				
				}

				emitRM("ST", fp, localOffset + ofpFO, fp, "push ofp");
				emitRM("LDA", fp, localOffset, fp, "push frame");
				emitRM("LDA", ac, 1, pc, "load ac with ret ptr");

				if(strcmp(tree->name, "input") == 0)
				{
					loc = getInputOffset();
				}
				else if(strcmp(tree->name, "output") == 0)
				{
					loc = getOutputOffset();
				}
				else
				{
					loc = findMemoryLocation(stack, tree->name);
					printf("location for call %d %s\n", loc, tree->name);
				}

				//loc = -(findMemoryLocation(stack, tree->name));
				emitRM("LDA", pc, loc, pc, "jump to fun loc");
				emitRM("LD", fp, ofpFO, fp, "pop frame");
				//cGen(child1);

				if(TraceCode)
				{
					emitComment("<- call");
				}
				break;
			default:
				break;
		}
	}
}

void genDecl(struct TreeNode * tree) {

	struct TreeNode * child1, *child2;
	int loc, funcLoc, funcBodLoc, jmpFuncLoc, val;
	int glbl = FALSE;

	if(tree)
	{
		switch(tree->kind.dec)
		{
			case VarK:
				//printf("\tvar %d\n", tree->offset);
				if(TraceCode)
				{
					if(globalOffset == 0)
					{
						sprintf(codestr, "allocating global var: %s", tree->name);
						glbl = TRUE;
					}
					else
					{
						sprintf(codestr, "processing local var: %s", tree->name);
					}
					emitComment(codestr);
				}

				if(tree->etype == Array)
				{
					val = tree->val;
				}
				else
				{
					val = 1;
				}

				if(inFunction == TRUE)
				{
					localOffset -= val;
				}
				else
				{
					globalOffset -= val;
				}

				if(TraceCode)
				{
					if(glbl == TRUE)
					{
						emitComment("<- vardecl");
					}
				}
				break;
			case FunK:
				printf("\tfunc %d\n", tree->params);

				if(TraceCode)
				{
					sprintf(codestr, "processing function: %s", tree->name);
					emitComment(codestr);
				}
				child1 = tree->child[0];
				child2 = tree->child[1];

				inFunction = TRUE;

				loc = -(findMemoryLocation(stack, tree->name));
				printf("LOCATION FUNC: %d\n", loc);

				// load function location
				funcLoc = emitSkip(1);
				emitComment("jump around function body here"); 
				emitRM("ST", ac, retFO, fp, "store return");
				--globalOffset;

				cGen(child1);
				cGen(child2);

				if(isReturn != TRUE)
    			{
					emitRM("LD", pc, retFO, fp, "return to caller");
    			}

    			// skip codegen and come back here for function body
				funcBodLoc = emitSkip(0);

				if(strcmp("main", tree->name) == 0)
				{
					entry = funcLoc + 1;
				}

				//back patching (11 in fac.tm)
				emitBackup(funcLoc);
				emitRM_Abs("LDA", pc, funcBodLoc, "jump around fn body");
    			emitRestore();



				inFunction = FALSE;

				if(TraceCode)
				{
					emitComment("<- fundecl");
				}


				break;
			case ParamK:
				printf("\tparam\n");
				emitComment("param");
				--localOffset;
				++numParams;
				break;
			default:
				break;
		}
	}
}

void genExp(struct TreeNode * tree, int isAddress) {

	struct TreeNode * child1, *child2;
	int offsetVar;
	int loc;

	if(tree)
	{
		switch(tree->kind.exp)
		{
			case ConstK:
				printf("\tconst\n");

				if(TraceCode)
				{
					emitComment("-> constant");
				}

				emitRM("LDC", ac, tree->val, 0, "load const");

				if(TraceCode)
				{
					emitComment("<- constant");
				}
				break;
			case IdK:
				printf("\tid\n");

				if(TraceCode)
				{
					emitComment("-> id");
					sprintf(codestr, "looking up id: %s", tree->name);
					emitComment(codestr);

				}

				loc = findMemoryLocation(stack, tree->name);
				printf("idK memloc %d\n", loc);

				if(loc >= 0)
				{
					offsetVar = retFO - loc;
				}
				else
				{
					printf("else IDK\n");
					offsetVar = -(findMemoryLocation(stack, tree->name));
				}
				printf("OFFSET IDK: %d\n", offsetVar);
				
				/*if(tree->isArr == 1)
				{
					printf("\t\tisArr IDk\n");

					if(loc >= 0 && loc < numParams)
					{

					}
					else
					{
						if(loc >= 0)
						{
							
						}
						else
						{
	
						}
					}

					//emit ST
					// index
					child1 = tree->child[0];
					cGen(child1);

					//get correct offset

				}
				else
				{

				}*/

				if(isAddress)
				{
					emitRM("LDA", ac, offsetVar, fp, "load id address");
				}
				else
				{
					emitRM("LD", ac, offsetVar, fp, "load id value");
				}
				if(TraceCode) emitComment("<- id");
				break;
			case OpK:
				printf("\top\n");
				if(TraceCode)
				{
					emitComment("-> op");
				}

				child1 = tree->child[0];
				child2 = tree->child[1];

				cGen(child1);

				emitRM("ST", ac, localOffset--, fp,"op: push left");

				cGen(child2);

				emitRM("LD", ac1, ++localOffset, fp, "op: load left");

				switch(tree->op)
				{
					case PLUS:
						printf("add \n");
						emitRO("ADD", ac, ac1, ac, "op +");
						break;
					case MINUS:
						printf("subtract \n");
						emitRO("SUB", ac, ac1, ac, "op -");
						break;
					case MULT:
						printf("multi \n");
						emitRO("MUL", ac, ac1, ac, "op *");
						break;
					case DIV:
						printf("div \n");
						emitRO("DIV", ac, ac1, ac, "op /");
						break;
					case LT:
						printf("less than \n");
						emitRO("SUB", ac, ac1, ac, "op <");
						emitRM("JLT", ac, 2, pc, "br if true");
						emitRM("LDC", ac, 0, ac, "false case");
						emitRM("LDA", pc, 1, pc, "unconditional jmp");
						emitRM("LDC", ac, 1, ac, "true case");
						break;
					case LTEQ:
						printf("less than equal \n");
						emitRO("SUB", ac, ac1, ac, "op <=");
						emitRM("JLE", ac, 2, pc, "br if true");
						emitRM("LDC", ac, 0, ac, "false case");
						emitRM("LDA", pc, 1, pc, "unconditional jmp");
						emitRM("LDC", ac, 1, ac, "true case");
						break;
					case GT:
						printf("greater than \n");
						emitRO("SUB", ac, ac1, ac, "op >");
						emitRM("JGT", ac, 2, pc, "br if true");
						emitRM("LDC", ac, 0, ac, "false case");
						emitRM("LDA", pc, 1, pc, "unconditional jmp");
						emitRM("LDC", ac, 1, ac, "true case");
						break;
					case GTEQ:
						printf("greater than equal \n");
						emitRO("SUB", ac, ac1, ac, "op <=");
						emitRM("JGE", ac, 2, pc, "br if true");
						emitRM("LDC", ac, 0, ac, "false case");
						emitRM("LDA", pc, 1, pc, "unconditional jmp");
						emitRM("LDC", ac, 1, ac, "true case");
						break;
					case DOUBEQ:
						printf("equals \n");
						emitRO("SUB", ac, ac1, ac, "op ==");
						emitRM("JEQ", ac, 2, pc, "br if true");
						emitRM("LDC", ac, 0, ac, "false case");
						emitRM("LDA", pc, 1, pc, "unconditional jmp");
						emitRM("LDC", ac, 1, ac, "true case");
						break;
					case NEQ:
						printf("not equals \n");
						emitRO("SUB", ac, ac1, ac, "op !=");
						emitRM("JNE", ac, 2, pc, "br if true");
						emitRM("LDC", ac, 0, ac, "false case");
						emitRM("LDA", pc, 1, pc, "unconditional jmp");
						emitRM("LDC", ac, 1, ac, "true case");
						break;
					default:
						printf("bug found %d\n", tree->op);
						emitComment("BUG: Unknown operator");
				}

				if(TraceCode)
				{
					emitComment("<- op");
				}
				break;
			default:
				break;
		}
	}
}

void cGen(struct TreeNode * tree) {

	if(tree)
	{
		switch(tree->nodeKind)
		{
			case StmtKind:
				printf("stmt\n");
				genStmt(tree);
				break;
			case ExpKind:
				printf("exp\n");
				genExp(tree, FALSE);
				break;
			case DeclKind:
				printf("decl\n");
				genDecl(tree);
				break;
			default:
				emitComment("BUG: missing in cGen");
				break;
		}
		cGen(tree->sibling);
	}
}

void codeGeneration(struct TreeNode * tree, char * file) {

	char * str;

	str = malloc(sizeof(char) * strlen(file) + 10);

	strcpy(str, "File: ");
	strcat(str, file);

	emitComment("C-Minus Compilation to TM Code");
	emitComment(str);

	//Standard Prelude
	genPrelude();
	// Predefined i/o functions
	genPredefinedIO();
	emitComment("End of standard prelude.");


	// Generate Code
	cGen(tree);


	//Finale
	genFinale();
}

