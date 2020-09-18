/*/************************************************************************
 * PROGRAMMED BY: ZBRA & BBC
 * CLASS		: CS1A
 * SECTION		: MW 9:30a
 * Lab #15		: Party Planner
 *************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main() {
	//This is the header that will display in the output

	const char PROGRAMMER[30] = "ZBRA & BBC";
	const char CLASS[5] = "CS1A";
	const char SECTION[25] = "MW: 9:30AM";
	const int LAB_NUM = 15;
	const char LAB_NAME[28] = "Party Planner";

	cout << left;
	cout << "***********************************";
	cout << "\n* PROGRAMMED BY : " << PROGRAMMER;
	cout << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	cout << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	cout << "\n* LAB#" << setw(10) << LAB_NUM << ": " << LAB_NAME;
	cout << "\n***********************************\n\n";
	cout << right;

	/**********************************************************************
	 * This program will be able to output a persons preferred type of
	 * candy and there preference of drink depending on their age.
	 *********************************************************************/

	char name[31];			//INPUT - Name of guest
	int age;				//INPUT - Age of guest
	char candy[15];			//INPUT - Candy type
	char drink[15];			//INPUT - Drink type
	char chocStat;			//INPUT - Chocolate preference
	char nutStat;			//INPUT - Nut preference


	// INPUTS - Prompts for name, age, and chocolate preference
	cout << left;
	cout << setw(30) << "What is your friend\'s name?";
	cin.getline(name,31);


	cout << setw(30) << "How old is your friend?";
	cin >> age;
	cin.ignore(1000, '\n');


	cout << setw(30) << "Do they like chocolate (Y/N)?";
	cin.get(chocStat);
	cin.ignore(1000, '\n');





	//PROCESSING - Based on chocolate preference it prompts user for nut
	//		       preference and determines what to drink
	if(chocStat=='Y'|| chocStat == 'y')
	{
		cout << setw(30) << "Do they like nuts (Y/N)?";
		cin.get(nutStat);
		cin.ignore(1000, '\n');

		if(nutStat=='Y'|| nutStat == 'y')
		{
			strncpy(candy, "Peanut M & M\'s", 15);
		}
		else
		{
			strncpy(candy, "M & M\'s", 15);
		}
	}
	else
	{
		strncpy(candy, "Skittles", 15);
	}

	if(age >= 21)
	{
		strncpy(drink, "beer", 15);
	}
	else
	{
		strncpy(drink, "soda", 15);
	}

	//OUTPUT - The name and what should be served to that person
	cout << endl;
	cout << "You should serve " << name << " " << candy << " and ";
	cout << drink << ".";
	cout << right << endl << endl << endl;

	return 0;
	}





