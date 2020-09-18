/**************************************************************************
 * AUTHORS      : BBC
 * STUDENT IDs  : 382108
 * ASSIGNMENT #6: Saddleback Bank - OOP
 * CLASS		: CS1B
 * SECTION		: MW 8:30a
 * DUE DATE     : 5-7-2015
 *************************************************************************/
#include "DateClass.h"
#include<string>

DateClass::DateClass()
{
	dateMonth = 0;
	dateDay = 0;
	dateYear = 0;
	prevDateMonth = 0;
	prevDateDay = 0;
	prevDateYear = 0;

}


DateClass::DateClass(unsigned short month, unsigned short day, unsigned short year)
{
	dateMonth = month;
	dateDay = day;
	dateYear = year;

}


DateClass::~DateClass() {
	// TODO Auto-generated destructor stub
}


void DateClass::SetDate(unsigned short month, unsigned short day, unsigned short year)
{

	dateMonth = month;
	dateDay = day;
	dateYear = year;

}

void DateClass::SetPrevDate(unsigned short prevMonth, unsigned short prevDay, unsigned short prevYear)
{
	prevDateMonth = prevMonth;
	prevDateDay   = prevDay;
	prevDateYear  = prevYear;
}

string DateClass::GetDate()const
{
	ostringstream currentDate;


	if(dateMonth <= 9)
	{
		currentDate << '0' << dateMonth << '/'
				    << '0' << dateDay   << '/' << dateYear;
	}
	else
		currentDate << dateMonth << '/' << '0' << dateDay << '/' << dateYear;



	return currentDate.str();
}


string DateClass::GetPrevDate()const
{
	ostringstream prevDate;

	if(dateMonth <= 9)
	{
		prevDate << '0' << prevDateMonth << '/'
				    << '0' << prevDateDay   << '/' << prevDateYear;
	}
	else
		prevDate << dateMonth << '/' << '0' << dateDay << '/' << dateYear;

	return prevDate.str();

}
unsigned short DateClass::GetYear()const
{
	return dateYear;
}


unsigned short DateClass::GetMonth()const
{
	return dateMonth;
}


unsigned short DateClass::GetDay()const
{
	return dateDay;
}


