// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

	@Counter //A counter variable
	M=0	 //Intializing the counter to zero

	@R2      //The result will be stored into R2 or RAM[2]
	M=0      //Intializing R2 to zero
  (LOOP)         //Loop begins
  	@Counter
  	D=M      //Sets D register to the Counter

  	@R0	 //Intializing multiple R0 or RAM[0]
 	D=M-D    //Sets the D register to R0 minus the Counter

  	@END     //End the loop if the D register is ZERO
  	D;JEQ 

  	@R1	 //Intializing multiple R1 or RAM[1]
  	D=M 	 //Sets the D register to R1

  	@R2	 //Stores the result in R2
  	M=D+M 	 //Sets R2 to R1 plus R2

  	@Counter
  	M=M+1 	 //Increments the Counter

  	@LOOP    //Loops again
  	0;JMP

  (END)
  	@END     //Ends multiplyer
  	0;JMP
