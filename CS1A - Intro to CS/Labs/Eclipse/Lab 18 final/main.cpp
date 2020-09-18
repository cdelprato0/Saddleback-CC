
/*/**************************************************************************
 * Author		: Isaac Torchia and BBC
 * Student ID	: 364903
 * Lab 15		: Repetition buddy's average sheep age calculator
 * Class		: Cs1A
 * Section		: MW: 9am
 * Due Date		: 10/29/14
 * **********************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/************************************************************************
 * Buddy's Average Sheep Age Calculator
 * _____________________________________________________________________________
 * This program will output the user's drink and candy of choice.
 * _____________________________________________________________________________
 * 	<There is no input for this program - output data is obtained
 * through the constants. >
 *
 * 	OUTPUT:
 * 		Outputs the type of candy and type of drink that the user prefers.
 *************************************************************************/
 int main()
 {
 	 /*******************************************************************
 	  * CONSTANTS
 	  * ------------------------------------------------------------------
 	  * Used for class heading - All Will be OUTPUT
 	  * -----------------------------------------------------------------
 	  * Programmer 		: Programmer's Name
 	  * Class 			: Student's Course
 	  * Section			: Class Days and Times
 	  * Lab_Num			: Lab Number (specific to this lab)
 	  * Lab_Name		: Title of the lab
 	  *******************************************************************/
 	  const char PROGRAMMER[30] = "Isaac Torchia and BBC";
 	  const char CLASS[5]		= "CS1A";
 	  const char SECTION [25]	="MW: 9:30 - 1120";
 	  const int LAB_NUM			= 18;
 	  const char LAB_NAME[40]	="Buddy's Average Age sheep Calculator";

 	  // variable declarations go here
 	  int		sheepAge;			//INPUT - User enterd sheep age.
 	  int		testNumber;			//CALC - runs the program 3 times
 	  float		averageSheepAge;    //OUTPUT&CALC - Outputs the average
 	  int		amountSheepCounter; //CALC - Keeps track of how many sheep
 	  int		totSheepAge;		//CALC - Running total of the ages


 	  // OUTPUT - Class Heading
 	  cout << left;

 	  cout << "********************************************************";
 	  cout << "\n* PROGRAMMED BY : " << PROGRAMMER;
 	  cout << "\n* " << setw(14) << "CLASS" << CLASS;
 	  cout << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
 	  cout << "\n* LAB #" << setw(9) << LAB_NUM << ": " << LAB_NAME;
 	  cout << "\n***************************************************\n\n";
 	  cout << right;

 	  //Shows the number of tests that the program will run through
 	  for ( testNumber = 1; testNumber <= 3; testNumber = testNumber + 1)
 	  {
 		 amountSheepCounter = 0;
 		 totSheepAge = 0;
 		 averageSheepAge = 0;

 		 cout << "Test # ";
 		 cout << testNumber << ":" << endl;

 		 cout << "Welcome to Buddy's Average Sheep Age Calculator!" <<
 				   endl << endl;

 		 cout << "\tEnter in the sheep ages, input -1 to exit ";
 		 cout << endl;

 		 //Tests for valid age of the sheep

 		 do
 		 {
 			cout << "\tSheep Age: ";
 	 		cin >> setw(17) >> sheepAge;

 			 if (sheepAge > 9)
 			 	{
 			 		 cout << endl << " *** Invalid sheep age - "
 			 			"please input a value less than or equal to 9!"
 			 			<< endl << endl;
 			 	}

 		 }while (sheepAge > 9);

 		 //Increments the number of sheep and total amount of ages and
 		 //determines if the sheep age is valid

 		 while (sheepAge >=0)
 		 {
 			 amountSheepCounter = amountSheepCounter + 1;
 			 totSheepAge = totSheepAge + sheepAge;


 			do
 			 {
 			 		cout << "\tSheep Age: ";
 			 	 	cin >> setw(17) >> sheepAge;

 			 		if (sheepAge > 9)
 			 		{
 			 			 cout << endl << " *** Invalid sheep age - "
 			 			 		"please input a value less than or"
 			 			 		" equal to 9!"
 			 			 		<< endl << endl;
 			 		}

 			 }while (sheepAge > 9);

 		 }
 		//OUTPUT- outputs the average age of the sheep

		 averageSheepAge = totSheepAge / amountSheepCounter;

 		 cout << endl << "\tOn average your sheep are ";
 		 cout << setprecision(1) << fixed << averageSheepAge
 			   << " years old!" << endl;
 		 //OUTPUT - Tells the user what category the age of the sheep
 		 //belongs

 		 if (averageSheepAge >= 6)
 		 {
 			 cout << "\tIn general your sheep are Aging - time to breed!!";
 			 cout << endl << endl << endl << endl;
 		 }
 		 else if (averageSheepAge <= 3 )
 		 {
 			 cout << "\tIn general your sheep are BABIES!";
 			 cout << endl << endl << endl << endl;
 		 }
 		 else
 		 {
 		 cout << "\tIn general your sheep are MIDDLE AGED!";
 		 cout << endl << endl << endl << endl;
 		 }

 	   }
 	  //OUTPUT - Ending statements for the user
 	  cout << "Thank you for using Buddy\'s Average Sheep Age Calculator!";
 	  cout << endl << "Have a great day!! :)";

  	   return 0;

 }
