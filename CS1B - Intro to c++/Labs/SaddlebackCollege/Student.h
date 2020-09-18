/*
 * Student.h
 *
 *  Created on: Apr 22, 2015
 *      Author: cdelprato0
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include "Person.h"

class Student: public Person //IS-A: Student IS a Person
							 //SUB-CLASS of Person, BASE-CLASS of International, Continuing, Non-Resident
							 //Student EXTENDS Person
{

	//ACCESS TO ALL PUBLIC AND PROTECTED MEMEBERS
public:

	//OVERLOADING: Same name ,same scope, different parameters signatures
	Student();//DEFAULT Constructor

	//NON-DEFAULT Constructor
	Student(string pName, int pAge, char pGender, //DATA Members from person
			int pUnits);

	virtual ~Student();


	//GETTERS
	int GetUnits() const;

	float CalcTuition()const;

	//OVERWRITING: Same name, different scope, same parameters
	string Display()const; //Overwriting: Person::Display();

	//DYNAMIC POLYMORPHISM: OVERWRITING: Same name, different scope, same parameters
	virtual string VDisplay() const;


	//SETTERS
	void SetUnits(int pUnits);




protected:
	int numUnits; //HAS-A

};

#endif /* STUDENT_H_ */
