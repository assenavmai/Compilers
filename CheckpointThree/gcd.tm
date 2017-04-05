* C-Minus Compilation to TM Code
* File: gcd.tm
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
* processing function: pls
* jump around function body here
 12:     ST  0,-1(5)	store return
* -> compound statement
* processing local var: x
* processing local var: y
* processing local var: z
* -> assign
* -> id
* looking up id: x
 13:    LDA  0,-2(5)	load id address
* <- id
 14:     ST  0,-5(5)	assign: push left
* -> constant
 15:    LDC  0,0(0)	load const
* <- constant
 16:     LD  1,-5(5)	assign: load left
 17:     ST  0,0(1)	assign: store value
* <- assign
* -> assign
* -> id
* looking up id: y
 18:    LDA  0,-3(5)	load id address
* <- id
 19:     ST  0,-5(5)	assign: push left
* -> constant
 20:    LDC  0,3(0)	load const
* <- constant
 21:     LD  1,-5(5)	assign: load left
 22:     ST  0,0(1)	assign: store value
* <- assign
* -> assign
* -> id
* looking up id: z
 23:    LDA  0,-4(5)	load id address
* <- id
 24:     ST  0,-5(5)	assign: push left
* -> constant
 25:    LDC  0,2(0)	load const
* <- constant
 26:     LD  1,-5(5)	assign: load left
 27:     ST  0,0(1)	assign: store value
* <- assign
* -> while
* while: jump after body comes back here
* -> op
* -> id
* looking up id: y
 28:     LD  0,-3(5)	load id value
* <- id
 29:     ST  0,-5(5)	op: push left
* -> constant
 30:    LDC  0,0(0)	load const
* <- constant
 31:     LD  1,-5(5)	op: load left
 32:    SUB  0,1,0	op >
 33:    JGT  0,2(7)	br if true
 34:    LDC  0,0(0)	false case
 35:    LDA  7,1(7)	unconditional jmp
 36:    LDC  0,1(0)	true case
* <- op
* while: jump to end belongs here
* -> compound statement
* -> assign
* -> id
* looking up id: y
 38:    LDA  0,-3(5)	load id address
* <- id
 39:     ST  0,-5(5)	assign: push left
* -> op
* -> id
* looking up id: y
 40:     LD  0,-3(5)	load id value
* <- id
 41:     ST  0,-6(5)	op: push left
* -> constant
 42:    LDC  0,1(0)	load const
* <- constant
 43:     LD  1,-6(5)	op: load left
 44:    SUB  0,1,0	op -
* <- op
 45:     LD  1,-5(5)	assign: load left
 46:     ST  0,0(1)	assign: store value
* <- assign
* -> call of function output
* -> id
* looking up id: y
 47:     LD  0,-3(5)	load id value
* <- id
 48:     ST  0,-7(5)	store arg val
 49:     ST  5,-5(5)	push ofp
 50:    LDA  5,-5(5)	push frame
 51:    LDA  0,1(7)	load ac with ret ptr
 52:    LDA  7,-46(7)	jump to fun loc
 53:     LD  5,0(5)	pop frame
* <- call
* <- compound statement
 54:    LDA  7,-27(7) 	while: absolute jmp to test
 37:    JEQ  0,17(7) 	while: jmp to end
* <- while
* <- compound statement
 55:     LD  7,-1(5)	return to caller
 11:    LDA  7,44(7) 	jump around fn body
* <- fundecl
* processing function: main
* jump around function body here
 57:     ST  0,-1(5)	store return
* -> compound statement
* -> call of function pls
 58:     ST  5,-5(5)	push ofp
 59:    LDA  5,-5(5)	push frame
 60:    LDA  0,1(7)	load ac with ret ptr
 61:    LDA  7,5(7)	jump to fun loc
 62:     LD  5,0(5)	pop frame
* <- call
* <- compound statement
 63:     LD  7,-1(5)	return to caller
 56:    LDA  7,7(7) 	jump around fn body
* <- fundecl
 64:     ST  5,-2(5)	push ofp
 65:    LDA  5,-2(5)	push frame
 66:    LDA  0,1(7)	load ac with ret ptr
 67:    LDA  7,-11(7) 	jump to main loc
 68:     LD  5,0(5)	pop frame
* End of execution.
 69:   HALT  0,0,0	
