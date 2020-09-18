/************************************************************************************
 * AUTHOR	    :Chaz Del Prato & Chase Deric
 * LAB # 3      :Prefix Averages
 * CLASS	    :CS1D
 * SECTION	    :M/W 3:30 PM
 ************************************************************************************/
#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;

/*******************************************************************************
 * CS1D - Lab Three - Prefix Averages
 * _____________________________________________________________________________
 * This program will be able to keep track of the of the prefix averages of
 * random numbers. This program will be able to keep track of how long the
 * process to calculate the prefix average. There will be an array that keeps
 * hold of a user defined amount of random numbers. The first 5 random number
 * will be outputed with the first 5 number of the prefix averages. At the same
 * time, the program will be outputting the time it takes to calculate the
 * prefix average. We will test the program with 100,1000,10000,50000,100000
 * array sizes and will analyze the data
 *
 *******************************************************************************/
int main()
{

	//outputs the header for the output
cout << "************************************************************************\n"
		"* PROGRAMMED BY : Chase Deric & Chaz Del Prato                         *\n"
		"* LAB # 3       : Prefix Average                                       *\n"
		"* CLASS         : CS1D                                                 *\n"
		"* SECTION       : MW 3:00p                                             *\n"
		"------------------------------------------------------------------------\n"
		"* Description   :                                                      *\n"
		"*  The output of this program will display a prompt for the user to    *\n"
		"*  enter the size of the array. The program will output the first 5    *\n"
		"*  random numbers of the array and then will output the 5 first values *\n"
		"*  of the prefix averages of the top array. Then it will output the    *\n"
		"*  time it took to complete the process in nanoseconds. The second     *\n"
		"*  prefix average will be displayed with the number in the array and   *\n"
		"*  then the current prefix average. The program will then output the   *\n"
		"*  time it took in nanoseconds.                                        *\n";
cout << "************************************************************************\n\n";

	int arraySize;			//size of the array to be generated
	float average;			//average of number to be used for array


	LARGE_INTEGER frequency;		//CALC - Calculates clock frequency
	LARGE_INTEGER t1, t2, t3, t4;	//CALC - time-stamps to be calculated
	double elapsed1, elapsed2;		//CALC - elapsed time

	//Outputs to the console and prompts the user to enter the size of the array
	cout << "PREFIX AVERAGE #1\n"
		 << "-----------------\n\n";
	cout << "Please enter the size of the input: ";
	cin >> arraySize;

	int intArray[arraySize]; 		//the array that keeps the random values
	float averageArray[arraySize];  //the array that keeps the prefix average


	//CALC - Calculates clock frequency
	QueryPerformanceFrequency(&frequency);

	//Loads the integer array with random numbers
	for(int index = 0; index < arraySize; index++){
		intArray[index] = (rand() % 1000 + 1);
	}

	//Outputs the first five numbers
	cout << "\nThe first 5 numbers that are saved in the array are: \n";
	for(int index = 0; index < 5; index++){
		cout << intArray[index] << "  ";
	}

	cout << "\n\nThe PreFix Average of the first 5 numbers are: \n";

	//Sets first timestamp
	QueryPerformanceCounter(&t1);

	//Performs the first prefix average
	for(int index = 0; index < arraySize - 1; index++){

		average = 0.0;

		for(int j = 0; j < index + 1; j++){
			average = average + intArray[j];
		}

		averageArray[index] = average / ( index + 1 );
	}

	//Sets second timestamp
	QueryPerformanceCounter(&t2);

	//CALC - calculates elapsed time for nested for loop
	elapsed1 = (t2.QuadPart - t1.QuadPart) * 1000000.0/ frequency.QuadPart;

	for(int index = 0; index < 5; index++){
		cout << setprecision(2) << fixed << averageArray[index] << "  ";
	}

	//displays new time
	cout << "\n\nIt took " << setprecision(3) << fixed << elapsed1 << " Nanoseconds!\n\n\n";

	cout << "PREFIX AVERAGE #2\n"
		 << "-----------------\n\n";

	int index =0;				//CALC - counter
	float sum = 0.0;			//CALC - used in calculating the average of the array


	int AlgTwoAr[arraySize];			//CALC - Array of values to be averaged
	float AverageAr[arraySize];			//CALC - Array to hold averages of AlgTwoAr

	//Sets third timestamp
	QueryPerformanceCounter(&t3);

	//BEGIN For loop, generates AlgTwoAr[] to arraySize and fills each element with a random number (0-99)
	for ( index=0; index < arraySize ;index++ )
	{
		AlgTwoAr[index] = rand () % 1000;

		//Calculates sum
		sum = sum + AlgTwoAr[index];

		//Fills AverageAr[] array with average of total sum at each element
		AverageAr[index] = sum / ( index + 1 );
	}

	//Sets fourth timestamp
	QueryPerformanceCounter(&t4);

	//CALC - Calculates elapsed time of second for loop
	elapsed2 = (t4.QuadPart - t3.QuadPart) * 1000000.0/ frequency.QuadPart;

	//Function that prints to screen both arrays
	for(int i=0; i<5 ;i++)
	{
		cout << "Number " << i+1 << " is: " << AlgTwoAr[i] << endl;
		cout << setprecision(2) << "Current Average is: "<< AverageAr[i] << endl << endl;
	}

	//displays new time
	cout << "It took " << elapsed2 << " Nanoseconds!";


	return 0;
}
