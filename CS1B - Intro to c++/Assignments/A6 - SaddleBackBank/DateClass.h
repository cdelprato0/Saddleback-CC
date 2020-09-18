/**************************************************************************
 * AUTHORS      : BBC
 * STUDENT IDs  : 382108
 * ASSIGNMENT #6: Saddleback Bank - OOP
 * CLASS		: CS1B
 * SECTION		: MW 8:30a
 * DUE DATE     : 5-7-2015
 *************************************************************************/
#ifndef DATECLASS_H_
#define DATECLASS_H_

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <ctime>
using namespace std;

class DateClass
{
public:
	DateClass();
	DateClass(unsigned short month, unsigned short day, unsigned short year);
	virtual ~DateClass();

	//GETTERS
	string GetDate()const;
	unsigned short GetYear()const;
	unsigned short GetMonth()const;
	unsigned short GetDay()const;
	string GetPrevDate()const;


	//SETTERS
	void SetDate(unsigned short month, unsigned short day, unsigned short year);
	void SetPrevDate(unsigned short prevMonth, unsigned short prevDay, unsigned short prevYear);



private:

	unsigned short dateMonth;
	unsigned short dateDay;
	unsigned short dateYear;

	unsigned short prevDateMonth;
	unsigned short prevDateDay;
	unsigned short prevDateYear;

};


#endif /* DATECLASS_H_ */
