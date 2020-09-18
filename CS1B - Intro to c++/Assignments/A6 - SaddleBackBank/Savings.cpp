/**************************************************************************
 * AUTHORS      : BBC
 * STUDENT IDs  : 382108
 * ASSIGNMENT #6: Saddleback Bank - OOP
 * CLASS		: CS1B
 * SECTION		: MW 8:30a
 * DUE DATE     : 5-7-2015
 *************************************************************************/
#include "Savings.h"


//Savings Class constructor - DEFAULT Constructor
Savings::Savings()
{
	//Sets the interest on the account to zero
	interestRate = 0.0;
}


/*************************************************************************
 * METHOD Savings - NON-DEFALUT Constructor
 * ________________________________________________________________________
 * This method uses overloading to set in variables that have been entered
 * into the parameters and assigns them to the attributes.
 * Also calls the set attributes of the base class.
 *
 * ________________________________________________________________________
 * PRECONDITIONS
 * <none>
 *
 * POSTCONDITIONS
 * <none>
 ************************************************************************/
Savings::Savings(int aNum,     //aNum   - Account Number
				 float aBal,   //aBal   - Account Balance
				 string aName, //aName  - Users name
				 float sInter) //sInter - Savings account interest

				 :AccountClass(aNum, aBal, aName) //Base class
{
	//Assigns the attribute to the parameter
	interestRate = sInter;
}


//Savings Class de-constructor - DEFAULT De-Constructor
Savings::~Savings()
{
	//Nothing to deconstruct in this class
}



void Savings::Display(ofstream &oFile, DateClass date)const
{
	string currentDate;

	currentDate = date.GetDate();

	oFile << left << setprecision(2) << fixed
	      << setw(19)  << "OPEN SAVINGS" << setw(13) << currentDate
		  << setw(8)   << accountNum      << setw(23) << name << '$';
	oFile << right
		  << setw(9) << accountBal << "   $" << setw(12)
		  << accountBal << endl;
}


bool Savings::DepositFunds(float aAmount, DateClass date)
{
	float interest;
	bool found;
	found = true;

	interest = InterestRate(date);

	accountBal = accountBal + aAmount + interest;

	return found;
}


bool Savings::WithdrawFunds(float aAmount, DateClass date)
{
	float interest;
	float withdraw;
	bool found;

	interest = InterestRate(date);

	withdraw = accountBal - aAmount;

	if(accountBal > aAmount)
	{
		accountBal = withdraw + interest;
		found = true;
	}
	else
	{
		found = false;
	}

	return found;
}


float Savings::InterestRate(DateClass date)
{
	float interest;
	string currentDate;
	string prevDate;

	interest = 0.0;
	currentDate = date.GetDate();
	prevDate = date.GetPrevDate();


	if(currentDate > prevDate)
	{

		interest = interestRate * accountBal;
	}


	return interest;
}
