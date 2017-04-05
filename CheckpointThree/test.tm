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
* -> return
 14:     LD  7,-1(5)	return to caller
* <- return
* <- compound statement
 15:     ST  5,-2(5)	push ofp
 16:    LDA  5,-2(5)	push frame
 17:    LDA  0,1(7)	load ac with ret ptr
 18:    LDA  7,-19(7) 	jump to main loc
 19:     LD  5,0(5)	pop frame
* End of execution.
 20:   HALT  0,0,0	
