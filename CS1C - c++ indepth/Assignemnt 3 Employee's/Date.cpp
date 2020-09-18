/**************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #3:CS1C Corporation
 * CLASS	    :CS1C
 * SECTION	    :M/W 2:00 PM
 *************************************************************************/
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

/******************************************************************************
 * METHOD OutputDate
 * ____________________________________________________________________________
 * This method will use ostringstream in order to be able to have the return
 * type a string. Use of ostringstream is to make it easier to output in a
 * Different method
 *
 * returns -> the contents as a string
 ******************************************************************************/
string Date::OutputDate()const
{
	ostringstream oss;

	oss << month << "/" << day << "/" << year;

	return oss.str();
}//END OF METHOD
