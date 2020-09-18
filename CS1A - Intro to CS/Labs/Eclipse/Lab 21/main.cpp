/*/************************************************************************
 * PROGRAMMED BY: Lucas  & BBC
 * CLASS		: CS1A
 * SECTION		: MW 9:30a
 * Lab #21		: Intro to Functions
 *************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

int AddTwoInts(int num1, int num2);
int MultiplyTwoInts(int num1, int num2);
int FindLargest(int num1, int num2);
float AverageTwoInts(float num1, float num2);

int main()
{
	// This is the header that will display in the output
	const char PROGRAMMER[30] = "Lucas & BBC";
	const char CLASS[5] = "CS1A";
	const char SECTION[25] = "MW: 9:30AM";
	const int LAB_NUM = 21;
	const char LAB_NAME[40] = "Intro to Functions";

	cout << left;
	cout << "*************************************";
	cout << "\n* PROGRAMMED BY : " << PROGRAMMER;
	cout << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	cout << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	cout << "\n* LAB#" << setw(10) << LAB_NUM << ": " << LAB_NAME;
	cout << "\n*************************************\n\n";
	cout << right;

/**************************************************************************
 *OUTPUT - Sum, Product, Largest, Average.
 *________________________________________________________________________
 *This program utilizes four functions to determine the sum, product, average
 *and largest of two integers provided by the user.
 *	______________________________________________________________________
 *	INPUT:
 *		num1  	   	: User's first integer.
 *		num2    	: User's second integer.
 *
 *	OUTPUT:
 *		The output will be the two integers evaluated by each of the functions
 *		created - AddTwoInts, MulitplyTwoInts, FindLargest, AverageTwoInts.
 *
 *************************************************************************/

	int num1;			//The first of two integers provided by the user.
	int num2;			//The second of two integers provided by the user.

	// Prompt the user for the first value.
	cout << left;
	cout << setw(26) << "Enter the first integer:";
	cin >> num1;
	cin.ignore (1000, '\n');

	// While loop to provide a loop exit if first integer is -999.
	while(num1 != -999)
	{

	// Second integer is retrieved from the user.
		cout << setw(26) << "Enter the second integer:";
		cin >> num2;
		cin.ignore (1000, '\n');
		cout << endl;

	// The program calls upon the functions defined at the bottom to calculate
	// the sum, product, largest, and average of the two integers provided.
		cout << right;
		cout << "The SUM is:" << setw(11) << AddTwoInts(num1, num2);
		cout << endl;
		cout << "The PRODUCT is:" << setw(7) << MultiplyTwoInts(num1, num2);
		cout << endl;
		cout << "The LARGEST is:" << setw(7) << FindLargest(num1, num2);
		cout << endl;
		cout << "The AVERAGE is:" << setw(7) << AverageTwoInts(num1, num2);
		cout << endl << endl << endl << endl;

	// The LCV (num1) is updated and checked at the top of the loop.
		cout << left;
		cout << setw(26) << "Enter the first integer:";
		cin  >> num1;
		cin.ignore (1000, '\n');

	}

	return 0;
}

//Function Definitions

	//Sum Function
int AddTwoInts(int num1, int num2)
{
	int sum;
	sum = num1 + num2;
	return sum;
}

	//Product Function
int MultiplyTwoInts(int num1, int num2)
{
	int product;
	product = num1 * num2;
	return product;
}

	//Largest Function
int FindLargest(int num1, int num2)
{
	if(num1 > num2)
	{
		return num1;
	}
	else
	{
		return num2;
	}
}

	//Average Function
float AverageTwoInts(float num1, float num2)
{
	float sum;
	float average;
	sum = num1 + num2;
	average = sum / 2.0;
	return average;
}
