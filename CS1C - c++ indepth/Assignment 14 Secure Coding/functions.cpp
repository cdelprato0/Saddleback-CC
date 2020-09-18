/****************************************************
 * PROGRAMMED BY  : Jason Inciong
 * STUDENT ID     : 386273
 * CLASS          : CS1C --> MW - 2:00PM
 * ASSIGNMENT #14 : Secure Coding
 * DUE DATE	      : 5/23/16
 ****************************************************/

#include "header.h"

void StaticBufferOverRuns() {
	char name[80];
	char outName[9];

	cout << "**********************\n"
		 << "STATIC BUFFER OVERRUNS\n"
		 << "**********************\n";

	cout << "-----------\n"
		 << "Bad Example\n"
		 << "-----------\n";
	cout << "Enter name: " << endl;
	cin >> name;

	//Overwrites the information: wrong
	strcpy( outName, name );
	cout << outName << endl << endl;

	cout << "------------\n"
		 << "Good Example\n"
		 << "------------\n";

	cout << "Enter name: " << endl;
	cin >> name;
	strncpy( outName, name, 10);
	outName[10] = '\0';
	cout << outName << endl << endl;
}

void HeapOverruns() {
	char* charAr;
	int*  arSize;

	arSize = new int;

	cout << "*************\n"
		 << "HEAP OVERRUNS\n"
		 << "*************\n";

	cout << "Enter number larger than 50 " << endl;
	cin >> *arSize;

	charAr = new char[*arSize];

	strcpy(charAr, "TESTING");

	cout << "Number of memory locations allocated was " << *arSize << endl
		 << charAr << endl;

	//memory not fully deleted
	delete arSize;
	delete [ ] charAr;

	cout << "Number of memory location allocated was " << *arSize << endl
		 << charAr << endl << endl;
}

void BoundaryCheck() {
	int intAr[3];

	cout << "************************\n"
		 << "BOUNDARY CHECKING ERRORS\n"
		 << "************************\n\n";

	//no boundary check
	cout << "-----------\n"
		 << "Bad Example\n"
		 << "-----------\n";

	for(int index = 0; index <= 3; index++ )
	{
		cout << "Enter integer: ";
		cin >> intAr[index];
		cout << "Inputted integer is " << intAr[index] << endl << endl;

	}//End FOR

	cout << "------------\n"
		 << "Good Example\n"
		 << "------------\n";

	string myString = "GoodWay";

	//overwrites the string
	//checks bound of string
	myString[15] = 's';

	cout << myString[15] << endl;
}
