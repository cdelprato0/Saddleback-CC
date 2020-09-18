/**************************************************************************
 * AUTHORS      : BBC
 * STUDENT IDs  : 382108
 * ASSIGNMENT #6: Saddleback Bank - OOP
 * CLASS		: CS1B
 * SECTION		: MW 8:30a
 * DUE DATE     : 5-7-2015
 *************************************************************************/
#include "Header.h"


void OutputFileHeader(ofstream &oFile)
{
	oFile << left
		  << setw(19) << "TRANSACTION" << setw(13) << "DATE"
		  << setw(8)  << "ACCT #"      << setw(23) << "ACCT NAME";
	oFile << right
		  << setw(10) << "AMOUNT"      << setw(16) << "BALANCE"
		  << setw(15) << "FROM ACCT#"  << setw(18) << "FROM ACCT BAL"
		  << endl;

	oFile << right
		  << setfill('-') << setw(19) << "       " << setw(13)
		  << "   "        << setw(8)  << "   "     << setw(23) << "   "
		  << setw(13)     << "   "    << setw(18)  << "     "
		  << setw(15)     << "     "  << setw(18)  << "     "
		  << setfill(' ') << endl;
}


//PrintHeader - Determines if the program is an assignment or lab and
//				displays the programmers info in the output.
void PrintHeader(ofstream& OFile, string asName, char asType, int asNum)
{
	OFile << left;
	OFile << "********************************************************";
	OFile << "\n* PROGRAMMED BY : BBC";
	OFile << "\n* " << setw(14) << "Student ID" << ": 382108";
	OFile << "\n* " << setw(14) << "Class" << ": CS1B --> Mon/Wed 8:30am";
	OFile << "\n* ";
	if(toupper(asType) == 'L')
	{
		OFile << "LAB #" << setw(9);
	}
	else
	{
		OFile << "ASSIGNMENT #" << setw(2);
	}
	OFile << asNum << ": " << asName;
	OFile << "\n******************************************************\n\n";
	OFile << right;
}
