/**************************************************************************
 * AUTHORS      : BBC
 * STUDENT IDs  : 382108
 * ASSIGNMENT #6: Saddleback Bank - OOP
 * CLASS		: CS1B
 * SECTION		: MW 8:30a
 * DUE DATE     : 5-7-2015
 *************************************************************************/
#ifndef MONEYMARKET_H_
#define MONEYMARKET_H_

#include "Savings.h"

class MoneyMarket: public Savings
{
public:

	/***************************
	 * CONSTRUCTOR * DESTRUCTOR*
	 ***************************/
	MoneyMarket();			//DEFALUT CONSTRUCTOR
	MoneyMarket(int aNum, float aBal, string aName, float mInter); //NON-DEFALUT CONSTRUCTOR
	virtual ~MoneyMarket(); //DEFAULT DE-CONSTRUCTOR

	virtual void Display(ofstream &oFile, DateClass date)const;

	virtual bool DepositFunds(float aAmount, DateClass date);
	virtual bool WithdrawFunds(float aAmount, DateClass date);

	float InterestRate(DateClass date);


private:

	//Holds the value of the interest determined for this account
	float mInterest;

};

#endif /* MONEYMARKET_H_ */
