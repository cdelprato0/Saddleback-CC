/**************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #5:Dynamic Arrays
 * CLASS	    :CS1C
 * SECTION	    :M/W 2:00 PM
 *************************************************************************/
#include "Header.h"

/**************************************************************************
 * Assignment 5 - Dynamic arrays
 * ________________________________________________________________________
 * This program will be able to take in a users input and save that input
 * into an array of structs. The array will then output the inventory list
 * to the console. The user will be prompted to fill in what mark had
 * purchased. It will then output a receipt that has the price,quantity,
 * and the name of the product that was sold and also has the tax included
 * into a grand total. The the program will output the inventory after the
 * sale has been made and will show the updated quantities. Arrays are
 * automatically deleted at the end of the program.
 *
 *************************************************************************/
int main()
{
	const float TAX = .0825; //Holds a constant value of tax
	Inventory* array[5];	//Creates an array of structs for inventory
	MarksPurchase* items[4]; //Creates an array of structs for marks
	float sum = 0.0;  //accumulate the sum of items bought
	float total = 0.0; //The grand total plus tax

	//Print function that prints to the console a header that has the name
	//and assignment
	PrintHeader("Dynamic Arrays", 'A', 5);

	//Outputs to the console
	cout << "Please enter the Inventory...\n";

	//Prompts the user and loads the array with the Inventory struct, name
	//price and quantity
	for(int index = 0; index < 5; index++)
	{
		//Dynamically allocates memory for the new array
		array[index] = new Inventory;

		cout << "Enter the Name of the Equipment: ";
		getline(cin, array[index]->name);

		cout << "Enter the Price: ";
		cin >> array[index]->price;
		cin.ignore(1000, '\n');

		cout << "Enter the Quantity: ";
		cin >> array[index]->quantity;
		cin.ignore(1000, '\n');
		cout << endl;
	}//END FOR

	cout << "\nInventory list...\n";

	//Prints the inventory list to the console
	for(int index = 0; index < 5; index++)
	{
		cout << "Equipment Name: " << array[index]->name << endl;
		cout << "Equipment Cost: " << array[index]->price << endl;
		cout << "Equipment Quantity: " << array[index]->quantity << endl
			 << endl;
	}//END FOR

	cout << "\nPlease enter the items sold to Mark...\n";

	//Prompts the user to enter what mark had bought and creates a new array
	//that holds the stuff he buys
	for(int index = 0; index < 4; index++)
	{
		//Dynamically allocates memory for this array of structs
		items[index] = new MarksPurchase;

		cout << "Enter the Name of the Item: ";
		getline(cin, items[index]->soldName);

		cout << "Enter the cost of the Item: ";
		cin >> items[index]->soldPrice;
		cin.ignore(1000, '\n');

		cout << "Enter the Quantity sold: ";
		cin >> items[index]->soldQuantity;
		cin.ignore(1000, '\n');
		cout << endl;
	}//END FOR

	cout << "\nPrinting Receipt...\n";

	//Prints out a receipt that has each item sold, a sub total, and a grand
	//total that has tax included
	for(int index = 0; index < 4; index++)
	{
		cout << "Item # " << (index + 1) << endl
			 << items[index]->soldQuantity << " of "
			 << items[index]->soldName << " @ $" << items[index]->soldPrice
			 << " each.\n";

		//Calculates the sum of all the items
		sum = sum + (items[index]->soldQuantity * items[index]->soldPrice);
		cout << "Sub Total: $" << sum << endl << endl;
	}//END FOR

	//Grand total plus tax
	total = (sum * TAX) + sum;

	cout << "Grand Total: $" << fixed << setprecision(2) << total;

	//Outputs the inventory after the sales have been made
	cout << "\n\nInventory after sales...\n";

	//Hard code of what was subtracted from the previous inventory
	cout << "Equipment Name: " << array[0]->name << endl;
	cout << "Equipment Cost: " << array[0]->price << endl;
	cout << "Equipment Quantity: "
		 << (array[0]->quantity - items[0]->soldQuantity)
		 << endl << endl;
	cout << "Equipment Name: " << array[1]->name << endl;
	cout << "Equipment Cost: " << array[1]->price << endl;
	cout << "Equipment Quantity: "
		 << (array[1]->quantity - items[1]->soldQuantity)
		 << endl << endl;
	cout << "Equipment Name: " << array[2]->name << endl;
	cout << "Equipment Cost: " << array[2]->price << endl;
	cout << "Equipment Quantity: "
		 << (array[2]->quantity - items[3]->soldQuantity)
		 << endl << endl;
	cout << "Equipment Name: " << array[3]->name << endl;
	cout << "Equipment Cost: " << array[3]->price << endl;
	cout << "Equipment Quantity: " << array[3]->quantity
		 << endl << endl;
	cout << "Equipment Name: " << array[4]->name << endl;
	cout << "Equipment Cost: " << array[4]->price << endl;
	cout << "Equipment Quantity: "
		 << (array[4]->quantity - items[2]->soldQuantity)
		 << endl << endl;

	return 0;
}//END PROGRAM
