#include <iostream>
#include <iomanip>
using namespace std;

//PROG DESC: This program adds two integers and outputs the result
int main()
{
	int firstNum;  //INPUT --> 1st input from the user
	int secondNum; //INPUT --> 2nd input from the user
	int sum; // CALC & OUT --> sum of the 2 integers input
	float average;

	//INPUT - reads in two inputs from the user (firstNum & secondNum)
	//Prompts the user for the first input then reads the input
	cout << "Enter the first integer: ";
	cin >> firstNum;

	//Prompts the user for the second input then reads the input
	cout << "Enter the second integer: ";
	cin >> secondNum;

	cout << fixed << setprecision(2);

	//PROCESSING-Calculates the sum of the two inputs
	sum = firstNum + secondNum;
	average = sum / 2.0;

	//OUTPUT-Outputs the inputs and the sum as specified
	cout << endl << firstNum << " + " << secondNum << " = " << sum <<endl;
	cout << endl << "The average is: " << average << endl;


	return 0;
}



