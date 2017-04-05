#include "globals.h"
#include "emit.h"

static int emitLoc = 0;
static int highEmitLoc = 0;

void emitComment(char * comment) {

	if(TraceCode)
	{
		fprintf(code, "* %s\n", comment);
	}
}

void emitRM(char * opcode, int targetReg, int offset, int base, char * comment) {

	fprintf(code, "%3d:  %5s  %d,%d(%d)", emitLoc++, opcode, targetReg, offset, base);

	if(TraceCode)
	{
		fprintf(code, "\t%s", comment);
	}

	fprintf(code, "\n");

	if(highEmitLoc < emitLoc)
	{
		highEmitLoc = emitLoc;
	}
}

int getInputOffset() {

	int temp;

	temp = -(emitLoc - 3);

	return temp;
}

int getOutputOffset() {

	int temp;

	temp = -(emitLoc - 6);

	return temp;
}

void emitRM_Abs(char * opcode, int targetReg, int abs, char * comment) {

	fprintf(code, "%3d:  %5s  %d,%d(%d) ", emitLoc, opcode, targetReg, abs-(emitLoc+1), pc);
	++emitLoc;

	if(TraceCode)
	{
		fprintf(code, "\t%s", comment);
	}

	fprintf(code, "\n");

	if(highEmitLoc < emitLoc)
	{
		highEmitLoc = emitLoc;
	}
}

void emitRO(char * opcode, int targetReg, int srcReg1, int srcReg2, char * comment) {

	fprintf(code, "%3d:  %5s  %d,%d,%d", emitLoc++, opcode, targetReg, srcReg1, srcReg2);

	if(TraceCode)
	{
		fprintf(code, "\t%s", comment);
	}

	fprintf(code, "\n");

	if(highEmitLoc < emitLoc)
	{
		highEmitLoc = emitLoc;
	}
}

int emitSkip(int distance) {

	int i = emitLoc;

	emitLoc += distance;

	if(highEmitLoc < emitLoc)
	{
		highEmitLoc = emitLoc;
	}

	return i;
}

void emitBackup(int loc) {

	if(loc > highEmitLoc)
	{
		emitComment("BUG in emitComment");
	}

	emitLoc = loc;
}

void emitRestore() {

	emitLoc = highEmitLoc;
}