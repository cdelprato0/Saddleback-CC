@echo off

:: Set Project Name
set projectName=BubbleSort

:: Assemble 
\masm32\bin\ml /c /Zd /coff %projectName%.asm

:: LINK Irvine
\masm32\bin\Link /SUBSYSTEM:CONSOLE /ENTRY:BubbleSort /out:%projectName%.exe %projectName%.obj ^
..\..\Irvine\Kernel32.lib ^
..\..\Irvine\Irvine32.lib ^
..\..\Irvine\User32.lib

\MinGW\bin\gcc -std=c++11 -c -m32 -o main.obj masm5.cpp
\MinGW\bin\g++ -m32 -o output.exe %projectName%.obj main.obj

:: Delete object files
del %projectName%.obj
del main.obj

:: RUN
output.exe