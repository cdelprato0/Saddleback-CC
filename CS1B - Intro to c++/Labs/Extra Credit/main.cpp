./**************************************************************************
 * AUTHOR	  :BBC
 * STUDENT ID :382108
 * LAB #	  :Extra Credit
 * CLASS	  :CS1B
 * SECTION	  :M/W 8:30
 * DUE DATE	  :02-02-2015
 *************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	//Declaring an identifier - Syntax: type variablename;
	int sum;
	char response;
	float average;

	//Constants - const type CONSTANT_NAME;
	const int DAYS_OF_WEEK = 7;
	const float SALES_TAX = 0.080;

	//C-Strings - char variableName;
	char oneLetter;

	//C-String size - char variableName[size];
	char multiLetter[30];

	//String - string variableName;
	string name1;
	string name2;

	//Assigning
	name1 = "jean";
	name2 = name1;

						//Data Table
	int ageOne;			//INPUT - first user's age
	int ageTwo;			//INPUT - second user's age
	float averageAge;	//CALC & OUT - average of two input ages

	//Extraction Operator - cin >> variable >> variable;
	float floatVal;

	cout << "Enter a floating point number";
	cin >> floatVal;

	cout << "Enter an age";
	cin >> ageOne;

	//cin.getline(variable, size);
	char fullName[30];

	cout << "PLease enter your full name.";
	cin.getline(fullName, 30);

	//cin.ignore(1000, '\n');
	cout << "Please enter a number";
	cin >> floatVal;
	cin.ignore(1000, '\n');

	cout << "PLease enter your full name.";
	cin.getline(fullName, 30);

	//cin.get(char variable);
	char gender;

	cout << "Please enter your gender(m/f)";
	cin.get(gender);

	//cin.width
	char userString[5];
	cout << "enter a string:";
	cin.width(5);
	cin >> userString;

	//Output
	int val;
	val = 24;
	cout << "\tThe val is" << setw(9) << val;

	//Setprecision, fixed, showpoint
	float val1;
	float val2;
	float val3;

	val1 = 423.353607;
	val2 = 3.1455929;
	val3 = 5;

	cout << setprecision(2);
	cout << setw(9) << val1 << endl;
	cout << setw(9) << val2 << endl;
	cout << setw(9) << val3 << endl;

	cout << showpoint;
	cout << setw(9) << val1 << endl;
	cout << setw(9) << val2 << endl;
	cout << setw(9) << val3 << endl << endl << endl;

	cout << fixed;
	cout << setw(9) << val1 << endl;
	cout << setw(9) << val2 << endl;
	cout << setw(9) << val3 << endl;

	//if-then
	int hours;

	if(hours <= 40)
	{
		cout << "No overtime" << endl;
	}
	cout << "Continue" << endl;

	//nested if - then
	char hourEmp;

	if(hours > 40)
	{
		if(hourEmp == 'Y')
		{
			cout << "Overtime dur";
		}
	}

	//if-then-else

	if(hours <= 40)
	{
		cout << "No overtime" << endl;
	}
	else
	{
		cout << "Overtime Due " << endl;
	}

	//nested if-then-else
	cout << "enter hours worked: ";
	cin >> hours;
	cin.ignore(1000,'\n');

	if(hours > 40)
	{
		cout << "Hourly Employee?";
		cin.get(hourEmp);
		cin.ignore(1000,'\n');
		if(hourEmp == 'Y')
		{
			cout << "Overtime due";
		}
		else
		{
			cout << "Sorry not hourly employed.";
		}
	}
	else
	{
		cout << "No overtime" << endl;
	}

	//Conditional Operator
	float overTime;

	overTime = (hours > 40? (hours - 40)*1.5: 0.0);

	//Nested
	float price;

	cout << (price > 3.0? "over 3" : (price == 3.0? "equals 3 ":
													"less than 3"));

	//If-then-else-if
	char classCode;

	if (classCode == 'F')
	{
	cout << "You are a freshman!" << endl;
	}
	else if (classCode == 'S')
	{
	cout <<"You are a sophomore!" << endl;
	}
	else if (classCode == 'J')
	{
	cout << "You are a junior!" << endl;
	}
	else if (classCode == 'R')
	{
	cout << "You are a senior!" << endl;
	}
	else
	{
	cout << "Invalid class Code!" << endl;
	}

	//switch statements
	switch (classCode)
	{
		case 'F' : cout << "freshman!" << endl;
		break;
		case 'S' : cout << "sophomore!" << endl;
		break;
		case 'J' : cout << "junior !" << endl;
		break;
		case 'R' : cout << "senior!" << endl;
		break;
		default : cout << "You entered an invalid code";
		break;
	}

	//Bool variable

	bool dataOK;
	int n1, n2;
	dataOK = n1 < 4 && n2 !=3;

	if (dataOK)
	{
	 cout << "all good";
	}
	else
	{
	 cout << "bad data";
	}

	//While  loop
	int num;

	cout << "Enter an integer (0 to exit): ";
	cin >> num;

	while (num != 0)
	{
	 cout << num * 12 << endl;
	 cout << "Enter another integer (0 to exi): ";
	 cin >> num;
	}
	cout << "Out of loop" << endl;

	//Do while loop
	int weight;

	do
	{
	cout << "Enter your weight: ";
	cin >> weight;

	if (weight < 100)
	 {
	 cout << "You must weigh at least 100 lbs" << endl;
	 cout << "to use this program.\n";
	 }

	}
	while (weight < 100);

	cout << "Out of loop with a valid weight of " << weight << " lbs.";

	//Increment
	int preInc;
	int postInc;
	int lcv;

	preInc = 1;
	postInc = 1;

	cout << "lcv Pre-Inc Test Post-Inc Test\n";

	for (lcv = 1; lcv <= 3; ++lcv)
	{
		cout << lcv << "\t ";
		cout << ++preInc << "\t\t";
		cout << postInc++ << endl;
	}
	cout << "\nIn the end they are the same: ";
	cout << preInc << "\t" << postInc;

	//Decrement
	int preDec;
	int postDec;


	preDec = 1;
	postDec = 1;

	cout << "lcv Pre-Dec Test Post-Dec Test";

	for (lcv = 1; lcv <= 3; ++lcv)
	{
		cout << lcv << "\t ";
		cout << --preDec << "\t\t";
		cout << postDec-- << endl;
	}

	cout << "\nIn the end they are the same: ";
	cout << preDec << "\t" << postDec;


}



