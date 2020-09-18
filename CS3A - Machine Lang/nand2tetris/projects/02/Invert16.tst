// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/02/Invert16.tst

// File created by Matthew Walsh.

load Invert16.hdl,
output-file Invert16.out,
compare-to Invert16.cmp,
output-list in%B1.16.1 invert%B1.1.1 out%B1.16.1;

// Set 01.
set in %B0000000000000000,
set invert 0,
eval,
output;

// Set 02.
set in %B0000000000000000,
set invert 1,
eval,
output;

// Set 03.
set in %B1111111111111111,
set invert 0,
eval,
output;

// Set 04.
set in %B1111111111111111,
set invert 1,
eval,
output;

// Set 05.
set in %B0000000011111111,
set invert 0;
eval,
output;

// Set 06.
set in %B0000000011111111,
set invert 1;
eval,
output;

// Set 07.
set in %B1111111100000000,
set invert 0;
eval,
output;

// Set 08.
set in %B1111111100000000,
set invert 1;
eval,
output;

// Set 09.
set in %B0000111100001111,
set invert 0;
eval,
output;

// Set 10.
set in %B0000111100001111,
set invert 1;
eval,
output;

// Set 11.
set in %B1111000011110000,
set invert 0;
eval,
output;

// Set 12.
set in %B1111000011110000,
set invert 1;
eval,
output;

// Set 13.
set in %B0011001100110011,
set invert 0;
eval,
output;

// Set 14.
set in %B0011001100110011,
set invert 1;
eval,
output;

// Set 15.
set in %B1100110011001100,
set invert 0;
eval,
output;

// Set 16.
set in %B1100110011001100,
set invert 1;
eval,
output;

// Set 17.
set in %B0101010101010101,
set invert 0;
eval,
output;

// Set 18.
set in %B0101010101010101,
set invert 1;
eval,
output;

// Set 19.
set in %B1010101010101010,
set invert 0;
eval,
output;

// Set 20.
set in %B1010101010101010,
set invert 1;
eval,
output;
