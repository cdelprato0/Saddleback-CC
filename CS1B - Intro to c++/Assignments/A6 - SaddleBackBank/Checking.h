/**************************************************************************
 * AUTHORS      : BBC
 * STUDENT IDs  : 382108
 * ASSIGNMENT #6: Saddleback Bank - OOP
 * CLASS		: CS1B
 * SECTION		: MW 8:30a
 * DUE DATE     : 5-7-2015
 *************************************************************************/
#ifndef CHECKING_H_
#define CHECKING_H_

#include "AccountClass.h"


class Checking: public AccountClass
{
public:

	/***************************
	 * CONSTRUCTOR * DESTRUCTOR*
	 ***************************/
	Checking();				//DEFALUT CONSTRUCTOR
	Checking(int aNum, float aBal, string aName); //NON-DEFALUT CONSTRUCTOR
	virtual ~Checking();	//DEFAULT DE-CONSTRUCTOR


	virtual void Display(ofstream &oFile, DateClass date)const;

	virtual bool DepositFunds(float aAmount, DateClass date);
	virtual bool WithdrawFunds(float aAmount, DateClass date);

};

#endif /* CHECKING_H_ */
