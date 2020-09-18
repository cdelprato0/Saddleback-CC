/*
 * Student.cpp
 *
 *  Created on: Apr 22, 2015
 *      Author: cdelprato0
 */

#include "Student.h"


//OVERLOADING: Same name ,same scope, different parameters signatures
Student::Student()
{
	//Person() is automatically constructed
	numUnits = -1;
}

//NON-DEFAULT Constructor
Student::Student(string pName, int pAge, char pGender, //DATA Members from person
		int pUnits) : Person(pName, pAge, pGender)	//Person(pName, pAge, pGender)
												   	    //calls the NON-Default constructor for person
{
	numUnits = pUnits;
}

Student::~Student()
{

}


//GETTERS
int Student::GetUnits() const
{

	return numUnits;
}





//SETTERS
void Student::SetUnits(int pUnits)
{
	numUnits = pUnits;
}

float Student::CalcTuition()const
{
	cout << "Not enough information to calculate tuition" << endl;

	return numUnits * -1.0;
}

//OVERWRITING: Same name, different scope, same parameters
string Student::Display()const		//Overwriting: Person::Display();
{

	//string personString = Person::Display(); //Polymorphism

	//NAME					  AGE   GENDER   UNITS
	//--------------------   ----- -------- -------

	ostringstream o;

	o << left;
	o << setw(20) << name;
	o << right;
	o << setw(5) << age;
	o << right;
	o << setw(8) << gender;
	o << right;
	o << setw(8) << numUnits;

	return o.str();
}

//DYNAMIC POLYMORPHISM: OVERWRITING: Same name, different scope, same parameters
string Student::VDisplay()const		//Overwriting: Person::Display();
{

	//string personString = Person::Display(); //Polymorphism

	//NAME					  AGE   GENDER   UNITS
	//--------------------   ----- -------- -------

	ostringstream o;

	o << left;
	o << setw(20) << name;
	o << right;
	o << setw(5) << age;
	o << right;
	o << setw(8) << gender;
	o << right;
	o << setw(8) << numUnits;

	return o.str();
}
