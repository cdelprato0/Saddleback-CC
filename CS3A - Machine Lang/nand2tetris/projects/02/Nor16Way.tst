// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/02/Nor16Way.tst

// File created by Matthew Walsh & gve

load Nor16Way.hdl,
output-file Nor16Way.out,
compare-to Nor16Way.cmp,
output-list in%B1.16.1 out%B1.1.1;

// Set 01.
set in %B0000000000000000,
eval,
output;

// Set 02.
set in %B0000000000000001,
eval,
output;

// Set 03.
set in %B0000000000000010,
eval,
output;

// Set 04.
set in %B0000000000000100,
eval,
output;

// Set 05.
set in %B0000000000001000,
eval,
output;

// Set 06.
set in %B0000000000010000,
eval,
output;

// Set 07.
set in %B0000000000100000,
eval,
output;

// Set 08.
set in %B0000000001000000,
eval,
output;

// Set 09.
set in %B0000000010000000,
eval,
output;

// Set 10.
set in %B0000000100000000,
eval,
output;

// Set 11.
set in %B0000001000000000,
eval,
output;

// Set 12.
set in %B0000010000000000,
eval,
output;

// Set 13.
set in %B0000100000000000,
eval,
output;

// Set 14.
set in %B0001000000000000,
eval,
output;

// Set 15.
set in %B0010000000000000,
eval,
output;

// Set 16.
set in %B0100000000000000,
eval,
output;

// Set 17.
set in %B1000000000000000,
eval,
output;

// Set 18.
set in %B1111111111111111,
eval,
output;

// Set 19.
set in %B0000000011111111,
eval,
output;

// Set 20.
set in %B1111111100000000,
eval,
output;