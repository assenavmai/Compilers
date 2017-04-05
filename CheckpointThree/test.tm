* C-Minus Compilation to TM Code
* File: test.tm
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
* allocating global var: x
* <- vardecl
* processing function: main
* jump around function body here
 12:     ST  0,-1(5)	store return
* -> compound statement
* processing local var: x
* -> assign
* -> id
* looking up id: x
 13:    LDA  0,-2(5)	load id address
* <- id
 14:     ST  0,-3(5)	assign: push left
* -> constant
 15:    LDC  0,1(0)	load const
* <- constant
 16:     LD  1,-3(5)	assign: load left
 17:     ST  0,0(1)	assign: store value
* <- assign
* -> if
* -> op
* -> id
* looking up id: x
 18:     LD  0,-2(5)	load id value
* <- id
 19:     ST  0,-3(5)	op: push left
* -> constant
 20:    LDC  0,1(0)	load const
* <- constant
 21:     LD  1,-3(5)	op: load left
 22:    SUB  0,1,0	op ==
 23:    JEQ  0,2(7)	br if true
 24:    LDC  0,0(0)	false case
 25:    LDA  7,1(7)	unconditional jmp
 26:    LDC  0,1(0)	true case
* <- op
* if: jump to else belongs here
* -> assign
* -> id
* looking up id: x
 28:    LDA  0,-2(5)	load id address
* <- id
 29:     ST  0,-3(5)	assign: push left
* -> constant
 30:    LDC  0,2(0)	load const
* <- constant
 31:     LD  1,-3(5)	assign: load left
 32:     ST  0,0(1)	assign: store value
* <- assign
* if: jump to end belongs here
 27:    JEQ  0,6(7) 	if: jmp to else
 33:    LDA  7,0(7) 	jmp to end
* <- if
* <- compound statement
 34:     LD  7,-1(5)	return to caller
 11:    LDA  0,13(0)	jump around fn body
* <- fundecl
 35:     ST  5,-2(5)	push ofp
 36:    LDA  5,-2(5)	push frame
 37:    LDA  0,1(7)	load ac with ret ptr
 38:    LDA  7,-39(7) 	jump to main loc
 39:     LD  5,0(5)	pop frame
* End of execution.
 40:   HALT  0,0,0	
