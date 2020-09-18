#ifndef HEADER_H_
#define HEADER_H_

// Preprocessor directives for the program

#include<iostream>
#include<iomanip>
#include<string>
using namespace std;


void PrintHeader(string aName, char aType, int aNum);
void EnterName(string fileNames[], const int NUM_N);
int SearchName(string fileNames[], int NUM_N, string inquiry);


#endif /* HEADER_H_ */
