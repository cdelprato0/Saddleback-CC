/**************************************************************************
 * AUTHORS      : BBC
 * STUDENT IDs  : 382108
 * ASSIGNMENT #6: Saddleback Bank - OOP
 * CLASS		: CS1B
 * SECTION		: MW 8:30a
 * DUE DATE     : 5-7-2015
 *************************************************************************/
#ifndef SAVINGS_H_
#define SAVINGS_H_

#include "AccountClass.h"

class Savings: public AccountClass
{
public:

	/***************************
	 * CONSTRUCTOR * DESTRUCTOR*
	 ***************************/
	Savings();			//DEFALUT CONSTRUCTOR
	Savings(int aNum, float aBal, string aName, float sInter); //NON-DEFALUT CONSTRUCTOR
	virtual ~Savings(); //DEFAULT DE-CONSTRUCTOR


	virtual void Display(ofstream &oFile, DateClass date)const;

	virtual bool DepositFunds(float aAmount, DateClass date);
	virtual bool WithdrawFunds(float aAmount, DateClass date);

	float InterestRate(DateClass date);




private:

	//Holds the value of the interest determined for this account
	float interestRate;
};

#endif /* SAVINGS_H_ */
