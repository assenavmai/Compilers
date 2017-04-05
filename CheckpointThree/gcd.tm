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
* param
* param
* -> compound statement
* -> if
* -> op
* -> id
* looking up id: v
 13:     LD  0,-3(5)	load id value
* <- id
 14:     ST  0,-4(5)	op: push left
* -> constant
 15:    LDC  0,0(0)	load const
* <- constant
 16:     LD  1,-4(5)	op: load left
 17:    SUB  0,1,0	op ==
 18:    JEQ  0,2(7)	br if true
 19:    LDC  0,0(0)	false case
 20:    LDA  7,1(7)	unconditional jmp
 21:    LDC  0,1(0)	true case
* <- op
* if: jump to else belongs here
* -> return
* -> id
* looking up id: u
 23:     LD  0,-2(5)	load id value
* <- id
 24:     LD  7,-1(5)	return to caller
* <- return
* if: jump to end belongs here
 22:    JEQ  0,3(7) 	if: jmp to else
* -> return
* -> call of function gcd
* -> id
* looking up id: v
 26:     LD  0,-3(5)	load id value
* <- id
 27:     ST  0,-6(5)	store arg val
* -> op
* -> id
* looking up id: u
 28:     LD  0,-2(5)	load id value
* <- id
 29:     ST  0,-4(5)	op: push left
* -> op
* -> op
* -> id
* looking up id: u
 30:     LD  0,-2(5)	load id value
* <- id
 31:     ST  0,-5(5)	op: push left
* -> id
* looking up id: v
 32:     LD  0,-3(5)	load id value
* <- id
 33:     LD  1,-5(5)	op: load left
 34:    DIV  0,1,0	op /
* <- op
 35:     ST  0,-5(5)	op: push left
* -> id
* looking up id: v
 36:     LD  0,-3(5)	load id value
* <- id
 37:     LD  1,-5(5)	op: load left
 38:    MUL  0,1,0	op *
* <- op
 39:     LD  1,-4(5)	op: load left
 40:    SUB  0,1,0	op -
* <- op
 41:     ST  0,-7(5)	store arg val
 42:     ST  5,-4(5)	push ofp
 43:    LDA  5,-4(5)	push frame
 44:    LDA  0,1(7)	load ac with ret ptr
 45:    LDA  7,4(7)	jump to fun loc
 46:     LD  5,0(5)	pop frame
* <- call
 47:     LD  7,-1(5)	return to caller
* <- return
 25:    LDA  7,22(7) 	jmp to end
* <- if
* <- compound statement
 11:    LDA  7,36(7) 	jump around fn body
* <- fundecl
* processing function: main
* jump around function body here
 49:     ST  0,-1(5)	store return
* -> compound statement
* processing local var: x
* -> assign
* -> id
* looking up id: x
 50:    LDA  0,-5(5)	load id address
* <- id
 51:     ST  0,-5(5)	assign: push left
* -> call of function input
 52:     ST  5,-6(5)	push ofp
 53:    LDA  5,-6(5)	push frame
 54:    LDA  0,1(7)	load ac with ret ptr
 55:    LDA  7,-52(7)	jump to fun loc
 56:     LD  5,0(5)	pop frame
* <- call
 57:     LD  1,-5(5)	assign: load left
 58:     ST  0,0(1)	assign: store value
* <- assign
* -> assign
* -> id
* looking up id: y
 59:    LDA  0,-2(5)	load id address
* <- id
 60:     ST  0,-5(5)	assign: push left
* -> constant
 61:    LDC  0,10(0)	load const
* <- constant
 62:     LD  1,-5(5)	assign: load left
 63:     ST  0,0(1)	assign: store value
* <- assign
* -> call of function gcd
 64:     ST  0,-7(5)	store arg val
 65:     ST  5,-5(5)	push ofp
 66:    LDA  5,-5(5)	push frame
 67:    LDA  0,1(7)	load ac with ret ptr
 68:    LDA  7,4(7)	jump to fun loc
 69:     LD  5,0(5)	pop frame
* <- call
* <- compound statement
 48:    LDA  7,21(7) 	jump around fn body
* <- fundecl
 70:     ST  5,-3(5)	push ofp
 71:    LDA  5,-3(5)	push frame
 72:    LDA  0,1(7)	load ac with ret ptr
 73:    LDA  7,-25(7) 	jump to main loc
 74:     LD  5,0(5)	pop frame
* End of execution.
 75:   HALT  0,0,0	
