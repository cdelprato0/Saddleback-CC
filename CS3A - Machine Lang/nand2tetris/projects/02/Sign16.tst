// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/02/Sign16.tst

// File created by Matthew Walsh.

load Sign16.hdl,
output-file Sign16.out,
compare-to Sign16.cmp,
output-list in%B1.16.1 out%B1.1.1;

// Set 01.
set in %B0000000000000000,
eval,
output;

// Set 02.
set in %B1111111111111111,
eval,
output;

// Set 03.
set in %B0000000011111111,
eval,
output;

// Set 04.
set in %B1111111100000000,
eval,
output;

// Set 05.
set in %B0000111100001111,
eval,
output;

// Set 06.
set in %B1111000011110000,
eval,
output;

// Set 07.
set in %B0011001100110011,
eval,
output;

// Set 08.
set in %B1100110011001100,
eval,
output;

// Set 09.
set in %B0101010101010101,
eval,
output;

// Set 10.
set in %B1010101010101010,
eval,
output;
