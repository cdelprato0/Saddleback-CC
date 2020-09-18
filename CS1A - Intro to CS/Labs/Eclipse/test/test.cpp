/*
 * test.cpp
 *
 *  Created on: Oct 29, 2014
 *      Author: cdelprato0
 */

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main()
{

	int countSkit=3;
	int countM_m=5;
	int countP_m_m=4;
	int countSoda=12;
	int countJuice=9;
	int countWine=15;

cout << left << "Florence needs to purchase:" << endl;
cout << left << setw(9) << "BAGS" << "SNACK" << endl;
cout << setw(9) << "----" << "-----" << endl;

cout << setw(9) <<  countSkit % 4 == 0 << "Skittles" << endl;
cout << setw(9) << countM_m / 4 % 1 << "M & M\'s" << endl;
cout << setw(9) << countP_m_m / 4 % 1<< "Peanut M & M\'s" << endl << endl;
																				//countJuice / 6 countJuice % 6
																				//Not correct  1 % (countJuice / 6)
cout << left << setw(9) << "CASES" << "BEVERAGE" << endl;
cout << setw(9) << "-----" << "--------" << endl;
cout << setw(9) << countJuice%6 << "Juice" << endl;
cout << setw(9) << countSoda%6<< "Soda" << endl;
cout << setw(9) << countWine%6<< "Wine" << endl;

return 0;
}
