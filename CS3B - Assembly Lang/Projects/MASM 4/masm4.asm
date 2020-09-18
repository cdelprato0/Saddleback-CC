;**********************************************************************************************************
; Program Name: MASM 4
; Programmer:   Chaz Del Prato & Chase Deric
; Class:        CS3B T/Th 3:30pm
; Date:         April 30, 2018
; Purpose:
;   For this assignment, you will be creating a Menu driver program that serves as a text editor and save 
;   the resulting text to a file. You must be able to enter new strings manually and/or via a file
;   (input.txt). All additions are additive (i.e. i can call 2b 5 x times and 5 copies would be store in 
;   the data structure(e.g. array of strings, or linked list of strings). Use the enclosed file for 
;   possible input. Do not load automatically, only via the menu.
;**********************************************************************************************************    

    ;Includes
    INCLUDE ..\..\Irvine\Irvine32.inc 
    INCLUDE ..\..\Irvine\Macros.inc    
    INCLUDELIB \masm32\lib\kernel32.lib
    INCLUDELIB ..\..\Irvine\User32.lib
    INCLUDELIB ..\..\Irvine\Irvine32.lib

    ;Prototypes
    ascint32         PROTO Near32 stdcall, lpStringToConvert:dword
    ExitProcess      PROTO,dwExitCode:dword
    getstring        PROTO Near32 stdcall, lpStringToGet:dword, dlength:dword
    hexToChar        PROTO Near32 stdcall, lpDestStr:dword, lpSourceStr:dword, dLen:dword
    intasc32         PROTO Near32 stdcall, lpStringToHold:dword, dval:dword
    putstring        PROTO Near32 stdcall, lpStringToPrint:dword
    putch            PROTO Near32 stdcall, bVal:byte
    GetFileSize      PROTO stdcall :DWORD, :DWORD
    OpenClipboard    PROTO stdcall :DWORD
    GetClipboardData PROTO stdcall :DWORD
    GlobalSize       PROTO stdcall :DWORD
    CloseClipboard   PROTO stdcall
    GetProcessHeap   PROTO stdcall

    ;External functions
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
    EXTERN StringContains@0:Near32

    ;External functions new name
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
    StringContains     EQU StringContains@0

    ;Heap
    HEAP_MIN = 2000000
    HEAP_MAX = 400000000

    ;Linked Lis
    LIST_SIZE = 8
    listNode STRUCT
        pointer     DWORD ?
        next        DWORD ?
    listNode ENDS
    

    .data

strDriverHeader   BYTE 9,9,9, "MASM 4 TEXT EDITOR",10,0

strDataConsump    BYTE 9,9, "Data Structure Memory Consumption: ",0

strViewAll        BYTE "<1> View all Strings ",10,10,0
strAddString      BYTE "<2> Add String ",10,9,
                           "<a> from keyboard",10,9,
                           "<b> from File. Static file named input.txt",10,9,
                           "<C> from Clipboard",10,10,0
strDeleteString   BYTE "<3> Delete string. Given an index #, delete the string and de-allocate memory.",10,10,0
strEditString     BYTE "<4> Edit string. Given an index #, replaced old string w/ new string. Allocate/De-allocate as needed.",10,10,0
strSearchString   BYTE "<5> String search. Regardless of case, return all strings that match the substring given.",10,10,0
strSaveFile       BYTE "<6> Save File",10,10,0
strQuit           BYTE "<7> Quit",10,10,0

strBytes        BYTE " bytes",10,0
dDataConsump    DWORD 0
dIndex          DWORD ?

strEnterChoice      BYTE "Please enter a Text Editor option (1-7): ",0
strAddStringInput   BYTE "Add a string from the KEYBOARD (a), or FILE (b), or CLIPBOARD (c): ",0
strAddKeyboard      BYTE "Enter the string to be ADDED: ",0
strInputFileName    BYTE "Please enter the name of the INPUT file (input.txt): ",0
strOutputFileName   BYTE "Please enther the name of the OUTPUT file (output.txt): ",0
strEnterIndex       BYTE "Please enter the INDEX you want to access: ",0
strEditNewString    BYTE "Enter the new string: ",0
strError            BYTE "Error",0
bChoice             BYTE ?


strFileName       BYTE 20 DUP(?)
dFileSize         DWORD ?
dFileBuffer       DWORD ?
dFileHandler      DWORD ?
strInputBuffer    BYTE 512 DUP(?)
dClipboardHandler DWORD ?

heapHandler     HANDLE ?
heapDefault     HANDLE ?

listHead      DWORD ?
listCount     DWORD 0

strReturn BYTE 10,0     ;Used for cleaning up the output into the console
strTab    BYTE "  ",0
strLeftP  BYTE "(",0
strRightP BYTE ")",0
strAdd    BYTE " + ",0
strSub    BYTE " - ",0
strEqual  BYTE "  => ",0
    
    .code
main PROC   
    MOV EAX, lightGreen         ;Sets the color of the console
    call SetTextColor

    INVOKE HeapCreate, 0, HEAP_MIN, HEAP_MAX    ;Creates Heap
    MOV heapHandler, EAX
    MOV listHead, 0

    call GetProcessHeap
    MOV heapDefault, EAX

driver:
    call Clrscr
    call DisplayDriver          ;Displays the menu
    

promptSelection:                ;Jumps to called function

    cmp EAX, 1
    je viewAllStrings

    cmp EAX, 2
    je addString

    cmp EAX, 3
    je deleteString

    cmp EAX, 4
    je editStrings

    cmp EAX, 5
    je searchString

    cmp EAX, 6
    je saveFile

    cmp EAX, 7
    je quit
    jmp error

viewAllStrings:
    call ViewAllStrings     ;Views all strings
    jmp driver

addString:
    INVOKE putstring, ADDR strAddStringInput    
    INVOKE getstring, ADDR bChoice,1            ;Reads in one value
    INVOKE putstring, ADDR strReturn
    INVOKE ascint32, ADDR bChoice
    
    cmp bChoice, 97     ;'a'
    je keyboard
    cmp bChoice, 98     ;'b'
    je file
    cmp bChoice, 99     ;'c'
    je clipboard
    jmp driver

keyboard:
    call AddStringFromKeyboard          ;adds string from keyboard
    jmp driver

file:
    INVOKE putstring, ADDR strInputFileName     ;gets file name
    INVOKE getstring, ADDR strFileName, 512
    call AddFromFile
    jmp driver

clipboard:
    call AddFromClipboard           ;gets string from clipborad
    jmp driver

deleteString:
    INVOKE putstring, ADDR strEnterIndex    ;gets index to delete
    INVOKE getstring, ADDR dIndex, 4
    INVOKE putstring, ADDR strReturn
    INVOKE ascint32, ADDR dIndex


    PUSH EAX                ;pushs the index to stack to be used in function
    call DeleteListNode     ;calls delete string
    jmp driver

editStrings:
    INVOKE putstring, ADDR strEnterIndex        ;gets index of string
    INVOKE getstring, ADDR dIndex, 4
    INVOKE putstring, ADDR strReturn
    INVOKE ascint32, ADDR dIndex
    MOV EBX, EAX

    INVOKE putstring, ADDR strEditNewString
    INVOKE getstring, ADDR strInputBuffer, 512  ;gets new string

    PUSH EBX                                    ;pushs index
    call EditString                             ;calls edit string
    jmp driver

searchString:
    mWrite "Enter the string to be search: "
    INVOKE getstring, ADDR strInputBuffer, 512  ;gets string to be search
    INVOKE putstring, ADDR strReturn

    call SearchList                             ;searches string
    jmp driver

saveFile:
    INVOKE putstring, ADDR strOutputFileName    ;gets name of ouutput file
    INVOKE getstring, ADDR strFileName,20
    call SaveToFile                             ;saves file
    jmp driver


quit:
      INVOKE ExitProcess, 0   ;Exit command

main ENDP

;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
;   Editor Procedures
;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

;***********************************************************************************************
; Name: DisplayDriver
;
; Purpose: Displays the menu for this assignment
;   
;***********************************************************************************************
DisplayDriver PROC

    INVOKE putstring, ADDR strDriverHeader      ;Prints the top of the driver

;--Display memort comsumption
    INVOKE putstring, ADDR strDataConsump       ;prints memeory consumption
    call DataConsumption

;--View All strings
    INVOKE putstring, ADDR strViewAll

;--Add string from keyboard/file
    INVOKE putstring, ADDR strAddString

;--Delete String
    INVOKE putstring, ADDR strDeleteString

;--Edit String
    INVOKE putstring, ADDR strEditString

;--Search String
    INVOKE putstring, ADDR strSearchString

;--Save File
    INVOKE putstring, ADDR strSaveFile

;--Quit
    INVOKE putstring, ADDR strQuit

;--User Prompt
    INVOKE putstring, ADDR strEnterChoice       ;gets user input for text editor selection
    INVOKE getstring, ADDR bChoice,1
    INVOKE putstring, ADDR strReturn
    
    INVOKE ascint32, ADDR bChoice
    ret
DisplayDriver ENDP


;***********************************************************************************************
; Name: DataConsumption
;
; Purpose: displays the total number of bytes in the system
;   
;***********************************************************************************************
DataConsumption PROC
    MOV EAX, dDataConsump
    call WriteDec
    INVOKE putstring, ADDR strBytes

    ret

DataConsumption ENDP

;***********************************************************************************************
; Name: ViewAllStrings
;
; Purpose:  displays all the string in the linked list, with an index number next to it.
;   not working
;   
;***********************************************************************************************
ViewAllStrings PROC
    MOV EBX, listHead       ;saves the head of the list
    MOV EAX, 0
    
loopAll:
    call WriteDec
    mWrite ". "

    inc EAX
    
    MOV EDX, (listNode PTR [EBX]).pointer   ;the string saved in memory gets put into edx
    call WriteString                        ;prints the string
    
    PUSH EAX
    MOV AL, 10                              ;prints a new line
    call WriteChar
    POP EAX
    
    MOV EBX, (listNode PTR [EBX]).next      ;points to the next node in the list

    cmp EBX, 0          ;checks to see if its reached the end of the list
    je allPrinted
    jmp loopAll

allPrinted:
    Call WaitMsg
    ret

ViewAllStrings ENDP

;***********************************************************************************************
; Name: AddStringFromKeyboard
;
; Purpose:  Adds a user inputted string to the list
;   
;***********************************************************************************************
AddStringFromKeyboard PROC
    INVOKE putstring, ADDR strAddKeyboard       ;gets new string
    INVOKE getstring, addr strInputBuffer, 512

    PUSH OFFSET strInputBuffer  ;determines the size of the new string so it can allocate memory
    call String_Length

    MOV strInputBuffer[EAX], 13 ;adds a carraige return at the end
    inc EAX
    MOV strInputBuffer[EAX], 10 ;adds a new line after the carraige return
    inc EAX
    MOV strInputBuffer[EAX], 0  ;add null at the end

    PUSH OFFSET strInputBuffer  ;copies the string into a register
    call String_Copy

    PUSH EAX            
    Call AddNodeToList          ;adds the string to the list

    ret

AddStringFromKeyboard ENDP

;***********************************************************************************************
; Name: AddFromClipboard
;
; Purpose:  adds the contents of your clipboard into the linked list
;   
;***********************************************************************************************
AddFromClipboard PROC

    PUSH EBP                ;adds new stack frame
    MOV EBP, ESP

    INVOKE OpenClipboard, NULL  ;opens up the clipboard
    INVOKE GetClipboardData, 1  ;saves the data saved in the clipbaord

    MOV dClipboardHandler, EAX  ;saves the contents into edx
    MOV EDX, dClipboardHandler
    
    INVOKE putstring, ADDR strReturn
    call WriteString                    ;prints all the strings saved
    INVOKE putstring, ADDR strReturn

    push dClipboardHandler
    call AddFileStringToList        ;adds them into the linked list

    INVOKE CloseClipboard           ;closes the clipboard

    call WaitMsg
    pop ebp
    ret
    
AddFromClipboard ENDP

;***********************************************************************************************
; Name: DeleteListNode
;
; Purpose: deletes a node from the linked list
;   
;***********************************************************************************************
DeleteListNode PROC

    PUSH EBP            ;creates new stack frame
    MOV EBP, ESP

    PUSH EAX
    PUSH EBX
    PUSH ECX 
    PUSH EDX

    MOV EAX, [EBP + 8]      ;the index of the string passed in
    MOV EBX, listHead       ;head of the stack
    MOV ECX, 1              ;counter
    
    cmp EAX, 0              ;checks to see if its the head
    je deleteFirst

deleteLoop:
    MOV EDX, EBX
    MOV EBX, (listNode PTR [EBX]).next  ;loops until it finds the given index
    cmp EAX, ECX
    je delete
    inc ECX
    jmp deleteLoop

delete:
    MOV ECX, (listNode PTR [EBX]).next      ;sets the next pointer to the next node
    MOV (listNode PTR [EDX]).next, ECX  

    PUSH (listNode PTR [EBX]).pointer   ;gets size of string to be deleted
    call String_Length

    inc EAX
    sub dDataConsump, EAX           ;deallcoates memeory
    sub dDataConsump, LIST_SIZE

    INVOKE HeapFree, heapDefault, 0, (listNode PTR [EBX]).pointer   ;deletes off the heap
    INVOKE HeapFree, heapHandler, 0, EBX
    dec listCount
    jmp endDelete

deleteFirst:
    MOV EDX, (listNode PTR [EBX]).next  ;sets the head to the next variable
    MOV listHead, EDX

    PUSH (listNode PTR [EBX]).pointer   ;gets the size of the string
    call String_Length

    inc EAX
    sub dDataConsump, EAX               ;dealloactaes memeory
    sub dDataConsump, LIST_SIZE

    INVOKE HeapFree, heapDefault, 0, (listNode PTR [EBX]).pointer   ;deletes off the heap
    INVOKE HeapFree, heapHandler, 0, EBX
    dec listCount
    jmp endDelete
    
endDelete:
    POP EDX
    POP ECX
    POP EBX
    POP EAX     ;restores registors
    POP EBP
    RET 4

DeleteListNode ENDP

;***********************************************************************************************
; Name: EditString
;
; Purpose: edits a string, input an index and replaces the how string with a new one
;   
;***********************************************************************************************
EditString PROC

    PUSH EBP                ;creates nmew stack frame
    MOV EBP, ESP

    PUSH EAX
    PUSH EBX
    PUSH ECX
    PUSH EDX

    MOV ECX, 0              ;counter
    MOV EBX, listHead       ;saves the head
    MOV EDX, [EBP + 8]      ;index passed in

editLoop:
    cmp ECX, EDX            ;seaches for the index
    je indexFound

    MOV EBX, (listNode PTR [EBX]).next  ;incremenets until it finds it
    inc ECX
    jmp editLoop

indexFound:
    PUSH (listNode PTR [EBX]).pointer   ;gets the length of old strrng
    call String_Length

    inc EAX
    sub dDataConsump, EAX           ;deallocates memeory

    INVOKE HeapFree, heapDefault, 0, (listNode PTR [EBX]).pointer   ;deletes off heap

    PUSH EBX
    PUSH OFFSET strInputBuffer      ;gets lengtrh of new string
    call String_Length

    MOV strInputBuffer[EAX], 13
    inc EAX
    MOV strInputBuffer[EAX], 10     ;adds carraiage return, new line, and null to end of string
    inc EAX
    MOV strInputBuffer[EAX], 0
    inc EAX
    add dDataConsump, EAX           ;allocates memeory

    PUSH OFFSET strInputBuffer      ;copys string into registor
    call String_Copy
    
    POP EBX
    MOV (listNode PTR [EBX]).pointer, EAX   ,saves string into the index

    POP EDX
    POP ECX
    POP EBX
    POP EAX     ;restores registors
    POP EBP
    RET 4

EditString ENDP

;***********************************************************************************************
; Name: SearchList
;
; Purpose: Adds a string node to the linked list. Keyboard user input will be added.
;   
;***********************************************************************************************
SearchList PROC

   MOV EAX, 0
   MOV ECX, 0           ;counter
   MOV EBX, listHead    ;head

searchLoop:
    .IF(ECX == listCount)   ;checks if exists
        jmp endSearch
    .ENDIF

    PUSH EBX
    PUSH ECX
    PUSH (listNode PTR [EBX]).pointer   ;checks to see if the string is contanined in linked list
    PUSH OFFSET strInputBuffer
    call StringContains

    POP ECX
    POP EBX

    .IF(AL == 1)
        MOV EDX, (listNode PTR [EBX]).pointer   ;if it is found, it prints to console the whole string
        call WriteString
        call Crlf
    .ENDIF
        
    MOV EBX, (listNode PTR [EBX]).next ;goes to the next node
    inc ECX
    jmp searchLoop


endSearch:
    call WaitMsg
    ret   
    

SearchList ENDP

;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
;   List Procedures
;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

;***********************************************************************************************
; Name: AddNodeToList
;
; Purpose: Adds a string node to the linked list. Keyboard user input will be added.
;   
;***********************************************************************************************
AddNodeToList PROC

    PUSH EBP
    MOV EBP, ESP        ;new stack fram

    PUSH EBX
    PUSH EDX

    inc listCount               ;Keeps count of the number of nodes in the list

    PUSH [EBP + 8]          ;passes in the4 string and gets the size
    call String_Length
    
    inc EAX
    add EAX, LIST_SIZE      ;alloactes memeory
    add dDataConsump, EAX

    MOV EBX, listHead
    MOV EDX, [EBP + 8]

    cmp EBX, 0      ;checks if head is empty
    je emptyList

    PUSH EBX
    PUSH EDX

    INVOKE HeapAlloc, heapHandler, HEAP_ZERO_MEMORY, LIST_SIZE  ;alloactes on heap

    POP EDX
    POP EBX

listLoop:
    cmp (listNode PTR [EBX]).next, 0    ;checks for a dfree spot ion the linked list
    je endList
    MOV EBX, (listNode PTR [EBX]).next
    jmp listLoop

endList:
    MOV (listNode PTR [EBX]).next, EAX      ;saves the contents into the node
    MOV (listNode PTR [EAX]).pointer, EDX   ;sets the pointers to the right spotrs
    MOV (listNode PTR [EAX]).next, 0
    jmp endProc

emptyList:
    PUSH EBX
    PUSH EDX

    INVOKE HeapAlloc, heapHandler, HEAP_ZERO_MEMORY, LIST_SIZE ;creates a new list

    POP EDX
    POP EBX

    MOV listHead, EAX
    MOV (listNode PTR [EAX]).pointer, EDX   ;saves the contents to the nodes
    MOV (listNode PTR [EAX]).next, 0
    jmp endProc

endProc:
    POP EDX
    POP EBX     ;restores registors
    POP EBP

    ret 4
     
AddNodeToList ENDP

;***********************************************************************************************
; Name: AddFileStringToList
;
; Purpose: Adds a string node to the linked list. From input file, reads one line and adds to list
;   
;***********************************************************************************************
AddFileStringToList PROC

    PUSH EBP
    MOV EBP, ESP            ;creates new stack frame

    PUSH ECX
    PUSH EDX
    PUSH EBX

    MOV EDX, [EBP + 8]          ;the size of the linked list to be created

outLoop:
    MOV ECX, 0          ;counter

inLoop:
    MOV AL, [EDX + ECX]
    MOV strInputBuffer[ECX], AL ;creates the list

    inc ECX

    cmp AL, 13
    je ifReturn
    
    cmp AL, 0
    je ifNull
    jmp inLoop

ifReturn:
    add EDX, ECX            ;sets the index
    inc EDX 

    MOV strInputBuffer[ECX], 10         ;adds a return to the end of the stirng
    MOV strInputBuffer[ECX + 1], 0
    
    PUSH OFFSET strInputBuffer      ;savces string into register
    call String_Copy
    
    PUSH EAX                ;adds it to the linked list
    call AddNodeToList
    jmp outLoop

ifNull:
    add EDX, ECX
    inc EDX 

    MOV strInputBuffer[ECX], 0
    
    PUSH OFFSET strInputBuffer  ;saves string into registor
    call String_Copy
    
    PUSH EAX
    call AddNodeToList      ;adds string to list
    jmp done

done:
    POP EBX
    POP EDX     ;restors registoprs
    POP ECX
    POP EBP

    ret 4

AddFileStringToList ENDP

;@@@@@@@@@
;   File Procedures
;@@@@@@@@@

;***********************************************************************************************
; Name: AddFromFile
;
; Purpose: Will add from an external inputfile, named "input.txt". Will load all of the contents
;            into a linked list
;   not working
;***********************************************************************************************
AddFromFile PROC

    INVOKE CreateFile, addr strFileName, GENERIC_READ, 0, 0,\   ;opens file
           OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0  

    .IF(EAX == -1)
        INVOKE putstring, addr strError
    .ENDIF
           
    MOV dFileHandler, EAX
    INVOKE GetFileSize, EAX, 0      ;gets the size of the file
    inc EAX
    MOV dFileSize, EAX

    INVOKE HeapAlloc, heapHandler, HEAP_ZERO_MEMORY, EAX    ;allocates the heap
    MOV dFileBuffer, EAX

    MOV EDX, EAX
    MOV EAX, dFileHandler
    MOV ECX, dFileSize      ;reads from the file
    call ReadFromFile

    MOV EDX, dFileBuffer
    MOV ECX, dFileSize
    MOV BYTE PTR [EDX + ECX], 0 ;saves the contents

    push dFileBuffer
    call AddFileStringToList    ;adds the string to the list
    
    INVOKE HeapFree, heapHandler, 0, dFileBuffer    ;realloactes

    
    INVOKE CloseHandle, dFileHandler    ;closes input file
    ret
    
AddFromFile ENDP

;***********************************************************************************************
; Name: SaveFile
;
; Purpose: Will save the contents of the linked list to an output.txt file
;   
;***********************************************************************************************
SaveToFile PROC
    MOV EDX, OFFSET strFileName         ;saves the name of the file into EDX
    call CreateOutputFile               ;Creates the output file

    MOV dFileHandler, EAX

    MOV ECX, 0                          ;count
    MOV EBX, listHead                   ;sets the head of the list to ebx
    MOV EDX, listCount                  ;sets the size of list to edx

saveLoop:
    cmp ECX, listCount                  ;until end of list
    je saved
    
    PUSH (listNode PTR [EBX]).pointer   ;gets size of string
    call String_Length

    PUSH ECX                            ;saves counter

;writes the data to the file
    MOV ECX, EAX                    
    MOV EDX, (listNode PTR [EBX]).pointer
    MOV EAX, dFileHandler
    call WriteToFile                

    MOV EBX, (listNode PTR [EBX]).next  ;sets pointer to the next varaible

    POP ECX                             ;restores counter
    inc ECX                             ;incremenets counter
    jmp saveLoop

saved:
    ret
   
SaveToFile ENDP

END main