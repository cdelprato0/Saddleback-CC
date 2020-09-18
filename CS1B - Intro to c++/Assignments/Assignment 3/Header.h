/**************************************************************************
 * AUTHORS      : BBC
 * STUDENT IDs  : 382108
 * ASSIGNMENT #3: Tic Tac Toe
 * CLASS		: CS1B
 * SECTION		: MW 8:30a
 * DUE DATE     : 2-25-2015
 *************************************************************************/

#ifndef HEADER_H_
#define HEADER_H_

// Preprocessor directives for the program
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Global Constants that will keep be able to be used throughout the program
//without having to call in each function
const int NUM_ROWS = 3;		//CALC - The max number of rows allowed
const int NUM_COLS = 3;		//CALC - The max number of columns allowed


// Declare functions and their parameters for being called in the main
void PrintHeader(string asName, 	//INPUT - Name of the project
					char asType,	//INPUT - Type of project(Lab, Assignment)
					int asNum);		//INPUT - The number for the project

void OutputInstruct();

void InitializeBoard(char boardAr[][NUM_COLS]); //Tic-Tac-Toe Board

void DisplayBoard(const char boardAr[][NUM_COLS]); //Tic-Tac-Toe Board

void GetPlayers(string& playerX,  // OUTPUT - Player X’s name.
				string& playerO); // OUTPUT - Player O’x name.

void GetAndCheckInp(char boardAr[][NUM_COLS], //Tic-Tac-Toe Board
					char token,				  //INPUT - 'X' or 'O'
					string playerX,			  //INPUT - Player x's name
					string playerO);		  //INPUT - Player O's name

char SwitchToken(char token);		//OUTPUT - 'X' or 'O'

char CheckWin(const char boardAr[][NUM_COLS]); //Tic-Tac-Toe Board

void OutputWinner(char whoWon,			//OUTPUT - Who one the game
					string playerX, 	//OUTPUT - playerX name
					string playerO);	//OUTPUT - playerO name

#endif /* HEADER_H_ */
