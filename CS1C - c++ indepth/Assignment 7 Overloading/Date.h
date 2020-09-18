/*******************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #7:CS1C Overloading
 * CLASS	    :CS1C
 * SECTION	    :M/W 2:00 PM
 *******************************************************************************/
#ifndef DATE_H_
#define DATE_H_

#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Date {
public:

	/***************************
	 * CONSTRUCTOR * DESTRUCTOR*
	 ***************************/
	Date(); //DEFAULT CONSTRUCTOR
	Date(int aMonth, int aDay, int aYear); //NON-DEFAULT CONSTRUCTOR
	virtual ~Date(); //DEFAULT DE-CONSTRUCTOR

	/************
	 * MUTATORS *
	 ************/
	void SetMonth(int aMonth);  //Sets the month of the hire date
	void SetDay(int aDay);      //Sets the day of the hire date
	void SetYear(int aYear);    //Sets the year of the hire date

	/*************
	 * ACCESSORS *
	 *************/
	int GetMonth()const;
	int GetDay()const;
	int GetYear()const;

private:
	int month;
	int day;
	int year;
};

#endif /* DATE_H_ */
