;**********************************************************************************************************
; Program Name: MASM 3 - StringFunctions
; Programmer:   Chaz Del Prato
; Class:        CS3B T/Th 3:30pm
; Date:         April 17, 2018
; Purpose:
;   
;**********************************************************************************************************    

    INCLUDE ..\..\Irvine\Irvine32.inc   

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
   
String_Length PROC Near32

x_param EQU [ebp + 8]

    push ebp
    mov ebp, esp

    push EBX                ;saves all registers
    push ESI

    mov ebx, x_param        ;ebx 1st string
    mov esi, 0              ;esi indexes into the strings

beginWhile:
    cmp BYTE PTR[ebx + esi],0   ;reached end of the string
    je endWhile                 ;exit loop
    inc esi
    jmp beginWhile
endWhile:

    mov EAX, ESI
    pop ESI
    pop EBX

    pop ebp     ;restores

    ret 4        ;cleans up stack

String_Length ENDP

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


String_Copy PROC Near32

    push ebp
    mov ebp, esp

    sub esp, 4
    len1 equ DWORD PTR[ebp-4]
    
    push ebx
    push esi
    push edi

    MOV ESI, [EBP + 8]
    push esi
    call String_Length
    MOV len1, EAX
    inc len1

    INVOKE memoryallocBailey, len1

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
    add esp, 4
    pop edi
    pop esi
    pop ebx
    
    pop ebp

    ret 4

String_Copy ENDP

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

StringContains PROC

    push ebp                    
    mov ebp, esp

    push ebx                    
    push ecx
    push edx
    push esi

    sub esp, 8                 
    string1Len equ [ebp-4]
    string2Len equ [ebp-8]

    string1 equ [ebp+12]        
    string2 equ [ebp+8]

    push string1                
    call String_length
    mov string1Len, eax
    push string2
    call String_length
    mov string2Len, eax

    .IF(string1Len < eax)
        mov al, 0
        jmp quit
    .ENDIF
    
    dec eax
    mov string2Len, eax        

    mov esi, 0                 
    mov ecx, 0                
    mov ebx, string1
    mov edx, string2
L1:
    .IF(esi == string1Len)
        mov al, 0
        jmp quit
    .ENDIF
    mov al, [ebx+esi]
    or al, 00100000b            
    mov ah, [edx+ecx]
    or ah, 00100000b           
    .IF(al != ah)
        inc esi
        mov ecx, 0
    .ELSEIF(ecx == string2Len)
        mov al, 1
        jmp quit
    .ELSE
        inc esi
        inc ecx
    .ENDIF
    jmp L1
quit:
    add esp, 8
    pop esi
    pop edx
    pop ecx
    pop ebx
    pop ebp
    ret 8
StringContains ENDP

END