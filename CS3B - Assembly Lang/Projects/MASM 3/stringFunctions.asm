;**********************************************************************************************************
; Program Name: MASM 3 - StringFunctions
; Programmer:   Chaz Del Prato
; Class:        CS3B T/Th 3:30pm
; Date:         April 17, 2018
; Purpose:
;   The string funtions extenal file.
;**********************************************************************************************************    

    ;Includes Irvine Libaray
    INCLUDE ..\..\Irvine\Irvine32.inc   

    ;Bailey macros
    ascint32         PROTO Near32 stdcall, lpStringToConvert:dword
    ExitProcess      PROTO,dwExitCode:dword
    getstring        PROTO Near32 stdcall, lpStringToGet:dword, dlength:dword
    hexToChar        PROTO Near32 stdcall, lpDestStr:dword, lpSourceStr:dword, dLen:dword
    intasc32Comma    PROTO Near32 stdcall, lpStringToHold:dword, dval:dword
    putstring        PROTO Near32 stdcall, lpStringToPrint:dword
    putch            PROTO Near32 stdcall, bVal:byte
    memoryallocBailey PROTO Near32 stdcall, dSize:dword

    .data

    
    .code

;***********************************************************************************************
; Name: String_Length
;
; Purpose:
;  This method accepts the address of a string and counts the characters in the string, 
;   excluding the NULL character and returns that value as an int (dword) in the EAX register.  
;   Write this method as an “internal” method below your driver. Just after PUBLIC _start  put 
;   the comment block for the method. Then make sure your proc is placed BEFORE your END 
;   statement.  This method will be used for many of the methods below and making it an internal 
;   method will prevent conflicts.
;***********************************************************************************************
String_Length PROC

x_param EQU [ebp + 8]

    push ebp
    mov ebp, esp

    push esi                ;saves all registers
    push ebx

    mov eax, 0
    mov ebx, x_param        ;ebx 1st string
    mov esi, 0              ;esi indexes into the strings

beginWhile:
    cmp BYTE PTR[ebx + esi],0   ;reached end of the string
    je endWhile                 ;exit loop
    inc eax                     ;length++
    inc esi
    jmp beginWhile
endWhile:

    mov EAX, ESI
    pop EBX
    pop ESI

    pop ebp     ;restores

    ret 4        ;cleans up stack

String_Length ENDP

;***********************************************************************************************
; Name: String_Equals
;
; Purpose:
;  This method makes an exact comparison of individual characters in two strings. If any 
;   character in the string in a position is different than the character in the same position 
;   in the other string, the method returns “false” (0  in the AL register). If the length of 
;   the two strings is different, the method also returns “false”. Note that ‘e’ is NOT the 
;   same as ‘E’. Otherwise “true” (1) is returned. The value is returned in the AL register.
;***********************************************************************************************
String_Equals PROC

strString2 EQU [EBP+8]
strString1 EQU [EBP+12]
    push EBP
    mov EBP, ESP

    sLength1 EQU WORD PTR [EBP-2]
    sLength2 EQU WORD PTR [EBP-4]

    sub ESP, 4

    push ESI
    push EDI
    push EBX


    MOV EAX, 0
    MOV ESI, strString1
    push ESI
    call String_Length
    add esp, 4

    MOV sLength1, AX

    MOV EAX, 0
    MOV ESI, strString2
    push ESI
    call String_Length
    add ESP, 4
    MOV sLength2, AX
    MOV AX, 0

    MOV BX, sLength1
    cmp BX, sLength2
    jnz exitRoutine

    MOV EBX, strString1

    MOV EDI, 0

stLoop:
    MOV AL, [EBX+EDI]
    cmp AL, [ESI+EDI]
    jne NotEqual
    cmp AL, 0
    je AreEqual
    inc EDI
    jmp stLoop

NotEqual:
    MOV AX, 0
    jmp ExitRoutine

AreEqual:
    MOV AX, 1

ExitRoutine:
    pop EBX
    pop EDI
    pop ESI

    MOV ESP, EBP

    POP EBP
    
    ret
String_Equals ENDP

;***********************************************************************************************
; Name: String_EqualsIgnoreCase
;
; Purpose:
;  This method makes a comparison of individual characters in two strings ignoring case. If any 
;   character in the string in a position is different than the character in the same position 
;   in the other string, the method returns “false” (0  in the AL register). If the length of 
;   the two strings is different, the method also returns “false”. Note that ‘e’ is the SAME as 
;   ‘E’. The value returned is in the AL register.
;***********************************************************************************************
String_EqualsIgnoreCase PROC

    strString2 EQU [EBP+8]
    strString1 EQU [EBP+12]
    
    push EBP
    MOV EBP, ESP

    sLength1 EQU WORD PTR [EBP - 2]
    sLength2 EQU WORD PTR [EBP - 4]
    sub ESP, 4

    push ESI
    push EDI
    push EBX

    MOV EAX, 0
    MOV EBX, strString1
    push EBX
    call String_Length
    add ESP, 4
    MOV sLength1, AX
    MOV EAX, 0
    
    MOV ESI, strString2
    push ESI
    call String_Length
    add ESP, 4
    MOV sLength2, AX
    MOV AX, 0
    
    MOV CX, sLength1
    cmp CX, sLength2
    jnz exitRoutineIC

    MOV EDI, 0
    MOV EDX, 0

stLoopIC:
    MOV AL, [EBX + EDI]
    OR AL, 00100000b
    
    MOV Cl, [ESI+EDI]
    OR CL, 00100000b
    
    cmp AL, CL
    jne NotEqualIC
    cmp AL, 00100000b
    je AreEqualIC
    inc EDI
    jmp stLoopIC

NotEqualIC:
    MOV AX, 0
    jmp ExitRoutineIC

AreEqualIC:
    MOV AX, 1

ExitRoutineIC:
    pop EBX
    pop EDI
    pop ESI

    MOV ESP, EBP

    POP EBP
    
    ret
String_EqualsIgnoreCase ENDP

;***********************************************************************************************
; Name: String_Copy
;
; Purpose:
;  This method accepts a string to copy, allocates dynamically enough storage to hold a copy of 
;   the new characters, copies the characters and returns the address of that newly created 
;   string. You will need to INVOKE the  memoryallocBailey method, the UML for which is below. 
;   I have written this method: you only have to PROTOtype it and INVOKE it.
;***********************************************************************************************
String_Copy PROC Near32

    push ebp
    mov ebp, esp

    push ebx
    push esi
    push edi

    MOV ESI, [EBP + 8]
    push esi
    call String_Length
    MOV DWORD PTR[EBP - 4], EAX
    inc DWORD PTR[EBP - 4]

    INVOKE memoryallocBailey, DWORD PTR[EBP - 4]

    MOV EDI, EAX
    MOV EBX, 0

copy:
    MOV AL, [ESI + EBX]
    cmp AL, 0
    je copied

    MOV [EDI + EBX], AL
    inc EBX
    jmp copy

copied:
    mov BYTE PTR[EDI + EBX], 0

    MOV EAX, EDI
    pop edi
    pop esi
    pop ebx
    
    pop ebp

    ret 4

String_Copy ENDP

;***********************************************************************************************
; Name: String_Substring1
;
; Purpose:
;  This method creates a new string consisting of characters from a substring of the passed 
;   string starting with beginIndex and ending with endIndex.
;***********************************************************************************************
String_Substring1 PROC
    push EBP
    MOV EBP, ESP

    sub ESP, 4
    sLength1 EQU [EBP - 4]

    push EBX
    push ECX
    push EDX
    push ESI
    push EDI
    
    strString1 EQU [EBP + 16]
    strFirst1 EQU [EBP + 12]
    strLast1 EQU [EBP + 8]

    MOV EBX, strString1
    MOV ECX, strFirst1
    MOV EDX, strLast1

    push strString1
    call String_Length
    MOV sLength1, EAX

    MOV ESI, strLast1
    sub ESI, strFirst1
    inc ESI
    INVOKE memoryallocBailey, ESI
    MOV EDI, EAX
    MOV ESI, 0

loopSubstring1:
    add ESI, strFirst1
    MOV AL, [EBX + ESI]
    
    cmp ESI, strLast1
    je endLoop
    
    sub ESI, strFirst1
    MOV [EDI + ESI], AL
    inc ESI
    
    jmp loopSubstring1

endLoop:
    MOV BYTE PTR[EDI + ESI], 0
    MOV EAX, EDI
    
    pop EDI
    pop ESI
    pop EDX
    pop ECX
    pop EBX
    add ESP, 4
    pop EBP

    ret 12
    
String_Substring1 ENDP

;***********************************************************************************************
; Name: String_Substring2
;
; Purpose:
;  This method creates a new string consisting of characters from a substring of the passed 
;   string starting with beginIndex to the end of the original string.
;***********************************************************************************************
String_Substring2 PROC
    push EBP
    MOV EBP, ESP

    sub ESP, 4
    sLength1 EQU [EBP - 4]

    push EBX
    push ECX
    push ESI
    push EDI
    
    strString1 EQU [EBP + 12]
    strFirst1 EQU [EBP + 8]

    MOV EBX, strString1
    MOV ECX, strFirst1

    push strString1
    call String_Length
    MOV sLength1, EAX

    MOV ESI, sLength1
    sub ESI, strFirst1
    inc ESI
    INVOKE memoryallocBailey, ESI
    MOV EDI, EAX
    MOV ESI, 0

loopSubstring2:
    add ESI, strFirst1
    MOV AL, [EBX + ESI]
    
    cmp ESI, sLength1
    je endLoop2
    
    sub ESI, strFirst1
    MOV [EDI + ESI], AL
    inc ESI
    
    jmp loopSubstring2

endLoop2:
    MOV BYTE PTR[EDI + ESI], 0
    MOV EAX, EDI
    
    pop EDI
    pop ESI
    pop ECX
    pop EBX
    add ESP, 4
    pop EBP

    ret 8
    
String_Substring2 ENDP

;***********************************************************************************************
; Name: String_CharAt
;
; Purpose:
;  This method returns the character in the indicated position. If the request is impossible to 
;   fulfill, the method returns 0
;***********************************************************************************************
String_CharAt PROC

    push EBP
    MOV EBP, ESP

    push EBX
    push ECX
    push [EBP + 12]

    call String_Length

    cmp EAX, 0
    je noStringOrDone

    MOV EAX, 0
    MOV EBX, [EBP + 12]
    MOV ECX, [EBP + 8]
    MOV AL, [EBX + ECX]

noStringOrDone:
    pop ECX
    pop EBX
    pop EBP
    ret 8

String_CharAt ENDP

;***********************************************************************************************
; Name: String_StartsWith1
;
; Purpose:
;  It checks whether the substring (starting from the specified offset index) exists within 
;   string1. For example testing the string “George Washington” for the prefix “Wash” starting 
;   in position 7 would return “true” (1) otherwise, it would return false (0) would have is 
;   having the specified prefix or not.
;***********************************************************************************************
String_StartsWith1 PROC
    push EBP
    MOV EBP, ESP

    push EBX
    push ECX
    push EDX
    push ESI
    push [EBP + 12]

    call String_Length
    mov [EBP - 8], EAX      

    push [EBP + 16]
    call String_Length
    MOV [EBP - 4], EAX

    MOV EAX, [EBP - 8]

    MOV EBX, [EBP + 8]
    MOV ECX, 0
    MOV EDX, [EBP + 16]
    MOV ESI, [EBP + 12]

loopCheckSW:
    MOV AL, [EDX + EBX]
    MOV AH, [ESI + ECX]
    
    cmp AH, 0
    je trueSW1
    cmp AL, AH
    jne falseSW1
    
    inc EBX
    inc ECX
    jmp loopCheckSW

trueSW1: 
    MOV AL, 1
    jmp done

falseSW1:
    MOV AL, 0
    jmp done

done:
    pop ESI
    pop EDX
    pop ECX
    pop EBX
    pop EBP

    ret 12
String_StartsWith1 ENDP

;***********************************************************************************************
; Name: String_StartsWith2
;
; Purpose:
;  It tests whether string1 begins with the specified prefix. If yes then it returns true else false.
;***********************************************************************************************
String_StartsWith2 PROC
    push EBP
    MOV EBP, ESP

    push EBX
    push ECX
    push EDX
    
    push [EBP + 8]
    call String_Length
    mov [EBP - 8], EAX      

    push [EBP + 12]
    call String_Length
    MOV [EBP - 4], EAX

    MOV EAX, [EBP - 8]
    MOV EBX, 0
    MOV ECX, [EBP + 8]
    MOV EDX, [EBP + 12]

loopCheckSW2:
    MOV AL, [EDX + EBX]
    MOV AH, [ECX + EBX]
    
    cmp AH, 0
    je trueSW2
    cmp AL, AH
    jne falseSW2
    
    inc EBX
    jmp loopCheckSW2

trueSW2: 
    MOV AL, 1
    jmp doneSW2

falseSW2:
    MOV AL, 0
    jmp doneSW2

doneSW2:
    pop EDX
    pop ECX
    pop EBX
    pop EBP

    ret 8
String_StartsWith2 ENDP

;***********************************************************************************************
; Name: String_EndsWith
;
; Purpose:
;  Checks whether the string ends with the specified suffix.
;***********************************************************************************************
String_EndsWith PROC
    push EBP
    MOV EBP, ESP

    push EBX
    push ECX
    push EDX
    push ESI

    push [EBP + 8]
    call String_Length
    MOV [EBP - 8], EAX

    push [EBP + 12]
    call String_Length
    MOV [EBP - 4], EAX

    MOV EAX, [EBP - 8]
    MOV EBX, [EBP - 4]
    SUB EBX, [EBP - 8]
    MOV ECX, 0
    MOV ESI, [EBP + 12]
    MOV EDX, [EBP + 8]

loopEndsWith:
    MOV AL, [ESI + EBX]
    MOV AH, [EDX + ECX]
    
    cmp AH, 0
    je trueEW
    cmp AL, AH
    jne falseEW

    inc EBX
    inc ECX
    jmp loopEndsWith

trueEW:
    MOV AL, 1
    jmp doneEW

falseEW:
    MOV AL, 0
    jmp doneEW

doneEW:
    pop ESI
    pop EDX
    pop ECX
    pop EBX
    pop EBP

    ret 8
String_EndsWith ENDP

END