;**********************************************************************************************************
; Program Name: MASM 5
; Programmer:   Chaz Del Prato & Chase Deric
; Class:        CS3B T/Th 3:30pm
; Date:         April 30, 2018
; Purpose:
;   For this assignment, you are to write C++ code that sorts the 200,000 integers from the attached 
;   numbers.dat  using the C++ (pseudocode on p. 374) and Assembly language (p. 375) versions of the bubble 
;   sort algorithm. DO NOT use any other form of sort from any other source!. It is important that the 
;   logic be identical to that shown on p. 374 of our text.  Store the resulting numbers in a files 
;   respective to the language that sorted them (e.g. bubbleSortC.dat, and bubbleSortA.dat).
;**********************************************************************************************************  

;Copied from book

.586
.model flat,C
BubbleSort PROTO,
	pArray:PTR DWORD, Count:DWORD	

.code

BubbleSort PROC USES eax ecx esi,
pArray:PTR DWORD,		 ; pointer to int array
Count:DWORD			     ; size of given array

mov ecx,Count
dec ecx			 	        ; decrement count by 1

L1:	push ecx			     ; save outer loop count
	mov	esi,pArray	         ; point to first value

L2:	mov	eax,[esi]		     ; get array value
	cmp	[esi+4],eax        	 ; compare a pair of values
	jg	L3			         ; if [esi] <= [edi], don't exch
	xchg eax,[esi+4]	     ; exchange the pair
	mov	[esi],eax

L3:	add	esi,4		         ; move both pointers forward
	loop	L2			     ; inner loop

    pop	ecx			    	     ; retrieve outer loop count
    loop L1			        	 ; else repeat outer loop

L4: 
    ret

BubbleSort ENDP

END