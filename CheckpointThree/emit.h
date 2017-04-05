#ifndef _EMIT_H_
#define _EMIT_H_


// program counter
#define pc 7

// global pointer (top of memory)
#define gp 6

// frame pointer (bottom)
#define fp 5

// accumulator
#define ac 0

// accumulato x2
#define ac1 1

void emitComment(char * comment);
void emitRM(char * opcode, int reg, int offset, int base, char * comment);
void emitRM_Abs(char * opcode, int targetReg, int abs, char * comment);
void emitRO(char * opcode, int targetReg, int srcReg1, int srcReg2, char * comment);
int emitSkip(int distance);
void emitBackup(int loc);
void emitRestore();
int getInputOffset();
int getOutputOffset();

#endif