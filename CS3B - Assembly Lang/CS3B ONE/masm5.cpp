/*
 * masm5.cpp
 *
 *  Created on: May 16, 2018
 *      Author: Chaz
 */

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

void BubbleSortCpp(long array[], long count);

int main()
{
	system("cls");

	//variable declaration
	std::vector<float> v;

	/************ Bubblesort using asm code ***************/

	std::cout << "Assmebly vs C++ (Bubble Sort Performance)" << endl << endl;

	//Read in data from random_numbers.dat
	std::cout << "Loading file random_numbers.dat\n";
	std::fstream file("random_numbers.dat", std::ios_base::in);
	float a;
	while (file >> a) {
		v.push_back(a);
	}

	//PERFORM SORT using ASM code
	std::cout << "BubbleSort.asm : IN PROGRESS \n";
	clock_t beginTime = clock();
	BubbleSort( (long *)&v[0], v.size());
	clock_t endTime = clock();

	// display time taken for sorting
	double seconds = double( endTime - beginTime ) / CLOCKS_PER_SEC;
	int minutes = ( (int)seconds % 3600 ) / 60;
	int smallSeconds = ( (int)seconds % 60 );
	std::cout << "ASM BubbleSort duration = " << minutes << ":" << smallSeconds << " minutes\n";
	file.close();   //CLOSE FILE

	//Output the sorted values to output file
	std::cout << "BubbleSort.asm : SORTED and OUTPUTTING\n";
	int j = 0;
	std::ofstream outputFile("asm_sort.dat");
	if (outputFile.is_open()) {
		for (float &i : v) {
			outputFile << std::setprecision(10) << i;
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
	std::cout << "ASM SORT Completed Successfully" << endl << endl;

	/************ Bubblesort using c++ code ***************/

	std::vector<float> w;

	//Read in data from random_numbers.dat
	std::cout << "Loading file random_numbers.dat\n";
	std::fstream fileC("random_numbers.dat", std::ios_base::in);
	float b;
	while (fileC >> b) {
		w.push_back(b);
	}

	//PERFORM SORT using CPP code
	std::cout << "BubbleSort.cpp : IN PROGRESS \n";
	clock_t beginTimeC = clock();
	BubbleSortCpp( (long *)&w[0], w.size() );
	clock_t endTimeC = clock();

	// display time taken for sorting
	double secondsC = double(endTimeC - beginTimeC) / CLOCKS_PER_SEC;
	int minutesC = ( (int)secondsC % 3600 ) / 60;
	int smallSecondsC = ( (int)secondsC % 60 );
	std::cout << "CPP BubbleSort duration = " << minutesC << ":" << smallSecondsC << " minutes\n";
	fileC.close();   //CLOSE FILE

	//Output the sorted values to output file
	std::cout << "BubbleSort : SORTED and OUTPUTTING\n";
	int jC = 0;
	std::ofstream outputFileC("cpp_sort.dat");
	if ( outputFileC.is_open() ) {
		for (float &i : w) {
			outputFileC << std::setprecision(10) << i;
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

	std::cout << "CPP Test Test Completed Successfully \n\n\n\n";
	std::cout << "RESULTS:  \n\n";
	std::cout << "ASM SORTING TIME =  " << minutes << ":" << smallSeconds << " MIN\n";
	std::cout << "CPP SORTING TIME =  " << minutesC << ":" << smallSecondsC << " MIN\n";
	std::getchar();

	return 0;
}

void BubbleSortCpp(long array[], long count)
{
	for (int j = 1; j < count; j++) {
		for (int i = 0; i < count - 1 - j; i++) {
			if (array[i] > array[i + 1]) {
				long temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
			}
		}
	}
}


