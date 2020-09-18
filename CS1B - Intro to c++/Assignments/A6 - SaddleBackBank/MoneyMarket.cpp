/**************************************************************************
 * AUTHORS      : BBC
 * STUDENT IDs  : 382108
 * ASSIGNMENT #6: Saddleback Bank - OOP
 * CLASS		: CS1B
 * SECTION		: MW 8:30a
 * DUE DATE     : 5-7-2015
 *************************************************************************/
#include "MoneyMarket.h"


//MoneyMarket Class constructor - DEFAULT Constructor
MoneyMarket::MoneyMarket()
{
	//Sets the interest on the account to zero
	mInterest = 0.0;
}


/*************************************************************************
 * METHOD MoneyMarket - NON-DEFALUT Constructor
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
MoneyMarket::MoneyMarket(int aNum, 	  //aNum  - account number
						float aBal,   //aBal  - account balance
						string aName, //aName - users name
						float mInter) //mInter- moneyMarket interest
						:Savings(aNum, aBal, aName, mInter)//Base class
{
	//Assigns the attribute to the parameter
	mInterest = mInter;
}


//MoneyMarket Class de-constructor - DEFAULT De-Constructor
MoneyMarket::~MoneyMarket()
{
	//Nothing to deconstruct in this class
}



void MoneyMarket::Display(ofstream &oFile, DateClass date)const
{
	string currentDate;

	currentDate = date.GetDate();

	oFile << left << setprecision(2) << fixed
	      << setw(19)  << "OPEN Money Market" << setw(13) << currentDate
		  << setw(8)   << accountNum      << setw(23) << name << '$';
	oFile << right
		  << setw(9) << accountBal << "   $" << setw(12)
		  << accountBal << endl;
}

bool MoneyMarket::DepositFunds(float aAmount, DateClass date)
{
	float interest;
	bool found;
	found = true;

	interest = InterestRate(date);

	accountBal = accountBal + aAmount + interest;

	return found;
}


bool MoneyMarket::WithdrawFunds(float aAmount, DateClass date)
{
	float interest;
	float withdraw;
	float withdrawFee;
	float withdrawWithFee;
	bool found;

	interest = InterestRate(date);
	withdraw = accountBal - aAmount;

	withdrawFee = 1.50;
	withdrawWithFee = withdraw - withdrawFee;

	if(accountBal > aAmount)
	{
		accountBal = withdrawWithFee + interest;
		found = true;
	}
	else
	{
		found = false;
	}


	return found;
}


float MoneyMarket::InterestRate(DateClass date)
{
	float interest;
	string currentDate;
	string prevDate;

	interest = 0.0;
	currentDate = date.GetDate();
	prevDate = date.GetPrevDate();

	if(currentDate > prevDate)
	{

		interest = mInterest * accountBal;
	}


	return interest;
}
