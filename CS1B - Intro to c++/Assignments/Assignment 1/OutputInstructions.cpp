/**************************************************************************
 * AUTHORS      : BBC
 * STUDENT IDs  : 382108
 * ASSIGNMENT #1: Functions
 * CLASS		: CS1B
 * SECTION		: MW 8:30a
 * DUE DATE     : 2-9-2015
 *************************************************************************/
#include "Header.h"

/***************************************************************************
 * Functions - OutputInstructions
 * -------------------------------------------------------------------------
 * This functions will output the game "High Roller", instructions on how
 * to play and how the game works, into the console
 * -------------------------------------------------------------------------
 ****************************************************************************/
void OutputInstructions()
{
	//OUTPUT - Outputs into the console after the PrintHeader function
	cout << "***********************************************************\n"
			"*                  WELCOME TO HIGH ROLLER                 *\n"
			"*---------------------------------------------------------*\n"
			"* This is a two-player game that allows each player to    *\n"
			"* roll a die. The player with the highest roll wins.      *\n"
			"*---------------------------------------------------------*\n"
			"* Each player will first be prompted to enter their name. *\n"
			"* Then each player will roll in turn (the first name      *\n"
			"* entered will go first).                                 *\n"
			"***********************************************************\n";
}
