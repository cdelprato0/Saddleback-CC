/*
 * NonResident.h
 *
 *  Created on: Apr 22, 2015
 *      Author: cdelprato0
 */

#ifndef NONRESIDENT_H_
#define NONRESIDENT_H_

#include "Student.h"

class NonResident: public Student //SUB-CLASS of Student_NOT A BASE-CLASS_EXTENDS Student
{
public:
	NonResident();
	NonResident(string pName, int pAge, char pGender, int pUnits,
			int pMonths);
	virtual ~NonResident();


	//GETTERS
	int GetMonthsInCA()const;
	float CalcTuition()const; //PER UNIT COST $240 * numUnits
	string Display()const;
	virtual string VDisplay()const;

	//SETTERS
	void SetMonthsInCA(int pMonths);



private: //END of Inheritance Chain
	int numMonthsInCA;

};

#endif /* NONRESIDENT_H_ */
