/*/**************************************************************************
 * PROGRAMMED BY: ZBRA & BBC
 * CLASS		: CS1A
 * SECTION		: MW 9:30a
 * Lab #16		: Party Planner
 *************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main()
{
	//This is the header that will display in the output

	const char PROGRAMMER[30] = "ZBRA & BBC";
	const char CLASS[5] = "CS1A";
	const char SECTION[25] = "MW: 9:30AM";
	const int LAB_NUM = 16;
	const char LAB_NAME[28] = "Flo's Party Planner";

	cout << left;
	cout << "****************************************";
	cout << "\n* PROGRAMMED BY : " << PROGRAMMER;
	cout << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	cout << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	cout << "\n* LAB#" << setw(10) << LAB_NUM << ": " << LAB_NAME;
	cout << "\n****************************************\n\n";
	cout << right;

	/**********************************************************************
	 * This program will be able to output a persons preferred type of
	 * candy and there preference of drink depending on their age as well
	 * as how many servings, bags, and cases of each.
	 *********************************************************************/

	char name[31];			// INPUT - Name of guest
	int age;				// INPUT - Age of guest
	char candy[15];			// INPUT - Candy type
	char drink[15];			// INPUT - Drink type
	char chocStat;			// CALC - Chocolate preference
	char nutStat;			// CALC - Nut preference
	int count;				// Loop Control Variable
	int countWine=0;		// ASSIGN - count for wine servings
	int countSoda=0;		// ASSIGN - count for soda servings
	int countJuice=0;		// ASSIGN - count for juice servings
	int countSkit=0;		// ASSIGN - count for Skittles servings
	int countMM=0;			// ASSIGN - count for M & M's servings
	int countPMM=0;			// ASSIGN - count for Peanut M & M's servings
	int minGuestCount=1;	// ASSIGN - This is the min guest count
	int maxGuestCount=12;   // ASSIGN - This is the max guest count


	cout << left;
	cout << "Welcome Florence! ";
	cout << "Please input your guests\' names, ages, and preferences!\n\n";

	//INPUT - States which guest number it is and prompts the user for
	//		  a name, their age, and if they like chocolate

	for(count = minGuestCount;count <= maxGuestCount; count = count +1 )
	{
		cout << left;
		cout << "Guest #"<< count << ":" << endl;

		cout << setw(30) << "What is your friends\'s name?";
		cin.getline(name,31);

		cout << setw(30) << "How old is your friend?";
		cin >> age;
		cin.ignore(1000, '\n');

		cout << setw(30) << "Do they like chocolate (Y/N)?";
		cin.get(chocStat);
		cin.ignore(1000, '\n');

		//PROCESSING - Based on chocolate preference it prompts user for
		//		       nut preference and determines what to drink and also
		//			   increments the count of the snacks and drinks

		if(chocStat=='Y'|| chocStat == 'y')
			{
				cout << setw(30) << "Do they like nuts (Y/N)?";
				cin.get(nutStat);
				cin.ignore(1000, '\n');

				if(nutStat=='Y'|| nutStat == 'y')
				{
					strncpy(candy, "Peanut M & M\'s", 15);
					countPMM = countPMM + 1;
				}
				else
				{
					strncpy(candy, "M & M\'s", 15);
					countMM = countMM + 1;
				}
			}
			else
			{
				strncpy(candy, "Skittles", 15);
				countSkit = countSkit + 1;
			}

			if(age >= 21)
			{
				strncpy(drink, "wine", 15);
				countWine = countWine + 1;
			}
			else
			{
				if(age >= 6)
				{
					strncpy(drink, "soda", 15);
					countSoda = countSoda + 1;
				}
				else
				{
					strncpy(drink, "juice", 15);
					countJuice = countJuice + 1;
				}
			}

			//OUTPUT - The name and what should be served to that person
			cout << endl;
			cout << "You should serve " << name << " " << candy << " and ";
			cout << drink << ".";
			cout << right << endl << endl << endl;
	}

	// CALC&OUTPUT - Shows the amount of servings that are calculated form
    //			    each guest and calculates the number of bags and cases
    //			    that are needed to satisfy all of her guests
	cout << endl << left << "There are:" << endl;
	cout << setw(2)<< countSkit << "servings of Skittles" <<endl;
	cout << setw(2)<< countMM << "servings of M & M\'s" << endl;

	cout << setw(2)<< countPMM << "servings of Peanut M & M\'s";
	cout << endl << endl;

	cout << setw(3) << countSoda * 3 << "servings of soda" << endl;
	cout << setw(3)<< countJuice * 3 << "servings of juice" << endl;
	cout << setw(3)<< countWine * 3 << "servings of wine";
	cout << endl << endl << endl;

	cout << left << "Florence needs to purchase:" << endl;
	cout << left << setw(9) << "BAGS" << "SNACK" << endl;
	cout << setw(9) << "----" << "-----" << endl;

	if(countSkit % 4 == 0)
	{
		cout << setw(9) << countSkit / 4 << "Skittles" << endl;
	}
	else
	{
		cout << setw(9) << (countSkit / 4) + 1 << "Skittles" <<endl;
	}

	if(countMM % 4 == 0)
	{
		cout << setw(9) << countMM / 4 << "M & M\'s" << endl;
	}
	else
	{
		cout << setw(9) << (countMM / 4) + 1 << "M & M\'s" <<endl;
	}

	if(countPMM % 4 == 0)
	{
		cout << setw(9) << countPMM / 4 << "Peanut M & M\'s" << endl;
	}
	else
	{
		cout << setw(9) << (countPMM / 4) + 1 << "Peanut M & M\'s" << endl;
	}
	cout << endl;

	cout << left << setw(9) << "CASES" << "BEVERAGE"<< endl;
	cout << setw(9) << "-----" << "--------" << endl;

	if((countJuice *3) % 6 == 0)
	{
		cout << setw(9) << (countJuice * 3) / 6 << "Juice" << endl;
	}
	else
	{
		cout << setw(9) << (countJuice * 3 / 6) + 1 << "Juice" << endl;
	}

	if((countSoda * 3) % 6 == 0)
	{
		cout << setw(9) << (countSoda * 3) / 6 << "Soda" << endl;
	}
	else
	{
		cout << setw(9) << (countSoda * 3 / 6) + 1 << "Soda" << endl;
	}

	if((countWine * 3) % 6 == 0)
	{
		cout << setw(9) << (countWine * 3) / 6 << "Wine" << endl;
	}
	else
	{
		cout << setw(9) << (countWine * 3 / 6) + 1 << "Wine" << endl;
	}

	cout << right;

	return 0;
}
