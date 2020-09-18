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
	cout << "***********************************";
	cout << "\n* PROGRAMMED BY : " << PROGRAMMER;
	cout << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	cout << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	cout << "\n* LAB#" << setw(10) << LAB_NUM << ": " << LAB_NAME;
	cout << "\n***********************************\n\n";
	cout << right;

	/**********************************************************************
	 * This program will be able to output a persons preferred type of
	 * candy and there preference of drink depending on their age as well
	 * as how many servings bags and cases of each.
	 *********************************************************************/

	char name[31];			//INPUT - Name of guest
	int age;				//INPUT - Age of guest
	char candy[15];			//INPUT - Candy type
	char drink[15];			//INPUT - Drink type
	char chocStat;			//INPUT - Chocolate preference
	char nutStat;			//INPUT - Nut preference
	int count;				// LCV
	int countWine=0;		// count for wine servings
	int countSoda=0;		// count for soda servings
	int countJuice=0;		// count for juice servings
	int countSkit=0;		// count for Skittles servings
	int countM_m=0;			// count for M & M's servings
	int countP_m_m=0;		// count for Peanut M & M's servings
	int minGuestCount=1;
	int maxGuestCount=12;


	// INPUTS - Prompts for name, age, and chocolate preference


	cout << left;
	cout << setw(30) << "Welcome Florence!  Please input your guests' names, ages, and preferences!\n\n";


	for(count = minGuestCount;count <= maxGuestCount; count = count +1 )
	{
		cout << left;
		cout << "Guest #"<< count << ":" << endl;

		cout << setw(30) << "What is your fiends name?";
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
				strncpy(drink, "wine", 15);
			}
			else
			{
				if(age >= 6)
				{
					strncpy(drink, "soda", 15);
				}
				else
				{
					strncpy(drink, "juice", 15);
				}
			}

			//OUTPUT - The name and what should be served to that person
			cout << endl;
			cout << "You should serve " << name << " " << candy << " and ";
			cout << drink << ".";
			cout << right << endl << endl << endl;

			//Processing serving counts for drink and snacks

		if(strcmp(drink,"wine")==0)
		{
			countWine = countWine + 1;
		}

		if(strcmp(drink,"soda")==0)
		{
			countSoda = countSoda + 1;
		}

		if(strcmp(drink,"juice")==0)
		{
			countJuice = countJuice + 1;
		}

		if(strcmp(candy,"Skittles")==0)
		{
			countSkit = countSkit + 1;
		}

		if(strcmp(candy,"M & M\'s")==0)
		{
			countM_m = countM_m + 1;
		}

		if(strcmp(candy,"Peanut M & M\'s")==0)
		{
			countP_m_m = countP_m_m + 1;
		}
	}

// end processing table outputs servings and amout of cases/bags to buy
cout << left << "There are:" << endl;
cout << setw(2)<< countSkit << "servings of Skittles" <<endl;
cout << setw(2)<< countM_m << "servings of M & M\'s" << endl;
cout << setw(2)<< countP_m_m << "servings of Peanut M & M\'s";
cout << endl << endl;

cout << setw(3) << countSoda * 3 << "servings of soda" << endl;
cout << setw(3)<< countJuice * 3 << "servings of juice" << endl;
cout << setw(3)<< countWine * 3 << "servings of wine";
cout << endl << endl << endl;

cout << left << "Florence needs to purchase:" << endl;
cout << left << setw(9) << "BAGS" << "SNACK" << endl;
cout << setw(9) << "----" << "-----" << endl;

cout << setw(9) << countSkit / 4 % 1 << "Skittles" << endl;
cout << setw(9) << countM_m / 4 % 1 << "M & M\'s" << endl;
cout << setw(9) << countP_m_m / 4 % 1<< "Peanut M & M\'s" << endl << endl;
																				//countJuice / 6 countJuice % 6
																				//Not correct  1 % (countJuice / 6)
cout << left << setw(9) << "CASES" << "BEVERAGE" << endl;
cout << setw(9) << "-----" << "--------" << endl;
cout << setw(9) <<  << "Juice" << endl;
cout << setw(9) << countSoda / 6 % 1<< "Soda" << endl;
cout << setw(9) << countWine / 6 % 1<< "Wine" << endl;

cout << right;







return 0;
}









