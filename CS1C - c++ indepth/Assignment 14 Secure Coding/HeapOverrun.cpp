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
//int main(){
//
//	char* characterArray;
//	int*  arraySize;
//
//	arraySize= new int;
//
//	cout << "Please enter number larger than 50 " << endl;
//	cin >> *arraySize;
//
//	characterArray = new char[*arraySize];
//
//	strcpy(characterArray, "TESTING");
//
//	cout << "Number of memory locations allocated was " << *arraySize << endl
//		 << characterArray << endl;
//
//	//The memory is deleted but it still can be reached!!
//	delete arraySize;
//	delete [ ] characterArray;
//
//	cout << "Number of memory location allocated was " << *arraySize << endl
//		 << characterArray << endl;
//	return 0;
//}
