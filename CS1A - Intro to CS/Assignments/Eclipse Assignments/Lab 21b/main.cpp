/*/************************************************************************
 * PROGRAMMED BY: BBC & FSC
 * CLASS		: CS1A
 * SECTION		: MW 9:30a
 * Lab #21b		: Functions - Rock, Paper, Scissors
 *************************************************************************/

#include "Header.h"

int main()
{
	char move;
	string uName;
	int rounds;
	bool won;
	int wonTot;
	int count;

	wonTot = 0;
	count = 1;

	PrintHeader("Rock, Paper, Scissors", 'L', 21);

	GetInput(uName, rounds);

	for(count=1;count<=rounds;++count)
	{
		ValidatePlay(move);

		CheckWin(move);

		OutputWin(won, uName , wonTot);
	}

	OutputMatchWinner(wonTot, rounds, uName);

}
