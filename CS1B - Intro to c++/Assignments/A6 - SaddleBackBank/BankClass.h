/**************************************************************************
 * AUTHORS      : BBC
 * STUDENT IDs  : 382108
 * ASSIGNMENT #6: Saddleback Bank - OOP
 * CLASS		: CS1B
 * SECTION		: MW 8:30a
 * DUE DATE     : 5-7-2015
 *************************************************************************/
#ifndef BANKCLASS_H_
#define BANKCLASS_H_

#include "AccountClass.h"
#include "Checking.h"
#include "Savings.h"
#include "MoneyMarket.h"
#include "DateClass.h"

class BankClass
{
public:

	/***************************
	 * CONSTRUCTOR * DESTRUCTOR*
	 ***************************/
	BankClass();			//DEFALUT CONSTRUCTOR
	virtual ~BankClass();	//DEFAULT DE-CONSTRUCTOR

	/*************
	 * ACCESSORS *
	 *************/
	void DisplayList(ofstream &oFile, DateClass date)const;		//Displays to the output file
	AccountClass* SearchAccount(int aNum)const; //Searches a linked list for
												//an account number
	int Size()const;
	bool IsEmpty()const;

	/************
	 * MUTATORS *
	 ************/
	void InsertHead(AccountClass* info);		//Inserts a node to the head
												//of the list
	void InsertTail(AccountClass* info);		//Inserts a node to the tail
												//of the linked list

	bool DepositFunds(ofstream &oFile, DateClass date, int aNum, float aAmount);
	bool WithdrawFunds(ofstream &oFile, DateClass date, int aNum, float aAmount);
	bool TransferFunds(ofstream &oFile, DateClass date, int aNumFrom, int aNumTo, float aAmount);


private:
	//Holds the linked list for the accounts
	struct Account
	{
		AccountClass *payLoad;	//The pay load of the accounts
								//(Holds accNumber, accBalanc, etc...)

		Account *next; 			//TGhe pointer that points to the next node
	};

	Account *head;				//The Head of the linked list
	Account *tail;				//The tail of the linked list
	int size;					//The size of the linked list
};

#endif /* BANKCLASS_H_ */
