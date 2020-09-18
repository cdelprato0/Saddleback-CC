#ifndef SFSDF_H_
#define SFSDF_H_

// Preprocessor directives for the program
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
using namespace std;


//// Declare functions and their parameters for being called in the main
void Header();

void GetInfo(string& name, char& gender);

bool CoinFlip(int& total,int& totalHeads);

int Total_Average(int& total, int& totalHeads);

void Output(int average, int total);


#endif /* SFSDF_H_ */
