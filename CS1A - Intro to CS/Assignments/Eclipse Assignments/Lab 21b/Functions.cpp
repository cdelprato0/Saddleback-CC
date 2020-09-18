#include "Header.h"

void PrintHeader(string asName, char asType, int asNum)
{
	cout << left;
	cout << "********************************************************";
	cout << "\n* PROGRAMMED BY : BBC & FSC";
	cout << "\n* " << setw(14) << "Student ID" << ": 382108";
	cout << "\n* " << setw(14) << "Class" << ": CS1A --> Mon/Wed 9:30am";
	cout << "\n* ";
	if(toupper(asType) == 'L')
	{
		cout << "LAB #" << setw(9);
	}
	else
	{
		cout << "ASSIGNMENT #" << setw(2);
	}
	cout << asNum << ":" << asName;
	cout << "\n******************************************************\n\n";
	cout << right;
}


void GetInput(string& uName, int& rounds)
{
	cout << "Enter Player's Name: ";
	getline(cin, uName);

	cout << "Enter Number of Rounds in Match: ";
	cin >> rounds;
	cout << endl << endl;

}

char ValidatePlay(char move)
{
	cout << "R - Rock\nP - Paper\nS - Scissors\n";
	cout << "Enter your play: ";
	cin.get(move);
	cin.ignore(10000, '\n');
	cout << endl << endl;
	return move;
}

bool CheckWin(char move)
{
	int compMove;
	bool won;
	string compPlay;

	srand(time(NULL));
	compMove = (rand()%3+1);

	switch(compMove)
	{
	case 1: compPlay = "Rock";
			break;
	case 2: compPlay = "Paper";
			break;
	case 3: compPlay = "Scissors";
	}

	cout << "Computer chooses " << compPlay;

	won = (move=='R' && compMove==3) || (move=='P' && compMove==1) ||
		  (move=='S' && compMove==2) || (move=='r' && compMove==3) ||
		  (move=='p' && compMove==1) || (move=='s' && compMove==2);
	return won;
}

void OutputWin(bool won, string uName, int& wonTot)
{

	if (won)
		{
		cout << "\n\nWINNER WINNER CHICKEN DINNER!\n" << uName << " wins!"
				"\n\n";
		++wonTot;
		}
	else
		cout << "Better luck next time, " << uName << endl << endl;
}

void OutputMatchWinner(int wonTot, int rounds, string uName)
{
	float average;
	cout << "*********  FINAL RESULTS  *********\n";
	cout << "***********************************\n\n\n";

	cout << uName << " is the winner!!\n";

	average = float(wonTot) / rounds * 100;

	cout << uName << " won an average of " << setprecision(0) << fixed
		 << average << "% of the time!";
}





