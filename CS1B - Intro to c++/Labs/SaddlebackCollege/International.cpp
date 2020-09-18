/*
 * International.cpp
 *
 *  Created on: Apr 22, 2015
 *      Author: cdelprato0
 */

#include "International.h"

International::International()
{

}

International::International(string pName, int pAge, char pGender, int pUnits,
		string pCitizen) : Student(pName, pAge, pGender, pUnits)
{
	citizenOf = pCitizen;
}

International::~International()
{
	// TODO Auto-generated destructor stub
}

string International::GetCitizenOf()const
{
	return citizenOf;
}

float International::CalcTuition()const
{
	return numUnits * 260;
}

string International::Display()const
{
	//NAME					  AGE   GENDER   UNITS   Citizen Of
	//--------------------   ----- -------- ------- ------------

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
	o << setw(17) << citizenOf;

	return o.str();
}

string International::VDisplay()const
{
	//NAME					  AGE   GENDER   UNITS   Citizen Of
	//--------------------   ----- -------- ------- ------------

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
	o << setw(17) << citizenOf;

	return o.str();
}

void International::SetCitizenOf(string pCitizen)
{
	citizenOf = pCitizen;
}
