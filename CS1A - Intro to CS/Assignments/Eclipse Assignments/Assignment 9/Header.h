#ifndef HEADERFILER_H_
#define HEADERFILER_H_

#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
using namespace std;

//This is a header file that stores all of the pre-processors in one file.
//Making it easier to organize code.

void PrintHeader(string asName, char asType, int asNum);

void GetSalesInfo(int& accNumber, int& month, int& day, int& year,
				char& countyCode, float& price, int& weight);

float CalcDiscount(int& month, float& discount, float& price,
		float& newPrice);

float CalcSalesTax(char countyCode, float& newPrice, float& tax);

float CalcShipping(int& weight, float& shipping);

void OutputInvoice(int& accNumber, int& month, int& day, int& year,
		float& price, float& discount, float& tax, float& shipping,
		char countyCode, float& newPrice);





#endif /* HEADERFILER_H_ */
