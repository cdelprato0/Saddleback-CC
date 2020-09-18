;**********************************************************************************************************
; Program Name: MASM 3
; Programmer:   Chaz Del Prato
; Class:        CS3B T/Th 3:30pm
; Date:         April 17, 2018
; Purpose:
;   The purpose of this program is to be able to connect a driver with different external files and run
;   methods across muitple files. The driver will consist of mutiple string options that will modify
;   two user enters strings. All methos are hand written and does not use any predefined string methods.
;**********************************************************************************************************    

    INCLUDE ..\..\Irvine\Irvine32.inc   

;Bailey Macros
    ascint32         PROTO Near32 stdcall, lpStringToConvert:dword
    ExitProcess      PROTO,dwExitCode:dword
    getstring        PROTO Near32 stdcall, lpStringToGet:dword, dlength:dword
    hexToChar        PROTO Near32 stdcall, lpDestStr:dword, lpSourceStr:dword, dLen:dword
    intasc32         PROTO Near32 stdcall, lpStringToHold:dword, dval:dword
    putstring        PROTO Near32 stdcall, lpStringToPrint:dword
    putch            PROTO Near32 stdcall, bVal:byte

;External file methods
    EXTERN String_Length@0:Near32
    EXTERN String_Equals@0:Near32
    EXTERN String_EqualsIgnoreCase@0:Near32
    EXTERN String_Copy@0:Near32
    EXTERN String_CharAt@0:Near32
    EXTERN String_Substring1@0:Near32
    EXTERN String_Substring2@0:Near32
    EXTERN String_StartsWith1@0:Near32
    EXTERN String_StartsWith2@0:Near32
    EXTERN String_EndsWith@0:Near32

;Sets the external file name to the first given name
    String_Length      EQU String_Length@0
    String_Equals      EQU String_Equals@0
    String_EqualsIC    EQU String_EqualsIgnoreCase@0
    String_Copy        EQU String_Copy@0
    String_CharAt      EQU String_CharAt@0
    String_Substring1  EQU String_Substring1@0
    String_Substring2  EQU String_SubString2@0
    String_StartsWith1 EQU String_StartsWith1@0
    String_StartsWith2 EQU String_StartsWith2@0
    String_EndsWith    EQU String_EndsWith@0
    
    .data

strDriverHeader       BYTE "***************************************************",10,
                           "*                     MASM 3                       *",10,
                           "* ------------------------------------------------ *",10,0

strSetString1         BYTE "* <1> Set string1                         ",0
strSetString2         BYTE "* <2> Set string2                         ",0
strString_length      BYTE "* <3> String_length                       ",0
strString_equals      BYTE "* <4> String_equals                       ",0
strString_equalsIgn   BYTE "* <5> String_equalsIgnoreCase             ",0
strString_copy        BYTE "* <6> String_copy                         ",0
strString_substring1  BYTE "* <7> String_substring_1                  ",0
strString_substring2  BYTE "* <8> String_substring_2                  ",0
strString_charAt      BYTE "* <9> String_charAt                       ",0
strString_startsWith1 BYTE "* <10> String_startsWith_1                ",0
strString_startsWith2 BYTE "* <11> String_startsWith_2                ",0
strString_endsWith    BYTE "* <12> String_endsWith                    ",0
strString_indexOf1    BYTE "* <13> String_indexOf_1                   ",0
strString_indexOf2    BYTE "* <14> String_indexOf_2                   ",0
strString_indexOf3    BYTE "* <15> String_indexOf_3                   ",0
strString_lastIndex1  BYTE "* <16> String_lastIndexOf_1               ",0
strString_lastIndex2  BYTE "* <17> String_lastIndexOf_2               ",0
strString_lastIndex3  BYTE "* <18> String_lastIndexOf_3               ",0
strString_concate     BYTE "* <19> String_concate                     ",0
strString_replace     BYTE "* <20> String_replace                     ",0
strString_toLower     BYTE "* <21> String_toLowerCase                 ",0
strString_toUpper     BYTE "* <22> String_toUpperCase                 ",0
strQuit               BYTE "* <23> Quit                                       *",10,
                           "***************************************************",0

strUserPrompt         BYTE "Choice (1-23): ",0
bUserChoice           BYTE 2 DUP(?)

strString1Prompt      BYTE "Enter String 1: ",0
strString2Prompt      BYTE "Enter String 2: ",0
strStringLengthPrompt BYTE "Choose a string to get the length of ( 1 or 2 ): ",0
strSubstringFirst     BYTE "Enter the beggining index: ",0
strSubstringLast      BYte "Enter the last index: ",0
strIndexPrompt        BYTE "Enter an index within string 1: ",0
strOffsetPrompt       BYTE "Enter the offset: ",0

strCurrently BYTE "currently:",0

strUserString1 BYTE "NULL", 21 DUP(?)
strUserString2 BYTE "NULL", 21 DUP(?)
strCopyString  BYTE "NULL", 21 DUP(?)
strSubstring1  BYTE "NULL", 21 DUP(?)
strSubstring2  BYTE "NULL",0
strCharAt      BYTE ?
strNull        BYTE "NULL",0

strStringLength BYTE "0",0
bOffset         BYTE ?

bEqualsTF       BYTE 0
bEqualsIgnoreTF BYTE 0
bStartsWith1TF  BYTE 0
bStartsWith2TF  BYTE 0
bEndsWithTF     BYTE 0
strTrue         BYTE "TRUE",0
strFalse        BYTE "FALSE",0

dCopyHex       DWORD 00000000h
dSubStringHex1 DWORD 00000000h
dSubStringHex2 DWORD 00000000h

strReturn BYTE 10,0     ;Used for cleaning up the output into the console
    
    .code

;***********************************************************************************************
; Name: main
;
; Purpose:
;   The purpose of the main is to execute a continuous menu that can take in mutiple inputs 
;   until the user descided to quit. The main will change the color of the console text.
;   It will then take in user input and determine the selection and call the appropriate string
;   modifier. 
;***********************************************************************************************
main PROC   
    ;Sets the color of the console to green
    MOV EAX, green
    call SetTextColor

driver: 
    call Clrscr                     ;Clears the console screen
    call DisplayDriver              ;Display the driver menu

promptSelection:

    ;Will Prompt the user to chose a number 1-23 and will jump the requested string function
    cmp EAX, 1
    je setString1

    cmp EAX, 2
    je setString2

    cmp EAX, 3
    je stringLength

    cmp EAX, 4
    je stringEquals

    cmp EAX, 5
    je stringEqualsIgnore

    cmp EAX, 6
    je stringCopy

    cmp EAX, 7
    je substring1

    cmp EAX, 8
    je substring2

    cmp EAX, 9
    je stringCharAt

    cmp EAX, 10
    je stringStartsWith1

    cmp EAX, 11
    je stringStartsWith2

    cmp EAX, 12
    je stringEndsWith

    cmp EAX, 23
    je quit

;-/-/
setString1:
    call Clrscr                                 ;Clears the console screen
    INVOKE putstring, ADDR strString1Prompt     ;Prompt the user for the first string
    INVOKE getstring, ADDR strUserString1, 25   ;Reads in the users input
    
    jmp driver                                  ;Redisplays the driver menu

;-/-/
setString2:
    call Clrscr                                 ;Clears the console screen
    INVOKE putstring, ADDR strString2Prompt     ;Prompt the user for the second string
    INVOKE getstring, ADDR strUserString2, 25   ;Reads in the users input
    
    jmp driver                                  ;Redisplays the driver menu

;-/-/
stringLength:
    call Clrscr                                 ;Clears the console screen
    INVOKE putstring, ADDR strStringLengthPrompt;Prompts the user the select a string for the length
    INVOKE getstring, ADDR bUserChoice, 1       ;Reads in the users input
    INVOKE ascint32, ADDR bUserChoice           ;Converts the users input to an integer

    ;Checks to see what string the user wants to look at
    cmp EAX, 1
    je length1
    cmp EAX, 2
    je length2

length1:
    push OFFSET strUserString1                  ;Pushes the contents of string1 onto the stack
    jmp getLength                               
    
length2:
    push OFFSET strUserString2                  ;Pushes the contents of string2 onto the stack

getLength:
    call String_Length                          ;Calls the string length function in the external file
    INVOKE intasc32, ADDR strStringLength, EAX  ;Converts the integer to an ascii character
    
    jmp driver

;-/-/
stringEquals:
    push OFFSET strUserString1                  ;Pushes the contents of string1 onto the stack
    push OFFSET strUserString2                  ;Pushes the contents of string2 onto the stack
    call String_Equals                          ;Calls the string equals function in the external file
    MOV bEqualsTF, AL                           ;Saves the result of string equals into a variable
    
    jmp driver

;-/-/
stringEqualsIgnore:
    push OFFSET strUserString1                  ;Pushes the contents of string1 onto the stack
    push OFFSET strUserString2                  ;Pushes the contents of string2 onto the stack
    call String_EqualsIC                        ;Calls the string equals ignore case function in the external file
    MOV bEqualsIgnoreTF, AL                     ;Saves the result of string equals ignore case into a variable
    
    jmp driver

;-/-/ 
stringCopy:
    push OFFSET strUserString1                  ;Pushes the contents of string2 onto the stack
    call String_Copy                            ;Calls the string copy function in the external file
    MOV dCopyHex, EAX                           ;Saves the result of string copy hex address into a variable
    
    jmp driver
    
;-/-/
substring1: 
    push OFFSET strUserString1                  ;Pushes the contents of string1 onto the stack

    INVOKE putstring, ADDR strSubstringFirst    ;Prompts the user the select a the first index of the string
    INVOKE getstring, ADDR bUserChoice, 2       ;Reads in the users input
    INVOKE ascint32, ADDR bUserChoice           ;Converts the users input to an integer
    MOV EBX, EAX                                ;Saves EAX into EBX so that EAX will not be lost

    INVOKE putstring, ADDR strReturn            ;Prompts the user the select the last index of the string
    INVOKE putstring, ADDR strSubstringLast     ;Reads in the users input
    INVOKE getstring, ADDR bUserChoice, 2       ;Converts the users input to an integer
    INVOKE ascint32, ADDR bUserChoice
    
    push EBX                                    ;Pushes EBX onto the stack
    push EAX                                    ;Pushes EAX onto the stack
    call String_Substring1                      ;Calls the substring function in the external file
    MOV dSubStringHex1, EAX                     ;Saves the result of substring hex address into a variable

    jmp driver
    
;-/-/
substring2:
    push OFFSET strUserString1                  ;Pushes the contents of string1 onto the stack

    INVOKE putstring, ADDR strSubstringFirst    ;Prompts the user the select a the first index of the string
    INVOKE getstring, ADDR bUserChoice, 2       ;Reads in the users input
    INVOKE ascint32, ADDR bUserChoice           ;Converts the users input to an integer                          
        
    push EAX                                    ;Pushes EAX onto the stack
    call String_Substring2                      ;Calls the substring function in the external file
    MOV dSubStringHex2, EAX                     ;Saves the result of substring hex address into a variable

    jmp driver
    
;-/-/
stringCharAt:
    INVOKE putstring, ADDR strIndexPrompt       ;Prompts the user to choose an index to start at
    INVOKE getstring, ADDR bUserChoice, 2       ;Reads in the users input
    INVOKE ascint32,  ADDR bUserChoice          ;Converts the users input to an integer 

    push OFFSET strUserString1                  ;Pushes the contents of string 1 to the stack
    push EAX                                    ;Puhses eax to the stack
    call String_CharAt                          ;Calls the char at function in the external file
    MOV strCharAt, AL                           ;Saves the result of char at into a variable
    
    jmp driver
    
;-/-/
stringStartsWith1:
    INVOKE putstring, ADDR strOffsetPrompt      ;Prompts the user to set an offset 
    INVOKE getstring, ADDR bOffset, 2           ;Reads in the users input
    INVOKE ascint32, ADDR bOffset               ;Converts the users input to an integer 

    push OFFSET strUserString1                  ;Pushes the contents of string 1 to the stack
    push OFFSET strUserString2                  ;Pushes the contents of string 2 to the stack
    push EAX                                    ;Pushes eax to the stack
    call String_StartsWith1                     ;Calls the starts with function in the external file
    MOV bStartsWith1TF, AL                      ;Saves the result of starts with into a variable
    
    jmp driver
    
;-/-/
stringStartsWith2:
    push OFFSET strUserString1                  ;Pushes the contents of string 1 to the stack
    push OFFSET strUserString2                  ;Pushes the contents of string 2 to the stack                  
    call String_StartsWith2                     ;Calls the starts with function in the external file      
    MOV bStartsWith2TF, AL                      ;Saves the result of starts with into a variable
    
    jmp driver
    
;-/-/
stringEndsWith:
    push OFFSET strUserString1                  ;Pushes the contents of string 1 to the stack
    push OFFSET strUserString2                  ;Pushes the contents of string 2 to the stack 
    call String_EndsWith                        ;Calls the starts with function in the external file 
    MOV bEndsWithTF, AL                         ;;Saves the result of ends with into a variable

    jmp driver
    
;-/-/
quit:
      INVOKE ExitProcess, 0   ;Exit command

main ENDP

;***********************************************************************************************
; Name: DisplayDriver
;
; Purpose:
;   The display driver will display the driver menu to the console window. It will be able
;   to update itself so that the most accurate info in provied on the console screen.
;***********************************************************************************************
DisplayDriver PROC

    INVOKE putstring, ADDR strDriverHeader      ;Prints the top of the driver

;--Set String 1 - 1
    INVOKE putstring, ADDR strSetString1
    INVOKE putstring, ADDR strCurrently
    INVOKE putstring, ADDR strUserString1
    INVOKE putstring, ADDR strReturn            ;Prints a newline

;--Set String 2 - 2
    INVOKE putstring, ADDR strSetString2
    INVOKE putstring, ADDR strCurrently
    INVOKE putstring, ADDR strUserString2
    INVOKE putstring, ADDR strReturn            ;Prints a newline

;--String Length - 3
    INVOKE putstring, ADDR strString_length
    INVOKE putstring, ADDR strCurrently
    INVOKE putstring, ADDR strStringLength
    INVOKE putstring, ADDR strReturn            ;Prints a newline

;--String equals
    INVOKE putstring, ADDR strString_equals
    INVOKE putstring, ADDR strCurrently
    call EqualsTF
    INVOKE putstring, ADDR strReturn            ;Prints a newline

;--String equals ignoring the case
    INVOKE putstring, ADDR strString_equalsIgn
    INVOKE putstring, ADDR strCurrently
    call EqualsIgnoringTF
    INVOKE putstring, ADDR strReturn            ;Prints a newline

;--String copy
    INVOKE putstring, ADDR strString_copy
    call CopyHex
    INVOKE putstring, ADDR strReturn            ;Prints a newline

;--String substring 1
    INVOKE putstring, ADDR strString_substring1
    call SubStringHex1
    INVOKE putstring, ADDR strReturn            ;Prints a newline

;--String substring 2
    INVOKE putstring, ADDR strString_substring2
    call SubStringHex2
    INVOKE putstring, ADDR strReturn            ;Prints a newline

;--String char at
    INVOKE putstring, ADDR strString_charAt
    call CharAt
    INVOKE putstring, ADDR strReturn            ;Prints a newline

;--String starts with 1
    INVOKE putstring, ADDR strString_startsWith1
    INVOKE putstring, ADDR strCurrently
    call StartsWith1TF
    INVOKE putstring, ADDR strReturn            ;Prints a newline

;--String starts with 2
    INVOKE putstring, ADDR strString_startsWith2
    INVOKE putstring, ADDR strCurrently
    call StartsWith2TF
    INVOKE putstring, ADDR strReturn            ;Prints a newline

;--String ends with
    INVOKE putstring, ADDR strString_endsWith
    INVOKE putstring, ADDR strCurrently
    call EndsWithTF
    INVOKE putstring, ADDR strReturn            ;Prints a newline

;String index of 1
    INVOKE putstring, ADDR strString_indexOf1
    INVOKE putstring, ADDR strCurrently
    INVOKE putstring, ADDR strReturn            ;Prints a newline

;String index of 2
    INVOKE putstring, ADDR strString_indexOf2
    INVOKE putstring, ADDR strCurrently
    INVOKE putstring, ADDR strReturn            ;Prints a newline

;String index of 3
    INVOKE putstring, ADDR strString_indexOf3
    INVOKE putstring, ADDR strCurrently
    INVOKE putstring, ADDR strReturn            ;Prints a newline

;String last index of 1
    INVOKE putstring, ADDR strString_lastIndex1
    INVOKE putstring, ADDR strCurrently
    INVOKE putstring, ADDR strReturn            ;Prints a newline

;String last index of 2
    INVOKE putstring, ADDR strString_lastIndex2
    INVOKE putstring, ADDR strCurrently
    INVOKE putstring, ADDR strReturn            ;Prints a newline

;String last index of 3
    INVOKE putstring, ADDR strString_lastIndex3
    INVOKE putstring, ADDR strCurrently
    INVOKE putstring, ADDR strReturn            ;Prints a newline

;String concate
    INVOKE putstring, ADDR strString_concate
    INVOKE putstring, ADDR strCurrently
    INVOKE putstring, ADDR strReturn            ;Prints a newline

;String replace
    INVOKE putstring, ADDR strString_replace
    INVOKE putstring, ADDR strCurrently
    INVOKE putstring, ADDR strReturn            ;Prints a newline

;String to lower case
    INVOKE putstring, ADDR strString_toLower
    INVOKE putstring, ADDR strCurrently
    INVOKE putstring, ADDR strReturn            ;Prints a newline

;String to upper case - 22
    INVOKE putstring, ADDR strString_toUpper
    INVOKE putstring, ADDR strCurrently
    INVOKE putstring, ADDR strReturn            ;Prints a newline

;Quits program - 23
    INVOKE putstring, ADDR strQuit
    INVOKE putstring, ADDR strReturn            ;Prints a newline
    
DisplayDriver ENDP


;***********************************************************************************************
; Name: UserChoicePrompt
;
; Purpose:
;   Will prompt the user to select their choice and will save the variable for main to use
;***********************************************************************************************
UserChoicePrompt PROC
    INVOKE putstring, ADDR strUserPrompt
    INVOKE getstring, ADDR bUserChoice, 2
    INVOKE putstring, ADDR strReturn
    
    INVOKE ascint32, ADDR bUserChoice
    ret
UserChoicePrompt ENDP


;***********************************************************************************************
; Name: EqualsTF
;
; Purpose:
;   Will take in the current value in equals and will determine if it means true or false and
;   will output the correct statement on the driver.
;***********************************************************************************************
EqualsTF PROC
    
    MOV DL, bEqualsTF
    cmp DL, 0
    je false1
    cmp DL, 1
    je true1
    
false1:
    INVOKE putstring, ADDR strFalse
    ret

true1:
    INVOKE putstring, ADDR strTrue
    ret

EqualsTF ENDP


;***********************************************************************************************
; Name: EqualsIgnoringTF
;
; Purpose:
;   Will take in the current value in equals and will determine if it means true or false and
;   will output the correct statement on the driver.
;***********************************************************************************************
EqualsIgnoringTF PROC
    
    MOV DL, bEqualsIgnoreTF
    cmp DL, 0
    je false2
    cmp DL, 1
    je true2
    
false2:
    INVOKE putstring, ADDR strFalse
    ret

true2:
    INVOKE putstring, ADDR strTrue
    ret

EqualsIgnoringTF ENDP


;***********************************************************************************************
; Name: CopyHex
;
; Purpose:
;   Will determine the hex value for the copy and will output that to the driver. Also will
;   output the current string that is copied.
;***********************************************************************************************
CopyHex PROC
    INVOKE putch, '&'
    MOV EAX, dCopyHex
    call WriteHex
    INVOKE putch, ' '
    INVOKE putch, ' '
    INVOKE putstring, ADDR strCurrently
    
    cmp EAX,0
    JNE print
    
    INVOKE putstring, ADDR strCopyString
    ret

print:
    INVOKE putstring, EAX
    
    ret

CopyHex ENDP


;***********************************************************************************************
; Name: SubstringHex1
;
; Purpose:
;   Will determine the hex value for the substring and will output that to the driver. Also will
;   output the result of the substring
;***********************************************************************************************
SubstringHex1 PROC
    INVOKE putch, '&'
    MOV EAX, dSubStringHex1
    call WriteHex
    INVOKE putch, ' '
    INVOKE putch, ' '
    INVOKE putstring, ADDR strCurrently

    cmp EAX, 0
    jne output
    
    INVOKE putstring, ADDR strSubstring1
    ret

output:
    INVOKE putstring, EAX

    ret

SubstringHex1 ENDP


;***********************************************************************************************
; Name: SubstringHex2
;
; Purpose:
;   Will determine the hex value for the substring and will output that to the driver. Also will
;   output the result of the substring
;***********************************************************************************************
SubstringHex2 PROC
    INVOKE putch, '&'
    MOV EAX, dSubStringHex2
    call WriteHex
    INVOKE putch, ' '
    INVOKE putch, ' '
    INVOKE putstring, ADDR strCurrently

    cmp EAX, 0
    jne output2
    
    INVOKE putstring, ADDR strSubstring2

    ret

output2:
    INVOKE putstring, EAX
    ret
    
SubstringHex2 ENDP


;***********************************************************************************************
; Name: CharAt
;
; Purpose:
;   Will determine the char at the specfic location in the string and output the character unless
;   it is null, then it will output null
;***********************************************************************************************
CharAt PROC
    INVOKE putstring, ADDR strCurrently
    MOV AL, strCharAt
    cmp AL, 0
    je setNull

    INVOKE putch, strCharAt
    ret

setNull: 
    INVOKE putstring, ADDR strNull
    ret

CharAt ENDP


;***********************************************************************************************
; Name: StartsWith1TF
;
; Purpose:
;   Will take in the current value in startsWith and will determine if it means true or false and
;   will output the correct statement on the driver.
;***********************************************************************************************
StartsWith1TF PROC
    
    MOV DL, bStartsWith1TF
    cmp DL, 0
    je false3
    cmp DL, 1
    je true3
    
false3:
    INVOKE putstring, ADDR strFalse
    ret

true3:
    INVOKE putstring, ADDR strTrue
    ret

StartsWith1TF ENDP


;***********************************************************************************************
; Name: StartsWith2TF
;
; Purpose:
;   Will take in the current value in startsWith and will determine if it means true or false and
;   will output the correct statement on the driver.
;***********************************************************************************************
StartsWith2TF PROC
    
    MOV DL, bStartsWith2TF
    cmp DL, 0
    je false4
    cmp DL, 1
    je true4
    
false4:
    INVOKE putstring, ADDR strFalse
    ret

true4:
    INVOKE putstring, ADDR strTrue
    ret

StartsWith2TF ENDP


;***********************************************************************************************
; Name: EndsWithTF
;
; Purpose:
;   Will determine if the ends with is a true or false that will be displayed in the driver menu
;***********************************************************************************************
EndsWithTF PROC
    
    MOV DL, bEndsWithTF
    cmp DL, 0
    je false5
    cmp DL, 1
    je true5
    
false5:
    INVOKE putstring, ADDR strFalse
    ret

true5:
    INVOKE putstring, ADDR strTrue
    ret

EndsWithTF ENDP

END main