/**************************************************************************
 * AUTHORS      : BBC
 * STUDENT IDs  : 382108
 * ASSIGNMENT #9: Functions
 * CLASS		: CS1A
 * SECTION		: MW 9:30a
 * DUE DATE     : 11-24-14
 *************************************************************************/

#include "Header.h"

/**************************************************************************
 * SoCal Outfitters catalog
 * ________________________________________________________________________
 * This program will obtain input from a user such as account number, the
 * date, what county they live in, the amount of their sale and the weight
 * of the total sale. It will be able to calculate the discount they
 * receive from when they ordered, the sales tax after the discount, the
 * shipping of their product and will output an invoice for them.
 * ________________________________________________________________________
 * INPUTS -
 * 		accNumber 	- User enters the customer's account number.
 * 		month 		- User enters the month.
 * 		day 		- the user enters the day.
 * 		year		- he user enter the year.
 * 		countyCode  - The user enters the customer county tax code.
 * 		price 		- The price of the sale.
 * 		weight 		- The total weight of the whole sale.
 *
 * OUTPUTS -
 * 		accNumber 	- User enters the customer's account number.
 * 		month 		- User enters the month.
 * 		day 		- the user enters the day.
 * 		year		- he user enter the year.
 * 		county 		- The county the customer is ordering from
 * 		price 		- The price of the sale.
 * 		newPrice    - The new price with the discount taken out.
 * 		shipping 	- The cost of shipping the sale to the customer.
 * 		tax  		- The tax on the price of the sale.
 * 		discount 	- The customer's discount on their sale.
 * 		totalDue	- The total amount that the customer owes for the sale.
 *************************************************************************/

int main()
{
	PrintHeader("Functions", 'A', 9);

	int accNumber;		// User enters the customer's account number.
	char countyCode;	// The user enters the customer county tax code.
	float price;		// The price of the sale.
	int weight;			// The total weight of the whole sale.
	int month; 			// User enters the month.
	int day;			// The user enters the day.
	int year;	 		// The user enter the year.
	float discount;	 	// The customer's discount on their sale.
	float shipping;		// The cost of shipping the sale to the customer.
	float tax;			// The tax on the price of the sale.
	float newPrice;		// The new price with the discount taken out.
	int count;			// Keeps count of for the FOR loop.

	for(count = 1; count <= 3; count = count + 1)
	{
		GetSalesInfo(accNumber, month, day , year, countyCode, price, weight);

		CalcDiscount(month, discount, price, newPrice);

		CalcSalesTax(countyCode, newPrice, tax);

		CalcShipping(weight, shipping);

		OutputInvoice(accNumber, month, day, year, price, discount, tax,
				shipping, countyCode, newPrice);
	}

	return 0;
}
