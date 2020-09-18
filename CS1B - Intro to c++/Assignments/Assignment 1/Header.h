/**************************************************************************
 * AUTHORS      : BBC
 * STUDENT IDs  : 382108
 * ASSIGNMENT #1: Functions
 * CLASS		: CS1B
 * SECTION		: MW 8:30a
 * DUE DATE     : 2-9-2015
 *************************************************************************/

#ifndef HEADER_H_
#define HEADER_H_

// Preprocessor directives for the program
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <time.h>
#include <stdlib.h>

using namespace std;

// Declare functions and their parameters for being called in the main
void PrintHeader(string asName, char asType, int asNum);

void OutputInstructions();

void GetPlayersNames(string& player1, string& player2);

char GetAndCheckCharResponse();

int PlayOneTurn(string& player1, int& die);

int PlayTwoTurn(string& player2, int& die);

int RollDie(int& randNum);

void DisplayWinner(int& dieNum1, int& dieNum2,string& player1,
		string& player2);

void PressEnterToRoll();

void DisplayDie(int die);




#endif /* HEADER_H_ */
