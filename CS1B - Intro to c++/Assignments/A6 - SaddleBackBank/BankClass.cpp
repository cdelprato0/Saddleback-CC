/**************************************************************************
 * AUTHORS      : BBC
 * STUDENT IDs  : 382108
 * ASSIGNMENT #6: Saddleback Bank - OOP
 * CLASS		: CS1B
 * SECTION		: MW 8:30a
 * DUE DATE     : 5-7-2015
 *************************************************************************/
#include "BankClass.h"

//Bank Class constructor
BankClass::BankClass()
{
	//Assigns the head and tail to NULL and size to zero so that the
	//Variables are initialized
	head = NULL;
	tail = NULL;
	size = 0;

}


//Bank Class de-constructor
BankClass::~BankClass()
{
	head = NULL;
	tail = NULL;
}


/*************************************************************************
 * METHOD DisplayList
 * ________________________________________________________________________
 * This method will output to an output file that is being passed in.
 * This display will go through the entire linked list and output the
 * necessary outputs by using the virtual command.
 *
 * 			  *Virtual-------------------------------------------------->
 * BankClass->AccountClass->CheckingClass->SavingsClass->MoneyMarketClass
 *
 * Method uses virtual Display
 * ________________________________________________________________________
 * PRECONDITIONS
 *   <none>
 *
 * POSTCONDITIONS
 *   Outputs to the OutputFile.txt
 ************************************************************************/
void BankClass::DisplayList(ofstream &oFile, DateClass date)const //oFile - Output File
{
	Account *currentNode;	//PROC - Pointer for the linked list

	//Assigning the pointer to the head of the linked list
	currentNode = head;

	//PROCESSING - While loop is checking to see if the currentNode is equal
	//				to NULL or if the head is equal to nothing. If it is
	//				equal to NULL it will output the virtual displays and
	//				will run through out the whole linked list
	while(currentNode != NULL)
	{

		//Calls the AccountClass Display which calls Checking, Savings, and
		//MoneyMarkets Display Methods
		currentNode->payLoad->Display(oFile, date);

		//Updates the current node that is being looked at to the one next to it
		currentNode = currentNode->next;
	}//END - WHILE - LOOP

}


/*************************************************************************
 * METHOD SearchAccount
 * ________________________________________________________________________
 * This method searches the linked list for a particular account number.
 * Once it is found it will output the nodes pay load.
 *
 * returns -> the payload of the node
 * ________________________________________________________________________
 * PRECONDITIONS
 *   <none>
 *
 * POSTCONDITIONS
 *   returns the found account number
 ************************************************************************/
AccountClass* BankClass::SearchAccount(int aNum)const //aNum - Account Number
{
	Account *currentNode; //PROC - Pointer for the linked list
	bool found;		      //PROC - Used to determine if the number is found

	//INITIAILIZING found to false or default
	found = false;

	//Assigning the pointer to the head of the linked list
	currentNode = head;

	//PROCESSING - The while loop checks to see if the name was found in the
	//				linked list and also checks to make sure that the
	//				current node is not equal to NULL or nothing
	while(!found && currentNode != NULL)
	{
		//PROCESSING - If the pay load of the current linked node is equal
		//				to the requested account number then it will set
		//				found to true and return the current pay load
		//				If the linked node does not match the requested
		//				account number than it will keep found = false and
		//				will look at the next node in the list
		if(currentNode->payLoad->GetAccNum() == aNum)
		{
			//Assigns found to true because the name was found in the list
			found = true;
		}//END -IF

		else
		{
			//Assigns found to false to unsure it stays that way
			found = false;

			//Updates the current node that is being looked at to the one
			//next to it
			currentNode = currentNode->next;
		}//END - ELSE

	}//END WHILE LOOP

	return currentNode->payLoad;
}



int BankClass::Size()const
{
	return size;
}


bool BankClass::IsEmpty()const
{
	return (size == 0);
}



void BankClass::InsertHead(AccountClass* info)
{
	Account *currentNode; //PROC - Pointer for the linked list

	//PROCESSING - Creates and allocates random memory for the new node
	currentNode          = new Account;

	// " - Loads the parameter that contain the pay load from main into the
	//     node for the linked list
	currentNode->payLoad = info;

	// " - Assigns the next node to NULL so that we can keep track of the
	//	   end of the list
	currentNode->next    = NULL;

	//PROCESSING - CHecks to see if the linked list is empty or not
	if(head == NULL)
	{
		//If it is it will assign the head and the tail to the current node
		head = currentNode;
		tail = currentNode;
	}
	else
	{
		//If it is not, it will assign the
		currentNode->next = head;
		head     		  = currentNode;
	}

	size++;
}


/*************************************************************************
 * METHOD InsertTail
 * ________________________________________________________________________
 * This method adds the node that is being passed in from main into the
 * linked list. It starts at the head of the linked list and uses the tail
 * to move around and add other nodes
 *
 *
 * ________________________________________________________________________
 * PRECONDITIONS
 *   <none>
 *
 * POSTCONDITIONS
 *   Inserts a node into a linked list at the tail
 ************************************************************************/
void BankClass::InsertTail(AccountClass *info) //info - the pay load for the
											   //       node form main
{
	Account *currentNode; //PROC - Pointer for the linked list

	//PROCESSING - Creates and allocates random memory for the new node
	currentNode          = new Account;

	// " - Loads the parameter that contain the pay load from main into the
	//     node for the linked list
	currentNode->payLoad = info;

	// " - Assigns the next node to NULL so that we can keep track of the
	//	   end of the list
	currentNode->next    = NULL;

	//PROCESSING - Checks to see if the linked list is empty or not
	if(tail == NULL)
	{
		//If it is it will assign the head and the tail to the current node
		head = currentNode;
		tail = currentNode;
	}//END - IF

	else
	{
		//If it is not, then it will add the node to the tail of the
		//linked list
		tail->next = currentNode;
		tail       = currentNode;
	}//END - ELSE

	//The size of the linked list is updated
	size++;
}


bool BankClass::DepositFunds(ofstream &oFile, DateClass date, int aNum, float aAmount)
{
	string currentDate;
	AccountClass *search;
	bool found;

	found = false;

	search = SearchAccount(aNum);

	if(search != NULL)
	{

		search->DepositFunds(aAmount, date);

		found = true;
	}
	else
	{
		oFile << left
			  << "\n***ERROR - ACCOUNT NUMBER CAN NOT BE FOUND IN SYSTEM***\n"
			  << "***				 CONTACT BANK MANAGER			  ***\n\n";
		found = false; //ErrorCheck
	}

	currentDate = date.GetDate();

	if(found)
	{
		oFile << left
			  << setw(19) << " Deposit" << setw(13) << currentDate
			  << setw(8)  << search->GetAccNum()
			  << setw(23) << search->GetName() << '$';
		oFile << right
			  << setw(9) << aAmount << "   $"
			  << setw(12) << search->GetAccBal()
			  << endl;
	}

	return found;

}


bool BankClass::WithdrawFunds(ofstream &oFile, DateClass date, int aNum, float aAmount)
{
	string currentDate;
	bool found;
	AccountClass *search;

	found = false;

	currentDate = date.GetDate();
	search = SearchAccount(aNum);

	if(search != NULL)
	{
		search->WithdrawFunds(aAmount, date);
		found = true;
	}
	else
	{
		oFile << left
			  << "\n***ERROR - ACCOUNT NUMBER CAN NOT BE FOUND IN SYSTEM***\n"
			  << "***				 CONTACT BANK MANAGER			  ***\n\n";
		found = false;
	}

	if(found)
	{
		oFile << left
			  << setw(19) << " Withdrawal" << setw(13) << currentDate
			  << setw(8)  << search->GetAccNum()
			  << setw(23) << search->GetName() << '$';
		oFile << right
			  << setw(9) << aAmount << "   $"
			  << setw(12) << search->GetAccBal()
			  << endl;
	}
	else
	{
		oFile << left
			  << "\n***UNABLE TO WITHDRAW OUT OF ACCOUNT***\n"
			  << "***		INSUFFICIENT FUNDS  		***\n\n";
	}

	return found;
}


bool BankClass::TransferFunds(ofstream &oFile, DateClass date, int aNumTo, int aNumFrom, float aAmount)
{
	string currentDate;
	AccountClass *searchNumFrom;
	AccountClass *searchNumTo;
	bool found;

	found = false;
	searchNumFrom = SearchAccount(aNumFrom);
	searchNumTo = SearchAccount(aNumTo);

	currentDate = date.GetDate();

	if(searchNumFrom != searchNumTo)
	{

		if(searchNumFrom->GetAccBal() > aAmount)
		{
			searchNumFrom->WithdrawFunds(aAmount, date);
			searchNumTo->DepositFunds(aAmount, date);
			found = true;
		}
		else
		{
			oFile << "\n*** TRANSFER FROM " << aNumFrom << " TO " << aNumTo
				  << " NOT ALLOWED! ***\n"
				  << "***        DUE TO INSUFFICIENT FUNDS        ***\n\n";
			found = false;
		}

	}
	else
	{
		oFile << "\n*** ERROR - CAN\'T TRANSFER INTO THE SAME ACCOUNT ***\n\n";
		found = false;
	}

	if(found && searchNumFrom->GetAccBal() > aAmount)
	{
		oFile << left
			  << setw(19) << " Transfer" << setw(13) << currentDate
			  << setw(8)  << searchNumTo->GetAccNum()
			  << setw(23) << searchNumTo->GetName() << '$';
		oFile << right
			  << setw(9) << aAmount << "   $"
			  << setw(12) << searchNumTo->GetAccBal()
			  << setw(15) << searchNumFrom->GetAccNum() << "     $"
			  << setw(11) << searchNumFrom->GetAccBal()
			  << endl;
	}



	return found;
}
