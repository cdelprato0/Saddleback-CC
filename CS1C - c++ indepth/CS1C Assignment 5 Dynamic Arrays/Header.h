/**************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #5:Dynamic Arrays
 * CLASS	    :CS1C
 * SECTION	    :M/W 2:00 PM
 *************************************************************************/

#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

//Holds the values for the inventory
struct Inventory
{
	string name;
	float price;
	int quantity;
};

//Holds the values for marks purchases
struct MarksPurchase
{
	string soldName;
	float soldPrice;
	int soldQuantity;
};

//Prints out the header to the console
void PrintHeader(string asName, char asType, int asNum);

#endif /* HEADER_H_ */
