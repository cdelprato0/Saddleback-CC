#ifndef HEADER_H_
#define HEADER_H_


#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void PrintHeader(string asName, char asType, int asNum);


void GetInput(string& uName, int& rounds);

char ValidatePlay(char move);

bool CheckWin(char move);

void OutputWin(bool won, string uName, int& wonTot);

void OutputMatchWinner(int wonTot, int rounds, string uName);

#endif /* HEADER_H_ */
