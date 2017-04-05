* C-Minus Compilation to TM Code
* File: fac.tm
* Standard prelude: 
  0:     LD  6,0(0)	load gp with maxaddress
  1:    LDA  5,0(6)	copy gp to fp
  2:     ST  0,0(0)	clear location 0
* Jump around i/o routines here
* code for input routine
  4:     ST  0,-1(5)	store return
  5:     IN  0,0,0	input
  6:     LD  7,-1(5)	return to caller
* code for output routine
  7:     ST  0,-1(5)	store return
  8:     LD  0,-2(5)	load output value
  9:    OUT  0,0,0	output
 10:     LD  7,-1(5)	return to caller
  3:    LDA  7,7(7) 	jump around i/o code
* End of standard prelude.
* processing function: main
* jump around function body here
 12:     ST  0,-1(5)	store return
* -> compound statement
* -1 processing local var: x
* -1 processing local var: fac
* -> assign
* -> id
* looking up id: x
 14:    LDA  0,-2(5)	load id address
* <- id
 15:     ST  0,-4(5)	assign: push left
* -> call of function input
 16:     ST  5,-7(5)	push ofp
 17:    LDA  5,-5(5)	push frame
 18:    LDA  0,1(7)	load ac with ret ptr
 19:    LDA  7,5(7)	jump to fun loc
 20:     LD  5,0(5)	pop frame
* <- call
 21:     LD  1,-4(5)	assign: load left
 22:     ST  0,0(1)	assign: store value
* <- assign
* -> assign
* -> id
* looking up id: fac
 23:    LDA  0,-3(5)	load id address
* <- id
 24:     ST  0,-4(5)	assign: push left
* -> constant
 25:    LDC  0,1(0)	load const
* <- constant
 26:     LD  1,-4(5)	assign: load left
 27:     ST  0,0(1)	assign: store value
* <- assign
* -> while
* while: jump after body comes back here
* -> op
* -> id
* looking up id: x
 28:     LD  0,-2(5)	load id value
* <- id
* -> constant
 29:    LDC  0,1(0)	load const
* <- constant
* while: jump to end belongs here
* -> compound statement
* -> assign
* -> id
* looking up id: fac
 31:    LDA  0,-3(5)	load id address
* <- id
 32:     ST  0,-4(5)	assign: push left
* -> op
* -> id
* looking up id: fac
 33:     LD  0,-3(5)	load id value
* <- id
* -> id
* looking up id: x
 34:     LD  0,-2(5)	load id value
* <- id
 35:     LD  1,-4(5)	assign: load left
 36:     ST  0,0(1)	assign: store value
* <- assign
* -> assign
* -> id
* looking up id: x
 37:    LDA  0,-2(5)	load id address
* <- id
 38:     ST  0,-4(5)	assign: push left
* -> op
* -> id
* looking up id: x
 39:     LD  0,-2(5)	load id value
* <- id
* -> constant
 40:    LDC  0,1(0)	load const
* <- constant
 41:     LD  1,-4(5)	assign: load left
 42:     ST  0,0(1)	assign: store value
* <- assign
* <- compound statement
 43:    LDA  7,-16(7) 	while: absolute jmp to test
 30:    JEQ  0,13(7) 	while: jmp to end
* <- while
* -> call of function output
* -> id
* looking up id: fac
 44:     LD  0,-3(5)	load id value
* <- id
 45:     ST  0,-6(5)	push ofp
 46:     ST  5,-6(5)	push ofp
 47:    LDA  5,-4(5)	push frame
 48:    LDA  0,1(7)	load ac with ret ptr
 49:    LDA  7,5(7)	jump to fun loc
 50:     LD  5,0(5)	pop frame
* <- call
* <- compound statement
 51:     ST  5,-1(5)	push ofp
 52:    LDA  5,-1(5)	push frame
 53:    LDA  0,1(7)	load ac with ret ptr
 54:    LDA  7,-55(7) 	jump to main loc
 55:     LD  5,0(5)	pop frame
* End of execution.
 56:   HALT  0,0,0	
