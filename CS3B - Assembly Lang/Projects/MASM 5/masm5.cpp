//;**********************************************************************************************************
//; Program Name: MASM 5
//; Programmer:   Chaz Del Prato & Chase Deric
//; Class:        CS3B T/Th 3:30pm
//; Date:         April 30, 2018
//; Purpose:
//;   For this assignment, you are to write C++ code that sorts the 200,000 integers from the attached
//;   numbers.dat  using the C++ (pseudocode on p. 374) and Assembly language (p. 375) versions of the bubble
//;   sort algorithm. DO NOT use any other form of sort from any other source!. It is important that the
//;   logic be identical to that shown on p. 374 of our text.  Store the resulting numbers in a files
//;   respective to the language that sorted them (e.g. bubbleSortC.dat, and bubbleSortA.dat).
//;**********************************************************************************************************
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <math.h>
#include <iomanip>
#include <cstring>
#include <time.h>
#include <stdlib.h>

using namespace std;

extern "C" {
	void BubbleSort(long array[], long count);
}

void BubbleSortCpp(long array[], long count)
{
	int outer = count - 1;
	while( outer > 0 ){
		int inner = outer;
		while( inner > 0 ){
			if (array[inner] > array[inner + 1]) {
				long temp = array[inner];
				array[inner] = array[inner + 1];
				array[inner + 1] = temp;
				inner--;
		}
		outer--;
	}

//	for (int j = 1; j < count; j++) {
//		for (int i = 0; i < count - 1 - j; i++) {
//			if (array[i] > array[i + 1]) {
//				long temp = array[i];
//				array[i] = array[i + 1];
//				array[i + 1] = temp;
//			}
//		}
//	}
}

int main()
{
	//clears the console window
	system("cls");

	//declares the vector that will hold all the data
	vector<float> v;

	cout << "MASM 5 BubbleSort Comparison (Assembly vs C++)\n"
			  << "By Chase Deric and Chaz Del Prato\n\n";

	//Will read in all the data from the given input file
	cout << "Reading numbers.dat\n";

	fstream file("numbers.dat", ios_base::in);
	float index;

	while (file >> index) {
		v.push_back(index);
	}

	//Will call the .asm code and will run the assembly code through the bubble sort and will record the time it takes to complete
	cout << "Running BubbleSort.asm... \n\n";

	clock_t begin = clock();
	BubbleSort( (long *)&v[0], v.size());
	clock_t end = clock();

	//Will display the time it takes to complete the sort
	double sec = double( end - begin ) / CLOCKS_PER_SEC;
	int min = ( (int)sec % 3600 ) / 60;
	int sSecs = ( (int)sec % 60 );

	cout << "Time: " << min << ":" << sSecs << " minutes\n\n";
	file.close();

	//Outputs to a file to compared later
	int j = 0;
	ofstream outputFile("bubbleSortASM.dat");

	if (outputFile.is_open()) {

		for (float &index : v) {
			outputFile << setprecision(10) << index;
			j++;

			if (j == 10) {
				outputFile << "\n";
				j = 0;
			}
			else {
				outputFile << " ";
			}
		}
	}
	outputFile.close();
	cout << "Assembly complete!" << endl << endl;



	vector<float> w;

	cout << "Reading numbers.dat\n";

	fstream fileC("numbers.dat", ios_base::in);
	float b;

	while (fileC >> b) {
		w.push_back(b);
	}

	cout << "Running BubbleSort.cpp... \n\n";

	clock_t beginC = clock();
	BubbleSortCpp( (long *)&w[0], w.size() );
	clock_t endC = clock();

	double secC = double(endC - beginC) / CLOCKS_PER_SEC;
	int minC = ( (int)secC % 3600 ) / 60;
	int smallC = ( (int)secC % 60 );

	cout << "Time: " << minC << ":" << smallC << " minutes\n\n";
	fileC.close();

	int jC = 0;
	ofstream outputFileC("bubbleSortCPP.dat");

	if ( outputFileC.is_open() ) {

		for (float &i : w) {
			outputFileC << setprecision(10) << i;
			jC++;

			if (jC == 10) {
				jC = 0;
				outputFileC << "\n";
			}
			else {
				outputFileC << " ";
			}
		}
	}
	outputFileC.close();

	cout << "C++ Complete!\n\n\n\n";
	cout << "Assembly Time:  " << min << ":" << sSecs << " minutes\n";
	cout << "C++ Time:       " << minC << ":" << smallC << " minutes\n";
	getchar();

	return 0;
}




