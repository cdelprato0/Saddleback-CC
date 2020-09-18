;************************************************************************************
; Name:         Mariah Harris
; Program:      MASM2_0.asm
; Class:        CS 3B Tth 830a
; Lab:          MASM2
; Date:         March 27, 2018 at 830a
; Purpose:
;       This program will input numeric information from the keyboard, perform 
;       addition, multiplication, subtraction, and division, Additionally *no pun 
;       intended (:*, this program will check for overflow upon ALL operations.      
;
;************************************************************************************

    .486                 ;directive to let assembler know we are using the 486 architecture and therefore the 486 instruction set
    .model flat, stdcall ;lets assembler know we are using flat model memory
    .stack 100h          ;defines runtime stack size 4096 elements
    
    include \masm32\include\kernel32.inc
    include \masm32\include\masm32.inc
    includelib \masm32\lib\kernel32.lib
    includelib \masm32\lib\masm32.lib
    ;include Irvine32.lib

    ExitProcess PROTO Near32 stdcall, dwExitCode:dword                           ; defines the prototype for the ExitProcess Method
    ascint32	PROTO Near32 stdcall, lpStringOfNumericChars:dword               ; defines prototype for ascint32 method
    intasc32	PROTO Near32 stdcall, lpStringToHold:dword, dval:dword           ; defines prototype for intasc32 method
    putstring 	PROTO Near32 stdcall, lpStringToPrint:dword                      ; defines prototype for putstring method
    getche      PROTO Near32 stdcall                                             ; defines prototype for getche method
    getch       PROTO Near32 stdcall                                             ; defines prototype for getch method
    putch       PROTO Near32 stdcall, bChar:byte                                 ; defines prototype for putch method   
     
.data ;directive that intializes data

strName BYTE 10,9,32, "Name: Mariah Harris",0           ;Intializes strName, formatted output using ASCII values
strProgramName BYTE 10,9,32,32, "Program: MASM2.asm",0  ;Initializes strProgramName, formatted output using ASCII values
strClass BYTE 10,9, "Class: CS 3B",0                    ;Intializes strClass, formatted output using ASCII values
strDate BYTE 10,9,32, "March 29, 2018",0                ;Intializes the strDate, formatted output using ASCII values

inputPrompt1 BYTE 10,9, "Enter your first number: ",0   ;Initializes the user input prompt
inputPrompt2 BYTE 10,9, "Enter your second number: ",0  ;

  strTab  BYTE      "    ",0                          	  ;Used in formatting of a tab console output
  strSpace   BYTE      " ",0                             	  ;Used in formatting of a space to console output
  strThxMssg   BYTE      "Thanks for using my program… :p" ,10,10,0
  strExtraLine BYTE      10,0                             ;Used in formatting of a 
    
    dIntMax         dword 11          ; limit for inputting numeric string
    dCharMax       dword 79          ; limit for inputting alpha-numeric string
    dInCount        dword 0           ; number of character in the bBuffer input buffer
    bInputAr          byte  11 dup(0)   ; Stores the user input (10+1 bytes)

    strFirstInPrompt  BYTE "Enter your first number:  ",0   ; Prompt for first number
    strSecondInPrompt BYTE "Enter your second number: ",0   ; Prompt for second numb

    strInvalidIn    BYTE "INVALID NUMERIC STRING. RE-ENTER VALUE",10,0
    strInOF	          BYTE "OVERFLOW OCCURED. RE-ENTER VALUE",10,0
    strConvOF         BYTE "OVERFLOW OCCURED WHEN CONVERTING",10,0

    strOutSum         BYTE "The sum is ",0                 ; Display sum
    strAddOF	   BYTE "OVERFLOW OCCURED WHEN ADDING",10,0

    strOutSub  BYTE "The difference is ",0          ; Display difference 
    strSubOF	   BYTE "OVERFLOW OCCURED WHEN SUBTRACTING",10,0
    
    strOutMul      BYTE "The product is ",0             ; Display product
    strMulOF      BYTE "OVERFLOW OCCURED WHEN MULTIPLYING",10,0

    strQuotient     BYTE "The quotient is ",0            ; Display quotient
    strRemainder    BYTE "The remainder is ",0           ; Display remainder
    strZeroCode	   BYTE "You cannot divide by 0. Thus, there is no quotient or remainder",10,0
    
    bStreamLimit BYTE 10
    bBackCode         byte  8           ; ASCII value for backspace key 
    bEnterCode        byte 13           ; ASCII value for enter key
    bDeleteCode       byte  20          ; ASCII delete for delete key
    bCurrentInput          byte  0           ; Identifies which input is being utilized (0 - first, 1 - second)
    dOp1             dword ?           ; Creates space for first user input double word 
    dOp2            dword ?           ; Creates space for second user input double word
    strResult         byte  11 dup(?)   ; Creates space for string storing result of arithmetic operations



.code ; directive that initializes code 

MOV eax, 0
MOV ebx, 0
MOV ecx, 0
MOV edx, 0

UserInput PROC

    MOV ebx, 0              ; Resets EBX register
    ;MOV ecx, 10             --TOO SMALL, USE 11 to append null
    MOV ecx, 11             ; Intializes loop counter to size of input array string (10+1)
    MOV dInCount, 0         ; Initializes user input char count to zero 

inputRefresh:                ; Refreshes input 
    ;MOV edx, ecx            ---- Messes up values ; use EBX instead
    MOV ebx, ecx             ; Stores value of loop counter in ebx
    SUB ebx, 1               ; *** Decrements ebx
    MOV bInputAr[bx], 0      ; Resets individual bits of user input vals beginning w LSB
    loop inputRefresh        ; Repeat FOR ecx > 0
    
inputChar:    
    MOV eax, 0              ; Resets EAX register 
    MOV edx, 0              ; Resets EDX register
    CALL getch              ; Gets user input char, stores in AL

    ;CMP al, 8               ; Compares user input char w ASCII val for backspace
    CMP al, bBackCode        ; *** Compares user input char w ASCII val for backspace
    je L1                    ; Places address of L1 in EIP

    ;CMP al, 13
    CMP al, bEnterCode      ; ** Compares user input char w ASCII val for enter 
    je exitInput            ; Places address of exitInput in EIP

    MOV edx, dInCount       ; Stores the number of chars input in the edx register 
    ;CMP edx, bStreamLimit   ;*** EDX == buffer limit - 1 (10 bytes)
    CMP edx, 10             ; EDX == buffer limit - 1 (10 bytes) ?
    jae UserInput           ;**IF user input >= 10 (max size), go back for the next input (dOp2) 
    jmp L0                  ; User input < 10 --- room for more chars; places address of L0 in EIP

L0: ; Case when there is still room for more chars in input Ar
    MOV ebx, dInCount        ; Stores current input val char count in ebx register
    MOV bInputAr[bx], al     ; Stores char into user input val array
    INVOKE putch, al         ; Echoes the char to the command line 
    ADD dInCount, 1          ; ** Increments user input char count 
    jmp inputChar          ; Restarts user input char process

L1: ; Case when user enters backspace char 
    cmp dInCount, 0         ; Checks to see if there are any chars in the input ar stream
    je UserInput            ; IF no chars, then dont want to be able to backspace !! 
    call Backspace          ; ELSE, can backspace
    dec dInCount            ; Need to decrement input char count so accurate value
    jmp UserInput           ; Continue user input process -- Places address of UserInput in EIP

exitInput:
;   .IF(bInputAr== 0)   --- Not working 
    cmp bInputAr, 0         ; Ensures user input val array is empty
    je endProgram           ; If empty, end program. 

    ;.ELSE
    ;MOV bInputAr[11], 0    --- OUT OF BOUNDS - use 10 instead
    MOV bInputAr[10], 0      ; Not empty; adds null terminator to the input val array 
    
    ret     ; Pops address in ESP and places it into EIP

UserInput ENDP

;*********************************************************************
; VerifyInput
;           If user entered invalid character: CF set (1)
;           If overflow - OF set(1)
;*********************************************************************

VerifyInput PROC

    ;.IF(CF == 1)
    jc badChar                              ; IF CF set, address of badChar placed in EIP
    ;.IF(OF==1)
    jo isOF                                 ; IF OF set, address of isOF placed in EIP
    
    jmp leaveVerify                         ; Input is valid; places address of leaveVerify in EIP

badChar:
    INVOKE putstring, ADDR strInvalidIn     ;Prints bad char error message to console output
    jmp decideJmp                           ;Places address of decideJmp in EIP

;INVOKE putstring, ADDR strInOF

isOF:
    INVOKE putstring, addr strInOF          ;Prints overflow error message to console output 

leaveVerify:
    ;.IF(bCurrentInput = 0)
    cmp bCurrentInput, 0                 ; Verifies if first or second user input 
    je inputL1                           ; Places address of inputL1 in EIP

    ;.ELSE(bCurrentInput = 1)
    jmp inputL2                          ; Places address of inputL2 in EIP

convOk:
    ret                                  ;Pops value of ESP into EIP. 

VerifyInput ENDP



Backspace PROC
    INVOKE putch, 8     ;Echoes ASCII value 8
    INVOKE putch, 32
    INVOKE putch, 8
    ret ;Pops address in ESP and places it into EIP
Backspace ENDP

;main:   -- Dont need this 

_start:

    MOV eax, 0                                      ; Resets EAX register 
    MOV ebx, 0                                      ; Resets EBX register
    MOV ecx, 0                                      ; Resets ECX register
    MOV edx, 0                                      ; Resets EDX register  

    INVOKE putstring, ADDR strName          ;uses putstring function to display name as output on command line
    INVOKE putstring, ADDR strProgramName   ;uses putstring function to display class as output on command line
    INVOKE putstring, ADDR strClass         ;uses putstring function to display lab title string as output on command line
    INVOKE putstring, ADDR strDate          ;uses putstring function to display the date string as output on command line
    
    INVOKE putstring, ADDR strExtraLine        ;Adds extra line to seperate header from input prompt
 

InputProcess:

InputL1:
    INVOKE putstring, ADDR strFirstInPrompt         ; Prompts user for first input val
    INVOKE putstring, ADDR strExtraLine             ; Outputs extra line to console after input prompt
    CALL UserInput                                  ; Calls method that stores user input char val
    INVOKE ascint32, ADDR bInputAr                  ; Converts user input char to int value; stores result in eax
    MOV bCurrentInput, 0
    CALL VerifyInput                                ; Verifies user input and stores within eax
    MOV dOp1, eax                                   ;Stores verified user input result into dOp1    

 InputL2:    
    INVOKE putstring, ADDR strSecondInPrompt        ; Prompts user for second input val
    INVOKE putstring, ADDR strExtraLine             ; Outputs extra line to console after input prompt
    CALL UserInput                                  ; Calls method that stores user input char val
    INVOKE ascint32, ADDR bInputAr                  ; Converts user input char to int value; stores result in eax
    MOV bCurrentInput, 1
    CALL VerifyInput                                ; Verifies user input and stores within eax
    MOV dOp2, eax                                   ; Stores verified user input result into dOp2
               
endProgram:
    INVOKE putstring, ADDR strExtraLine             ; Outputs extra line to console
    INVOKE putstring, ADDR strExtraLine             ; Outputs extra line to console
    ;INVOKE putstring, ADDR strExtraLine
    INVOKE putstring, ADDR strThxMssg               ; Outputs closing program message
    INVOKE putstring, ADDR strExtraLine             ; Outputs extra line to console

   INVOKE ExitProcess, 0

end _start                                          ; Ends program



