/*
 * Continuing.cpp
 *
 *  Created on: Apr 22, 2015
 *      Author: cdelprato0
 */

#include "Continuing.h"

Continuing::Continuing()
{
	financialAid = 0;

}

Continuing::Continuing(string pName, int pAge, char pGender, int pUnits,
			float fAid) : Student(pName, pAge, pGender, pUnits)
{
	financialAid = fAid;
}

Continuing::~Continuing()
{
	// TODO Auto-generated destructor stub
}


float Continuing::GetFinanicalAid()const
{
	return financialAid;
}


float Continuing::CalcTuition()const
{
	return numUnits * 42 - financialAid;
}

string Continuing::Display()const
{
	//NAME					  AGE   GENDER   UNITS   TUITION   FINANCIAL AID
	//--------------------   ----- -------- ------- --------- ---------------

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
	o << setw(12) << financialAid;

	return o.str();
}

string Continuing::VDisplay()const
{
	//NAME					  AGE   GENDER   UNITS   TUITION   FINANCIAL AID
	//--------------------   ----- -------- ------- --------- ---------------

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
	o << setw(12) << financialAid;

	return o.str();
}

void Continuing::SetFinancialAid(float fAid)
{
	financialAid = fAid;
}
