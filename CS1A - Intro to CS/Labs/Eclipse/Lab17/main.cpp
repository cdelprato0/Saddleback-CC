/*/**************************************************************************
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
	cout << "***********************************";
	cout << "\n* PROGRAMMED BY : " << PROGRAMMER;
	cout << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	cout << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	cout << "\n* LAB#" << setw(10) << LAB_NUM << ": " << LAB_NAME;
	cout << "\n***********************************\n\n";
	cout << right;

	int totalEggsGathered;
	int totalEggs;
	int totalDozen;
	int numEggs;
	int numDozen;
	float averageEgg;
	int eggsGathered;
	int testNumber;

	numDozen = 0;
	eggsGathered = 0;
	totalEggs = 0;
	totalDozen = 0;
	totalEggsGathered = 0;


	for(testNumber = 1; testNumber <= 3; testNumber = testNumber + 1)
	{
		cout << left << "Test #" << testNumber << ":" << endl;
		cout << "Welcome to Aunt Ellen\'s eggs to dozens converter!";
		cout << endl << endl;

		cout << setw(39) << "Enter the number of eggs gathered: ";
		cin >> eggsGathered;


			while(eggsGathered > 0)
			{
				numDozen = eggsGathered /12;
				numEggs = eggsGathered % 12;
				if(eggsGathered > 0)
				{
					cout << "You have " << numDozen << " dozen " << numEggs << " eggs"
					<< endl << endl;
					totalEggs = totalEggs + eggsGathered;
					totalDozen = totalDozen + numDozen;
					totalEggsGathered = totalEggsGathered + 1;
				}
				cout << setw(39) << "Enter the number of eggs gathered: ";
				cin >> eggsGathered;
			}
			averageEgg = totalEggs / totalEggsGathered;

			cout << left << "TOTALS: " << endl;
			cout << fixed << setprecision(1);
			cout << "On average " << averageEgg << " eggs have been gathered." << endl;


			cout << "A total of " << totalEggs / 12 << " dozen and " << totalEggs % 12 <<
				" eggs have been gathered." << endl << endl << endl;


			}



	return 0;
}





