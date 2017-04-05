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
* allocating global var: y
* <- vardecl
* processing function: gcd
* jump around function body here
 12:     ST  0,-1(5)	store return
* -> compound statement
* -> if
* -> op
* -> id
* looking up id: v
 14:     LD  0,-3(5)	load id value
* <- id
* -> constant
 15:    LDC  0,0(0)	load const
* <- constant
* if: jump to else belongs here
* -> return
* -> id
* looking up id: u
 17:     LD  0,-2(5)	load id value
* <- id
 18:     LD  7,-1(5)	return to caller
* <- return
* if: jump to end belongs here
 16:    JEQ  0,3(7) 	if: jmp to else
* -> return
* -> call of function gcd
* -> id
* looking up id: v
 20:     LD  0,-3(5)	load id value
* <- id
 21:     ST  0,-4(5)	push ofp
* -> op
* -> id
* looking up id: u
 22:     LD  0,-2(5)	load id value
* <- id
* -> op
* -> op
* -> id
* looking up id: u
 23:     LD  0,-2(5)	load id value
* <- id
* -> id
* looking up id: v
 24:     LD  0,-3(5)	load id value
* <- id
* -> id
* looking up id: v
 25:     LD  0,-3(5)	load id value
* <- id
 26:     ST  0,-5(5)	push ofp
 27:     ST  5,-4(5)	push ofp
 28:    LDA  5,-2(5)	push frame
 29:    LDA  0,1(7)	load ac with ret ptr
 30:    LDA  7,5(7)	jump to fun loc
 31:     LD  5,0(5)	pop frame
* <- call
 32:     LD  7,-1(5)	return to caller
* <- return
 19:    LDA  7,13(7) 	jmp to end
* <-
* <- compound statement
* processing function: main
* jump around function body here
 34:     ST  0,-1(5)	store return
* -> compound statement
* processing local var: x
* -> assign
* -> id
* looking up id: x
 36:    LDA  0,-5(5)	load id address
* <- id
 37:     ST  0,-3(5)	assign: push left
* -> call of function input
 38:     ST  5,-6(5)	push ofp
 39:    LDA  5,-4(5)	push frame
 40:    LDA  0,1(7)	load ac with ret ptr
 41:    LDA  7,5(7)	jump to fun loc
 42:     LD  5,0(5)	pop frame
* <- call
 43:     LD  1,-3(5)	assign: load left
 44:     ST  0,0(1)	assign: store value
* <- assign
* -> assign
* -> id
* looking up id: y
 45:    LDA  0,-2(5)	load id address
* <- id
 46:     ST  0,-3(5)	assign: push left
* -> constant
 47:    LDC  0,10(0)	load const
* <- constant
 48:     LD  1,-3(5)	assign: load left
 49:     ST  0,0(1)	assign: store value
* <- assign
* -> call of function gcd
 50:     ST  0,-5(5)	push ofp
 51:     ST  5,-5(5)	push ofp
 52:    LDA  5,-3(5)	push frame
 53:    LDA  0,1(7)	load ac with ret ptr
 54:    LDA  7,5(7)	jump to fun loc
 55:     LD  5,0(5)	pop frame
* <- call
* <- compound statement
 56:     ST  5,-3(5)	push ofp
 57:    LDA  5,-3(5)	push frame
 58:    LDA  0,1(7)	load ac with ret ptr
 59:    LDA  7,-60(7) 	jump to main loc
 60:     LD  5,0(5)	pop frame
* End of execution.
 61:   HALT  0,0,0	
