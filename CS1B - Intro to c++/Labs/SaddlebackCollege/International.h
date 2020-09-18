/*
 * International.h
 *
 *  Created on: Apr 22, 2015
 *      Author: cdelprato0
 */

#ifndef INTERNATIONAL_H_
#define INTERNATIONAL_H_

#include "Student.h"

class International: public Student //SUB-CLASS of Student_NOT A BASE-CLASS_EXTENDS Student
{
public:
	International();
	International(string pName, int pAge, char pGender, int pUnits,
			string pCitizen);

	virtual ~International();


	//GETTERS
	string GetCitizenOf()const;
	float CalcTuition()const; //PER UNIT COST $260 * numUnits
	string Display()const;
	virtual string VDisplay()const;

	//SETTERS

	void SetCitizenOf(string pCitizen);


private: //END of Inheritance Chain
	string citizenOf;
};

#endif /* INTERNATIONAL_H_ */
