/**************************************************************************
 * AUTHORS      : BBC
 * STUDENT IDs  : 382108
 * ASSIGNMENT #6: Saddleback Bank - OOP
 * CLASS		: CS1B
 * SECTION		: MW 8:30a
 * DUE DATE     : 5-7-2015
 *************************************************************************/
#include "AccountClass.h"
#include "BankClass.h"
#include "Checking.h"
#include "Savings.h"
#include "MoneyMarket.h"
#include "Header.h"
#include "DateClass.h"

int main()
{
	AccountClass info;
	BankClass    currentNode;
	Checking	 *checkingAccount;
	Savings		 *savingsAccount;
	MoneyMarket  *mmAccount;
	DateClass date;

	ifstream     inFileAcc;
	ifstream     inFileTrans;
	ofstream	 oFile;

	unsigned short month;
	unsigned short day;
	unsigned short year;

	int          accNumber;
	string       accType;
	float        accBalance;
	string       accName;
	float 		 accAmount;
	string		 accAction;
	int			 accNumberTwo;

	string currentDate;

	inFileAcc.open("AccountInput.txt");
	inFileTrans.open("TransactionsInput.txt");
	oFile.open("OutputFile.txt");

	PrintHeader(oFile, "Saddleback Bank", 'A', 6);

	OutputFileHeader(oFile);



	inFileAcc >> month;
	inFileAcc >> day;
	inFileAcc >> year;
	inFileAcc >> accNumber;

	inFileAcc >> accType;

	inFileAcc >> accBalance;

	getline(inFileAcc, accName);

	date.SetDate(month, day, year);
	while(inFileAcc)
	{

		if(accType == "Checking" && inFileAcc)
		{
			checkingAccount = new Checking(accNumber, accBalance, accName);
			currentNode.InsertTail(checkingAccount);
		}
		else if(accType == "Saving" && inFileAcc)
		{
			savingsAccount = new Savings(accNumber, accBalance, accName, .10);
			currentNode.InsertTail(savingsAccount);
		}
		else if(accType == "MM" && inFileAcc)
		{
			mmAccount = new MoneyMarket(accNumber, accBalance, accName, .20);
			currentNode.InsertTail(mmAccount);
		}

		inFileAcc >> month;
		inFileAcc >> day;
		inFileAcc >> year;
		inFileAcc >> accNumber;

		inFileAcc >> accType;

		inFileAcc >> accBalance;

		getline(inFileAcc, accName);

		date.SetDate(month, day, year);

	}
	currentNode.DisplayList(oFile, date);
	oFile << endl;


	date.SetPrevDate(month, day, year);

	while(inFileTrans)
	{
		inFileTrans >> month;
		inFileTrans >> day;
		inFileTrans >> year;
		inFileTrans >> accNumber;
		inFileTrans >> accAmount;

		inFileTrans >> accAction;

		date.SetDate(month, day, year);


		if(accAction == "Deposit" && inFileTrans)
		{
			currentNode.DepositFunds(oFile, date, accNumber, accAmount);
		}
		else if(accAction == "Withdrawal" && inFileTrans)
		{
			currentNode.WithdrawFunds(oFile, date, accNumber, accAmount);

		}
		else if(accAction == "Transfer" && inFileTrans)
		{
			inFileTrans >> accNumberTwo;
			currentNode.TransferFunds(oFile, date, accNumber, accNumberTwo, accAmount);
		}


	}


	inFileAcc.close();
	oFile.close();



	return 0;
}
