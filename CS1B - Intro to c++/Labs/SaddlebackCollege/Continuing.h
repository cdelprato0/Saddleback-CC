/*
 * Continuing.h
 *
 *  Created on: Apr 22, 2015
 *      Author: cdelprato0
 */

#ifndef CONTINUING_H_
#define CONTINUING_H_

#include "Student.h"

class Continuing: public Student //SUB-CLASS of Student_NOT A BASE-CLASS_EXTENDS Student
{
public:
	Continuing();
	Continuing(string pName, int pAge, char pGender, int pUnits,
			float fAid);
	virtual ~Continuing();


	//GETTERS
	float GetFinanicalAid()const;
	float CalcTuition()const; //PER UNIT COST $42 * numUnits - financialAid
	string Display()const;
	virtual string VDisplay()const;

	//SETTERS
	void SetFinancialAid(float fAid);


private: //END of Inheritance Chain
	float financialAid;

};

#endif /* CONTINUING_H_ */
