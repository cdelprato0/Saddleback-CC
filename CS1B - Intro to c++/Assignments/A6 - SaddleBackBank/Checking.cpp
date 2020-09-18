/**************************************************************************
 * AUTHORS      : BBC
 * STUDENT IDs  : 382108
 * ASSIGNMENT #6: Saddleback Bank - OOP
 * CLASS		: CS1B
 * SECTION		: MW 8:30a
 * DUE DATE     : 5-7-2015
 *************************************************************************/
#include "Checking.h"

//Checking Class constructor - DEFAULT Constructor
Checking::Checking()
{
	//Nothing to initialize in this class
}


/*************************************************************************
 * METHOD Checking - NON-DEFALUT Constructor
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
Checking::Checking(int aNum, 		//aNum  - account number
					float aBal,		//aBal  - account Balance
					string aName) 	//aName - user name
					:AccountClass(aNum, aBal, aName) //Base class
{
	//Assigns the attributes to the parameters
	name = aName;
	accountBal = aBal;
	accountNum = aNum;
}


//Checking Class de-constructor - DEFAULT De-Constructor
Checking::~Checking()
{
	//Nothing to deconstruct in this class
}


void Checking::Display(ofstream &oFile, DateClass date)const
{
	string currentDate;

	currentDate = date.GetDate();

	oFile << left << setprecision(2) << fixed
	      << setw(19)  << "OPEN CHECKING" << setw(13) << currentDate
		  << setw(8)   << accountNum      << setw(23) << name << '$';
	oFile << right
		  << setw(9) << accountBal << "   $" << setw(12)
		  << accountBal << endl;
}

bool Checking::DepositFunds(float aAmount, DateClass date)
{
	bool found;

	found = true;

	accountBal = accountBal + aAmount;

	return found;

}


bool Checking::WithdrawFunds(float aAmount, DateClass date)
{
	float withdraw;
	float withdrawWithFee;
	float withdrawFee;
	bool found;

	withdraw = accountBal - aAmount;

	withdrawFee = 20.00;
	withdrawWithFee = withdraw - withdrawFee;

	if(withdraw >= 0)
	{
		accountBal = withdraw;
		found = true;
	}
	else if(withdraw < 0 && withdrawWithFee >= -200.00)
	{
		accountBal = withdrawWithFee;
		found = true;
	}
	else
	{
		found = false;
	}



	return found;
}
