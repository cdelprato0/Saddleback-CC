/*
 * header.h
 *
 *  Created on: Nov 24, 2014
 *      Author: mrobison5
 */

#ifndef HEADER_H_
#define HEADER_H_

// Preprocessor directives for the program

#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>

using namespace std;

// Declare functions and their parameters for being called in the main

void PrintHeader(string aName, char aType, int aNum);
void NameFile(string fileNames[], const int NUM_N);
int NameSearching(string fileNames[], const int NUM_N, string inquiry);



#endif /* HEADER_H_ */


