/**************************************************************************
 * AUTHORS      : BBC
 * STUDENT IDs  : 382108
 * ASSIGNMENT #6: Saddleback Bank - OOP
 * CLASS		: CS1B
 * SECTION		: MW 8:30a
 * DUE DATE     : 5-7-2015
 *************************************************************************/
#include "AccountClass.h"

//Account class constructor
AccountClass::AccountClass()
{
	//Assigns the account balance and account number to a non-possible amount
	accountBal = 0.00;
	accountNum = 0;

}


/*************************************************************************
 * METHOD AccountClass - NON-DEFALUT Constructor
 * ________________________________________________________________________
 * This method uses overloading to set in variables that have been entered
 * into the parameters and assigns them to the attributes
 *
 * ________________________________________________________________________
 * PRECONDITIONS
 *
 *
 * POSTCONDITIONS
 *
 ************************************************************************/
AccountClass::AccountClass(int aNum, float aBal, string aName)
{
	//Assigns the attributes to the parameters
	name = aName;
	accountNum = aNum;
	accountBal = aBal;

}


//Account Class de-constructor
AccountClass::~AccountClass()
{

}


/*************************************************************************
 * METHOD GetName
 * ________________________________________________________________________
 * This function simply allows the code to retrieve the name that is read
 * in from the input file.
 *
 * returns -> Name
 * ________________________________________________________________________
 * PRECONDITIONS
 *
 *
 * POSTCONDITIONS
 *   returns the value of the name
 ************************************************************************/
string AccountClass::GetName()const
{
	return name;
}


/*************************************************************************
 * METHOD GetAccNum
 * ________________________________________________________________________
 * This function simply allows the code to retrieve the account number that
 * is read in from the input file.
 *
 * returns -> account number
 * ________________________________________________________________________
 * PRECONDITIONS
 *
 *
 * POSTCONDITIONS
 *   returns the value of the account number
 ************************************************************************/
int AccountClass::GetAccNum()const
{
	return accountNum;
}


/*************************************************************************
 * METHOD GetAccBal
 * ________________________________________________________________________
 * This function simply allows the code to retrieve the account balance
 * that is read in from the input file.
 *
 * returns -> account balance
 * ________________________________________________________________________
 * PRECONDITIONS
 *
 *
 * POSTCONDITIONS
 *   returns the value of the account balance
 ************************************************************************/
float AccountClass::GetAccBal()const
{
	return accountBal;
}



void AccountClass::Display(ofstream &oFile, DateClass date)const
{


}


/*************************************************************************
 * METHOD SetValue
 * ________________________________________________________________________
 * This function will allow the user to set the name on the account.
 * name is protected.
 *
 * Method uses overloading
 * ________________________________________________________________________
 * PRECONDITIONS
 *   Previous value was set or now is being assigned
 *
 * POSTCONDITIONS
 *   New set value will be saved to name
 ************************************************************************/
void AccountClass::SetValue(string aName)
{
	name = aName;
}


/*************************************************************************
 * METHOD SetValue
 * ________________________________________________________________________
 * This function will allow the user to set the account number on the
 * account.
 * accountNum is protected.
 *
 * Method uses overloading
 * ________________________________________________________________________
 * PRECONDITIONS
 *   Previous value was set or now is being assigned
 *
 * POSTCONDITIONS
 *   New set value will be saved to account number
 ************************************************************************/
void AccountClass::SetValue(int aNum)
{
	accountNum = aNum;
}


/*************************************************************************
 * METHOD SetValue
 * ________________________________________________________________________
 * This function will allow the user to set the account balance on the
 * account.
 * accountBal is protected.
 *
 * Method uses overloading
 * ________________________________________________________________________
 * PRECONDITIONS
 *   Previous value was set or now is being assigned
 *
 * POSTCONDITIONS
 *   New set value will be saved to account balance
 ************************************************************************/
void AccountClass::SetValue(float aBal)
{
	accountBal = aBal;
}


bool AccountClass::DepositFunds(float aAmount, DateClass date)
{
	bool found;

	found = true;

	return found;
}


bool AccountClass::WithdrawFunds(float aAmount, DateClass date)
{
	bool found;

	found = true;

	return found;

}


