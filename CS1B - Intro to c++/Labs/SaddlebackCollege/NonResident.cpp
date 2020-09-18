/*
 * NonResident.cpp
 *
 *  Created on: Apr 22, 2015
 *      Author: cdelprato0
 */

#include "NonResident.h"

NonResident::NonResident()
{
	numMonthsInCA = 0;

}

NonResident::NonResident(string pName, int pAge, char pGender, int pUnits,
			int pMonths) : Student(pName, pAge, pGender, pUnits)
{
	numMonthsInCA = pMonths;
}

NonResident::~NonResident()
{
	// TODO Auto-generated destructor stub
}

int NonResident::GetMonthsInCA()const
{
	return numMonthsInCA;
}

float NonResident::CalcTuition()const
{
	return numUnits * 240;
}

string NonResident::Display()const
{
	ostringstream o;

	o << left;
	o << setw(20) << name;
	o << right;
	o << setw(5) << age;
	o << right;
	o << setw(8) << gender;
	o << right;
	o << setw(8) << numUnits;
	o << right;
	o << setw(8) << CalcTuition();
	o << right;
	o << setw(12) << numMonthsInCA;

	return o.str();
}

string NonResident::VDisplay()const
{
	ostringstream o;

	o << left;
	o << setw(20) << name;
	o << right;
	o << setw(5) << age;
	o << right;
	o << setw(8) << gender;
	o << right;
	o << setw(8) << numUnits;
	o << right;
	o << setw(8) << CalcTuition();
	o << right;
	o << setw(12) << numMonthsInCA;

	return o.str();
}

void NonResident::SetMonthsInCA(int pMonths)
{
	numMonthsInCA = pMonths;
}
