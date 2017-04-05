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


/**
* void emitComment(char * comment)
* Used in: emit.c codegen.c
*
* Prints a comment to the TM file
* 
* @param comment: comment to be emitted
**/
void emitComment(char * comment);

/**
* void emitRM(char * opcode, int reg, int offset, int base, char * comment)
* Used in: emit.c codegen.c
*
* Emits a RM opcode to the TM file
* 
* @param opcode: opcode
* @param reg: register
* @param offset: offset
* @param base: base address
* @param comment: comment to be emitted
**/
void emitRM(char * opcode, int reg, int offset, int base, char * comment);

/**
* void emitRM_Abs(char * opcode, int targetReg, int abs, char * comment)
* Used in: emit.c codegen.c
*
* Emits an absolute address instruction
* 
* @param opcode: opcode
* @param targetReg: targetReg
* @param abs: absolute address
* @param base: base address
* @param comment: comment to be emitted
**/
void emitRM_Abs(char * opcode, int targetReg, int abs, char * comment);

/**
* void emitRO(char * opcode, int targetReg, int srcReg1, int srcReg2, char * comment)
* Used in: emit.c codegen.c
*
* Emits a RO instruction
* 
* @param opcode: opcode
* @param targetReg: targetReg
* @param srcReg1: source register 1
* @param srcReg2: source register 2
* @param comment: comment to be emitted
**/
void emitRO(char * opcode, int targetReg, int srcReg1, int srcReg2, char * comment);

/**
* int emitSkip(int distance)
* Used in: emit.c codegen.c
*
* Skips the body of a funciton
* 
* @param distance: distance to skip
**/
int emitSkip(int distance);

/**
* int emitSkip(int distance)
* Used in: emit.c codegen.c
*
* Backup to the location that was previously skipped
* 
* @param loc: location on to backup tp
*
* @return the distance to ski[]
**/
void emitBackup(int loc);

/**
* int emitRestore()
* Used in: emit.c codegen.c
*
* Restore to the emit location
* 
**/
void emitRestore();

/**
* int getInputOffset()
* Used in: emit.c codegen.c
*
* Get the input the offset to call it
* 
* @return the offset to go to input
**/
int getInputOffset();

/**
* int getInputOffset()
* Used in: emit.c codegen.c
*
* Get the output the offset to call it
*
* @return the offset to go to input
**/
int getOutputOffset();

#endif