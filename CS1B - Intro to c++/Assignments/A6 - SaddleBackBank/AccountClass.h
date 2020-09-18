/**************************************************************************
 * AUTHORS      : BBC
 * STUDENT IDs  : 382108
 * ASSIGNMENT #6: Saddleback Bank - OOP
 * CLASS		: CS1B
 * SECTION		: MW 8:30a
 * DUE DATE     : 5-7-2015
 *************************************************************************/
#ifndef ACCOUNTCLASS_H_
#define ACCOUNTCLASS_H_

#include "DateClass.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <ctime>
using namespace std;

class AccountClass
{
public:

	/***************************
	 * CONSTRUCTOR * DESTRUCTOR*
	 ***************************/
	AccountClass();			 //DEFALUT CONSTRUCTOR
	AccountClass(int aNum, float aBal, string pName); //NON-DEFALUT CONSTRUCTOR
	virtual ~AccountClass(); //DEFAULT DE-CONSTRUCTOR

	/*************
	 * ACCESSORS *
	 *************/
	string GetName()const;			//Returns the name of the user
	int GetAccNum()const;			//Returns the account number of the user
	float GetAccBal()const;			//Returns the account balance of the user

	virtual void Display(ofstream &oFile, DateClass date)const;

	/************
	 * MUTATORS *
	 ************/
	void SetValue(string aName);	//Sets the value of the name of the user
	void SetValue(int aNum);		//Sets the account number of the user
	void SetValue(float aBal);		//Sets the account balance of the user

	virtual bool DepositFunds(float aAmount, DateClass date);
	virtual bool WithdrawFunds(float aAmount, DateClass date);



protected:

	string name;			//The name that is under the account
	int    accountNum;		//The users account number
	float  accountBal;		//The users account balance

};

#endif /* ACCOUNTCLASS_H_ */
