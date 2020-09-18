/**************************************************************************
 * AUTHOR	  :BBC
 * STUDENT ID :382108
 * LAB #2	  :CS1A Review
 * CLASS	  :CS1B
 * SECTION	  :M/W 8:30
 * DUE DATE	  :02-02-15
 *************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/**********************************************************************
 * Theme Park Party Planner
 * --------------------------------------------------------------------
 * This program will be able to take a user's input for a kid's name, age,
 * if they are vegetarian, and if they like cheese or not. With that info
 * this program will be able to find the admission fees to the park,
 * the food that should be packed for the kid, the cost of that food,
 * and what event and ride the kid is allowed to go on. The output will
 * display the total cost for all the kid's and the average cost per kid.
 * --------------------------------------------------------------------
 * INPUT -
 * 		kidName
 * 		age
 * 		vegi
 * 		cheese
 *
 * PROCESSING -
 * 		kidCount
 * 		admission
 * 		cost
 * 		totalCost
 * 		totalAdmission
 *
 * OUTPUT -
 * 		ride
 * 		food
 * 		average
 * 		grandTotal
 *********************************************************************/

int main()
{
	/**********************************************************************
	 * CONSTANTS
	 * --------------------------------------------------------------------
	 * USED FOR CLASS HEADING - ALL WILL BE OUTPUT
	 * --------------------------------------------------------------------
	 * PROGRAMMER 	  : Programmer's Name
	 * CLASS      	  : Student's Course
	 * SECTION   	  : Class Days and Times
	 * LAB_NUM        : Lab Number (specific to this lab)
	 * LAB_NAME       : Title of the Lab
	 * INPUT_SPACING  : Spacing for the input in the output
	 *********************************************************************/
	const char PROGRAMMER[30] = "BBC";
	const char CLASS[5]		  = "CS1B";
	const char SECTION[25]    = "MW : 8:30 - 11:20";
	const int  LAB_NUM		  = 2;
	const char LAB_NAME[17]   = "CS1A Review";
	const int  INPUT_SPACING  = 30;

	int kidCount;			//CALC     -Counter for the # of kids
	string kidName;			//IN	   -User enters in the kid's name
	int age;				//IN	   -User enters in the kid's age
	char vegi;				//IN	   -User enters in the kid's preference
	char cheese;			//IN	   -User enters in the kid's preference
	float admission;		//CALC	   -The amount that will be charged to get in
	string ride;			//OUT	   -The event and ride the kid can attend
	float cost;				//CALC	   -The cost of the food
	string food;			//OUT	   -The food that the kid is allowed to eat
	float totalCost;		//CALC	   -The accumulated cost of food
	float average;			//CALC&OUT -The average cost per kid
	float totalAdmission;	//CALC	   -The accumulated admission fees
	float grandTotal;		//CALC&OUT -The total money that is spent

	// OUTPUT - Class Heading
	cout << left;
	cout << "*****************************************************";
	cout << "\n* PROGRAMMED BY : " << PROGRAMMER;
	cout << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	cout << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	cout << "\n* LAB #" << setw(9) << LAB_NUM << ": " << LAB_NAME;
	cout << "\n*****************************************************\n\n";
	cout << right;

	//PROCESSING - Setting accumulators equal to zero
	admission = 0.00;
	cost = 0.00;
	totalCost = 0.00;
	totalAdmission = 0.00;
	grandTotal = 0.00;

	cout << "Welcome to the Theme Park Planner! Please input each kid\'s "
			"information." << endl << endl;

	for(kidCount = 1; kidCount <= 10; kidCount++)
	{
		cout << left;
		cout << "Kid #" << kidCount << endl;

		//INPUT - Prompts user to enter the kid's name, age, if they are
		//        Vegetarian, and if they like cheese.
		cout << setw(INPUT_SPACING) << "What is your kid\'s name?";
		getline(cin, kidName);

		cout << setw(INPUT_SPACING) << "How old is your kid?";
		cin >> (age);
		cin.ignore(1000, '\n');

		cout << setw(INPUT_SPACING) << "Vegetarian (Y/N)?";
		cin.get(vegi);
		cin.ignore(1000, '\n');

		cout << setw(INPUT_SPACING) << "Does he/she like cheese(Y/N)?";
		cin.get(cheese);
		cin.ignore(1000, '\n');
		cout << endl;

		//PROCESSING - Determines by the age, what rides and events they
		//             are allowed at and the admission fee.
		if(age < 5)
		{
			admission = 0.00;
			ride = "Ferris Wheel and will be visiting the "
					"Sheep Petting Zoo.";
		}
		else if(age <= 12)
		{
			admission = 15.00;
			ride = "Tea Cups and will be playing Laser Tag.";
		}
		else
		{
			admission = 20.00;
			ride = "Roller Coaster and the Zip Line.";
		}

		//CALC -Accumulator that keeps a running sum for the admission fees
		totalAdmission = totalAdmission + admission;

		//PROCESSING - Determines the food that is recommended to pack for
		//             the kid,  based on if they are a vegetarian and if
		//             they like cheese or not. Also adds cost of food.
		if(vegi == 'Y' || vegi == 'y')
		{
			if(cheese == 'Y' || cheese == 'y')
			{
				cost = 2.50;
				food = "Cheese Pizza ";
			}
			else
			{
				cost = 1.75;
				food = "Happy Garden ";
			}
		}
		else
		{
			if(cheese == 'Y' || cheese == 'y')
			{
				cost = 3.50;
				food = "Cheeseburger ";
			}
			else
			{
				cost = 3.25;
				food = "Hamburger ";
			}
		}

		//CALC -Accumulator that keeps a running sum for the food fees
		totalCost = totalCost + cost;

		//OUTPUT - Outputs the kid's name and what ride and event they can
		//         attend and tells them what food to pack.
		cout << kidName << " will be going on the " << ride << endl;
		cout << "Pack a " << food << "for " << kidName << '!' <<
				endl << endl << endl;
	}

	//CALC - Calculates the grand total cost for the day and the average
	//       cost per kid.
	grandTotal = totalAdmission + totalCost;
	average = grandTotal / 10.00;

	//OUTPUT - Outputs the total cost for the day and the average cost for
	//         each kid.
	cout << "..." << endl;
	cout << setprecision(2) << fixed;

	cout << setw(31) << "The total cost for the day is:" << '$' << right <<
			setw(9) << grandTotal << endl;
	cout << left;
	cout << setw(31) << "The average cost per kid is:" << '$' << right <<
			setw(9) << average;

	return 0;
}

