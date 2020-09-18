/**************************************************************************
 * AUTHOR     : singmusic & BBC
 * LAB #6     : Structs
 * CLASS      : CS1B
 * SECTION    : MW 8:30am
 * DUE DATE   : 2/25/2015
 *************************************************************************/
#include"Header.h"

/**************************************************************************
 * Search Array
 * ________________________________________________________________________
 * This function, when called, will check each element of the provided
 * array for a match with the search item entered. When found, the search
 * terminates and the index value of the match is returned.
 * ________________________________________________________________________
 *  * INPUTS -
 * 		inFile 		: Input file stream
 * 		memberAr	: Array of structs containing user info
 * 		AR_SIZE		: number of elements in the array
 * 		searchItem	: string search item -> from calling function
 * 		totBal      : total running balance of people found
 *
 * 	OUTPUT -
 *		balance - Will keep a running total sum of the balances due on the
 *			      people that were found
 *		index - will return the index number of the element in which
 *				person was found
 *************************************************************************/
int SearchArray(ofstream& oFile,			    //IN - input stream variable
				const MemberAccount memberAr[],	//IN - array of structs
				const int AR_SIZE,				//IN - size of array
				const string searchItem,		//IN - string search key
				float& totBal)					//IN&OUT - running total
												//         of balance due
{
	int index;		//PROC - index of array element
	bool found;		//PROC - true when searched item matches value
					//	     in current array element; false otherwise

	//PROC - Checks each element of the array for a match for the
	//		 string search item provided. If a match is found, the index
	//		 of the element at which it was found is returned; otherwise,
	//		 search continues until all elements are checked.
	index = 0;
	found = false;
	while(!found && index < AR_SIZE)
	{
		//OUT - If the search item is found, user information is
		//		printed to the output file. Otherwise, index increments.
		if(memberAr[index].name == searchItem)
		{
			found = true;

			oFile << memberAr[index].id << "\t" << left << setw(24) <<
					memberAr[index].name << left << "$" <<setprecision(2)
					<< fixed << right << setw(10) << memberAr[index].balance
					<< endl;
			totBal = totBal + memberAr[index].balance;
		}
		else
		{
			index++;
		}

	}

	return index;
}
