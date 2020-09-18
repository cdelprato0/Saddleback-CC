// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input. 
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel. When no key is pressed, the
// program clears the screen, i.e. writes "white" in every pixel.

(START)
        @8192   //Number of pixels in the screen for the CPUEmulator
        D=A	//Sets the contents of the A register (8192) to the D register

        @Counter
        M=D     //Sets the D register (8192) to the M register
(LOOP)
        @Pixels //Initializes variable to zero
        M=0     
(INNER)
        @KBD	//Sets the value of the keyboard (24576)
        D=M

        @WHITE	//The screen goes to WHITE if the keyboard value is zero
        D;JEQ   
(BLACK)
        @Pixels //Sets the M register contents into the D register
        D=M

        @SCREEN //Adds the number of Pixels plus the value of SCREEN (16384)
        A=A+D   
        M=-1    //Will fill the screen with black pixels

        @END
        0;JMP   //Will jump to the END
(WHITE)
        @Pixels //Sets the M register contents into tje D register
        D=M

        @SCREEN //Adds the number of Pixels plus the value of SCREEN (16384)
        A=A+D   
        M=0     //Will fill the screen with white pixels

(END)   
        @Pixels //Will increment the number of pixels by 1 and set it to the M register
        D=M+1  
	M=D

        @Counter //WIll subtract the D register minus the M regsiter
        D=D-M

        @LOOP    //Will go the begining of the LOOP if Counter minus Pixels is equal to zero
        D;JEQ   

        @INNER   //Will jump the begining of INNER
        0;JMP   
