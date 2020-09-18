// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/02/Buf16.tst

// File created by Matthew Walsh.

load Buf16.hdl,
output-file Buf16.out,
compare-to Buf16.cmp,
output-list in%B1.16.1 out%B1.16.1;

// Set 01.
set in %B0000000000000000,
eval,
output;

// Set 02.
set in %B0000000000000001,
eval,
output;

// Set 03.
set in %B0000000000000011,
eval,
output;

// Set 04.
set in %B0000000000000111,
eval,
output;

// Set 05.
set in %B0000000000001111,
eval,
output;

// Set 06.
set in %B0000000000011111,
eval,
output;

// Set 07.
set in %B0000000000111111,
eval,
output;

// Set 08.
set in %B0000000001111111,
eval,
output;

// Set 09.
set in %B0000000011111111,
eval,
output;

// Set 10.
set in %B0000000111111111,
eval,
output;

// Set 11.
set in %B0000001111111111,
eval,
output;

// Set 12.
set in %B0000011111111111,
eval,
output;

// Set 13.
set in %B0000111111111111,
eval,
output;

// Set 14.
set in %B0001111111111111,
eval,
output;

// Set 15.
set in %B0011111111111111,
eval,
output;

// Set 16.
set in %B0111111111111111,
eval,
output;

// Set 17.
set in %B1111111111111111,
eval,
output;

// Set 18.
set in %B1111111100000000,
eval,
output;

// Set 19.
set in %B0000000011111111,
eval,
output;

// Set 20.
set in %B1111000011110000,
eval,
output;

// Set 21.
set in %B0000111100001111,
eval,
output;

// Set 22.
set in %B1100110011001100,
eval,
output;

// Set 23.
set in %B0011001100110011,
eval,
output;

// Set 24.
set in %B1010101010101010,
eval,
output;

// Set 25.
set in %B0101010101010101,
eval,
output;