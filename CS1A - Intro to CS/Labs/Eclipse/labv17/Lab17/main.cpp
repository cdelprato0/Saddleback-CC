/**************************************************************************
 * PROGRAMMED BY: Isaac Torchia & BBC
 * CLASS		: CS1A
 * SECTION		: MW 9:30a
 * Lab #17		: Repetition - Aunt Ellen's Egg Ranch
 *************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main()
{
	//This is the header that will display in the output

	const char PROGRAMMER[30] = "Isaac Torchia & BBC";
	const char CLASS[5] = "CS1A";
	const char SECTION[25] = "MW: 9:30AM";
	const int LAB_NUM = 17;
	const char LAB_NAME[40] = "Repetition - Aunt Ellen's Egg Ranch";

	cout << left;
	cout << "********************************************************";
	cout << "\n* PROGRAMMED BY : " << PROGRAMMER;
	cout << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	cout << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	cout << "\n* LAB#" << setw(10) << LAB_NUM << ": " << LAB_NAME;
	cout << "\n******************************************************\n\n";
	cout << right;

	int totalEggsGathered;		//CALC - This is the accumulator
	int totalEggs;				//CALC - This keeps count of all eggs
	int totalDozen;				//CALC - This keeps count of all dozens
	int numEggs;				//CALC - This keeps track of each egg
	int numDozen;				//CALC - This keeps track of each dozen
	float averageEgg;			//CALC&OUTPUT - Outputs average egg count
	int eggsGathered;			//INPUT - User inputs the amount of eggs
	int testNumber;				// Increments the test number

	//This program will be able to take an number of gathered eggs and
	//count the number of dozens and the excess and then outputs the
	//average.


	for(testNumber = 1; testNumber <= 3; testNumber = testNumber + 1)
	{
		numDozen = 0;
		numEggs = 0;
		eggsGathered = 0;
		totalEggs = 0;
		totalDozen = 0;
		totalEggsGathered = 0;

		cout << left << "Test #" << testNumber << ":" << endl;
		cout << "Welcome to Aunt Ellen\'s eggs to dozens converter!";
		cout << endl << endl;

		//INPUT - User enters the number of gathered eggs

		cout << right;
		cout << setw(39) << "Enter the number of eggs gathered: ";
		cout << left;
		cin >> setw(41) >> eggsGathered;



		while(eggsGathered >= 0)
		{
			numDozen = eggsGathered / 12;
			numEggs = eggsGathered % 12;

			if(eggsGathered > 0)
			{
				if(numEggs != 0 and numDozen != 0)
				{
					cout << left;
					cout << "    You have " << numDozen << " dozen ";
					cout << numEggs << " eggs." << endl << endl;
				}
				else
				{
					if(numDozen >= 1)
					{
						cout << "    You have " << numDozen;
						cout << " dozen eggs." << endl << endl;
					}
					if(numEggs >= 1)
					{
						cout << "    You have " << numEggs;
						cout << " eggs." << endl << endl;
					}
				}
			}
			//PROCESSING

			totalEggs = totalEggs + eggsGathered;
			totalDozen = totalDozen + numDozen;
			totalEggsGathered = totalEggsGathered + 1;
			averageEgg = float(totalEggs) / float(totalEggsGathered);

			//INPUT - User enters the number of gathered eggs

			cout << right;
			cout << setw(39) << "Enter the number of eggs gathered: ";
			cout << left;
			cin >> setw(41) >> eggsGathered;

		}
			//OUTPUT - Outputs the average amount of eggs and how many
			//		   total dozens and total amount of eggs
		if(totalEggsGathered >= 1)
		{
			cout << left << "TOTALS: " << endl;

			cout << fixed << setprecision(1);
			cout << "    On average " << averageEgg;
			cout << " eggs have been gathered." << endl;

			cout << "    A total of " << totalEggs / 12 << " dozen and ";
			cout << totalEggs % 12 <<" eggs have been gathered!";
			cout << endl << endl << endl;
		}
	}



	return 0;
}
