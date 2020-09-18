/*******************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #7:CS1C Overloading
 * CLASS	    :CS1C
 * SECTION	    :M/W 2:00 PM
 *******************************************************************************/
#include "Date.h"

//DEFAULT CONSTRUCTOR
Date::Date()
{
	//Initializes all variables to zero
	month = 0;
	day = 0;
	year = 0;
}//END OF METHOD

/******************************************************************************
 * METHOD Employee - NON-DEFALUT Constructor
 * ____________________________________________________________________________
 * This method uses overloading to set in variables that have been entered
 * into the parameters and assigns them to the attributes
 *
 ******************************************************************************/
Date::Date(int aMonth, int aDay, int aYear)
{
	month = aMonth;
	day = aDay;
	year = aYear;

}//END OF METHOD

//DEFAULT DE-CONSTRUCTOR
Date::~Date()
{

}//END OF METHOD

/******************************************************************************
 * METHOD SetMonth
 * ____________________________________________________________________________
 * This method will set the Month of the hire date
 *
 * returns -> nothing
 ******************************************************************************/
void Date::SetMonth(int aMonth)
{
	month = aMonth;
}//END OF METHOD

/******************************************************************************
 * METHOD SetDay
 * ____________________________________________________________________________
 * This method will set the Day of the hire date
 *
 * returns -> nothing
 ******************************************************************************/
void Date::SetDay(int aDay)
{
	day = aDay;
}//END OF METHOD

/******************************************************************************
 * METHOD SetYear
 * ____________________________________________________________________________
 * This method will set the Year of the hire date
 *
 * returns -> nothing
 ******************************************************************************/
void Date::SetYear(int aYear)
{
	year = aYear;
}//END OF METHOD

int Date::GetMonth()const
{
	return month;
}//END OF METHOD

int Date::GetDay()const
{
	return day;
}//END OF METHOD

int Date::GetYear()const
{
	return year;
}//END OF METHOD

