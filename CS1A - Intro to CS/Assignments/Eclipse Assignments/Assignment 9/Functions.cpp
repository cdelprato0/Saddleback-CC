#include "Header.h"


//PrintHeader - Determines if the program is an assignment or lab and
//				displays the programmers info in the output.
void PrintHeader(string asName, char asType, int asNum)
{
	cout << left;
	cout << "********************************************************";
	cout << "\n* PROGRAMMED BY : BBC";
	cout << "\n* " << setw(14) << "Student ID" << ": 382108";
	cout << "\n* " << setw(14) << "Class" << ": CS1A --> Mon/Wed 9:30am";
	cout << "\n* ";
	if(toupper(asType) == 'L')
	{
		cout << "LAB #" << setw(9);
	}
	else
	{
		cout << "ASSIGNMENT #" << setw(2);
	}
	cout << asNum << ": " << asName;
	cout << "\n******************************************************\n\n";
	cout << right;
}
/**************************************************************************
 * GetSalesInfo
 * ________________________________________________________________________
 * This function mainly is for the user to enter the requested input. The
 * user enters the account number, the date, the county code that they live
 * in, the sales amount, and the weight of the sale.
 * ________________________________________________________________________
 * INPUTS -
 * 		accNumber 	- User enters the customer's account number.
 * 		month 		- User enters the month.
 * 		day 		- the user enters the day.
 * 		year		- he user enter the year.
 * 		countyCode  - The user enters the customer county tax code.
 * 		price 		- The price of the sale.
 * 		weight 		- The total weight of the whole sale.
 *************************************************************************/
void GetSalesInfo(int& accNumber, int& month, int& day, int& year,
				char& countyCode, float& price, int& weight)
{
// CALC - Setting all values to zero.
	accNumber = 0;
	month = 0;
	day = 0;
	year = 0;
	price = 0;
	weight = 0;

	cout << "Please Enter your Account Number: ";
	cin >> accNumber;

	cout << "Please Enter the Sales Date." << endl;

	cout << "Enter Month: ";
	cin >> month;

	cout << "Enter Day: ";
	cin >> day;

	cout << "Enter Year: ";
	cin >> year;
	cin.ignore(10000, '\n');

	cout << "Please Enter the County Code: ";
	cin.get(countyCode);
	cin.ignore(10000, '\n');

	cout << "Please Enter the Sales Amount: ";
	cin >> price;

	cout << "Please Enter the Weight: ";
	cin >> weight;
	cout << endl;
}

/**************************************************************************
 * CalcDiscount
 * ________________________________________________________________________
 * This function calculates the discount by using the month it was ordered
 * and the current price the sale was. Then calculates what the new price
 * is with the discount taken out.
 * ________________________________________________________________________
 * INPUTS -
 * 		month 		- User enters the month.
 * 		price 		- The price of the sale.
 *
 * 	OUTPUTS -
 * 		discount 	- The customer's discount on their sale.
 * 		newPrice    - The new price with the discount taken out.
 *************************************************************************/

float CalcDiscount(int& month, float& discount, float& price,
		float& newPrice)
{
	discount = 0;			// CALC - Setting all values to zero.

	if(month <= 5)
	{
		discount = price * 0.05;
	}
	else if(month <= 8)
	{
		discount = price * 0.10;
	}
	else
	{
		discount = price * 0.15;
	}
	newPrice = price - discount;
	return discount;
}

/**************************************************************************
 * CalcSalesTax
 * ________________________________________________________________________
 * This function calculates the sales tax on the order. The user is able
 * to enter the county tax code , and the new price. Tax needs to be
 * calculated AFTER discount has been taken out of the original price.
 * ________________________________________________________________________
 * INPUTS -
 * 		countyCode  - The user enters the customer county tax code.
 *		newPrice    - The new price with the discount taken out.
 *
 *	OUTPUTS -
 *		tax  		- The tax on the price of the sale.
 *
 *************************************************************************/

float CalcSalesTax(char countyCode, float& newPrice, float& tax)
{
	const float O_C_TAX = 0.0775;		//Constants for never changing tax
	const float S_D_TAX = 0.0825;		//information.
	const float L_A_TAX = 0.0800;

	tax = 0;			// CALC - Setting all values to zero.

	if(countyCode == 'O' || countyCode == 'o')
	{
		tax = newPrice * O_C_TAX;
	}
	else if(countyCode == 'S' || countyCode == 's')
	{
		tax = newPrice * S_D_TAX;
	}
	else if(countyCode == 'L' || countyCode == 'l')
	{
		tax = newPrice * L_A_TAX;
	}
	return tax;
}
/**************************************************************************
 * CalcShipping
 * ________________________________________________________________________
 * This function calculates the shipping that will be added to the cost of
 *  the order. It uses the the weight of the sale to process what category
 *  the shipping is under. Flat rate of $5.00. With weight above 25, it
 *  adds $0.10 for each lb over 25 and with weight over 50, it adds $0.07
 *  to each lb over 50.
 * ________________________________________________________________________
 * INPUTS -
 * 		weight 		- The total weight of the whole sale.
 *
 * 	OUTPUTS -
 * 		shipping 	- The cost of shipping the sale to the customer.
 *************************************************************************/

float CalcShipping(int& weight, float& shipping)
{
	int count; 			// Keeps count of for the FOR loop.
	shipping = 0;		// CALC - Setting all values to zero.

	if(weight <= 25)
	{
		shipping = 5.00;
	}
	else if(weight <= 50)
	{
		shipping = 5.00;
		for(count = 26; count <= weight; count = count +1)
		{
			shipping = shipping + .10;
		}
	}
	else if(weight > 50)
	{
		shipping = 5.00;
		for(count = 51; count <= weight; count = count +1)
		{
			shipping = shipping + .07;
		}
	}
	return shipping;
}
/**************************************************************************
 * OutputInvoice
 * ________________________________________________________________________
 * This function outputs the customer's invoice with all details that were
 * entered. Calculates how much the customer will exactly owe.
 * ________________________________________________________________________
 * OUTPUTS -
 * 		accNumber 	- User enters the customer's account number.
 * 		month 		- User enters the month.
 * 		day 		- The user enters the day.
 * 		year		- The user enter the year.
 * 		county 		- The county the customer is ordering from
 * 		price 		- The price of the sale.
 * 		newPrice    - The new price with the discount taken out.
 * 		shipping 	- The cost of shipping the sale to the customer.
 * 		tax  		- The tax on the price of the sale.
 * 		discount 	- The customer's discount on their sale.
 * 		totalDue	- The total amount that the customer owes for the sale.
 *************************************************************************/

void OutputInvoice(int& accNumber, int& month, int& day, int& year,
		float& price, float& discount, float& tax, float& shipping,
		char countyCode, float& newPrice)
{
	string county;		//OUTPUT - The county the customer is ordering from
	float totalDue;		//OUTPUT - The total amount that the customer owes
						//		for the sale.
	totalDue = (newPrice) + (tax + shipping);

	if(countyCode == 'O' || countyCode == 'o')
	{
		county = "Orange County";
	}
	else if(countyCode == 'S' || countyCode == 's')
	{
		county = "San Diego";
	}
	else if(countyCode == 'L' || countyCode == 'l')
	{
		county = "Los Angles";
	}

	cout << left;
	cout << setw(41) << "ACCOUNT NUMBER" << "COUNTY" << endl;
	cout << "\t" << accNumber << right << setw(41) << county;
	cout << endl << endl;

	cout << left;
	cout << "DATE OF SALE: " << month << "/" << day << "/" << year;
	cout << endl << endl << endl;

	cout << setprecision(2) << fixed;
	cout << "SALE AMOUNT:" << right << setw(8) << "$" << setw(8)
			<< price << endl;
	cout << "DISCOUNT:" << right << setw(11) << "$" << setw(8)
			<< discount << endl;
	cout << "SALES TAX:" << right << setw(10) << "$" << setw(8)
			<< tax << endl;
	cout << "SHIPPING:" << right << setw(11) << "$" << setw(8)
			<< shipping << endl;
	cout << "TOTAL DUE:" << right << setw(10) << "$" << setw(8)
			<< totalDue << endl << endl << endl;

}
