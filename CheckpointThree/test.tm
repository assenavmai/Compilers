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
* processing function: addthree
* jump around function body here
 12:     ST  0,-1(5)	store return
* param
* param
* param
* -> compound statement
* processing local var: result
* -> assign
* -> id
* looking up id: result
 13:    LDA  0,-5(5)	load id address
* <- id
 14:     ST  0,-6(5)	assign: push left
* -> op
* -> op
* -> id
* looking up id: a
 15:     LD  0,-2(5)	load id value
* <- id
 16:     ST  0,-7(5)	op: push left
* -> id
* looking up id: b
 17:     LD  0,-3(5)	load id value
* <- id
 18:     LD  1,-7(5)	op: load left
 19:    ADD  0,1,0	op +
* <- op
 20:     ST  0,-7(5)	op: push left
* -> id
* looking up id: c
 21:     LD  0,-4(5)	load id value
* <- id
 22:     LD  1,-7(5)	op: load left
 23:    ADD  0,1,0	op +
* <- op
 24:     LD  1,-6(5)	assign: load left
 25:     ST  0,0(1)	assign: store value
* <- assign
* -> return
* -> id
* looking up id: result
 26:     LD  0,-5(5)	load id value
* <- id
 27:     LD  7,-1(5)	return to caller
* <- return
* <- compound statement
 11:    LDA  7,16(7) 	jump around fn body
* <- fundecl
* processing function: main
* jump around function body here
 29:     ST  0,-1(5)	store return
* -> compound statement
* -> call of function gcd
 30:     ST  0,-8(5)	store arg val
 31:     ST  5,-6(5)	push ofp
 32:    LDA  5,-6(5)	push frame
 33:    LDA  0,1(7)	load ac with ret ptr
 34:    LDA  7,-5000(7)	jump to fun loc
 35:     LD  5,0(5)	pop frame
* <- call
* -> call of function addthree
 36:     ST  0,-8(5)	store arg val
 37:     ST  5,-6(5)	push ofp
 38:    LDA  5,-6(5)	push frame
 39:    LDA  0,1(7)	load ac with ret ptr
 40:    LDA  7,6(7)	jump to fun loc
 41:     LD  5,0(5)	pop frame
* <- call
* <- compound statement
 28:    LDA  7,13(7) 	jump around fn body
* <- fundecl
 42:     ST  5,-2(5)	push ofp
 43:    LDA  5,-2(5)	push frame
 44:    LDA  0,1(7)	load ac with ret ptr
 45:    LDA  7,-17(7) 	jump to main loc
 46:     LD  5,0(5)	pop frame
* End of execution.
 47:   HALT  0,0,0	
