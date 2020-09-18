///*******************************************************************************
// * AUTHOR	     : Chaz Del Prato
// * STUDENT ID    : 382108
// * Assignment #14: Secure Coding
// * CLASS	     : CS1C
// * SECTION	     : M/W 2:00 PM
// *******************************************************************************/
//
//#include <iostream>
//#include <cstring>
//using namespace std;
//
//int main()
//{
//
//	int integerArray[3];
//
//	//This is the BAD way to do this. It has no boundary checking
//	cout << "****BAD EXAMPLE****\n\n";
//
//	for ( int index = 0; index <= 3; index++ )
//	{
//		cout << "Please enter an integer: ";
//		cin >> integerArray[index];
//		cout << "The integer just entered was " << integerArray[index] << endl << endl;
//	}//End FOR
//
//	cout << "****GOOD WAY****\n\n";
//
//	string myString = "GoodWay";
//	//Safely overwrites the string and checks the bound of string
//	myString[15] = 's';
//
//	cout << myString[15] << endl;
//
//	return 0;
//}
