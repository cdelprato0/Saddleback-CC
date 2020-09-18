;************************************************************************************
; Program Name: MASM 0.5
; Programmer:   Cesare Del Prato
; Class:        CS3B T/Th 3:30pm
; Date:         Feburay 7, 2018
; Purpose:
;   This
;************************************************************************************

    .486
    .model flat, stdcall
    .stack 100h

    option casemap :none

    .data

;*********************************
; 2,  Symbolic Integer Constants *
;*********************************

three DWORD 12345678h
    .code

main:

;****************************************************************
;  1. Write a sequence of MOV instructions that will exchange the 
;     upper and lower words in a doubleword variable named three. 
;****************************************************************

    MOV AX, WORD PTR three
    MOV BX, WORD PTR three+2
    MOV three, BX
    MOV WORD PTR three+2, AX



    

    ;INVOKE ExitProcess, 0



END main