/****************************************************
 * PROGRAMMED BY  : Jason Inciong
 * STUDENT ID     : 386273
 * CLASS          : CS1C --> MW - 2:00PM
 * ASSIGNMENT #14 : Secure Coding
 * DUE DATE	      : 5/23/16
 ****************************************************/

#include <iostream>
#include <cstring>
#include "header.h"
using namespace std;

int main(){

	//STATIC BUFFER OVERRUNS
	StaticBufferOverRuns();

	//HEAP OVERRUNS
	HeapOverruns();

	//BOUNDARY CHECKING ERRORS
	BoundaryCheck();

	return 0;
}
