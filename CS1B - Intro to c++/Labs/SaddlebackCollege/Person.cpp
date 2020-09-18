/*
 * Person.cpp
 *
 *  Created on: Apr 22, 2015
 *      Author: cdelprato0
 */

#include "Person.h"

//OVERLOADING: Same name ,same scope, different parameters signatures
Person::Person()
{
	age = 0;
	gender = '?';
	SSN = 123456789;

}

Person::Person(string pName, int pAge, char pGender)
{
	name = pName;
	age = pAge;
	gender = pGender;
}



Person::~Person()
{

}


string Person::GetName()const
{
	return name;
}

int Person::GetAge()const
{
	return age;
}

char Person::GetGender()const
{
	return gender;
}


//OVERLOADING: Same name ,same scope, different parameters signatures
void Person::ChangeValue(int pAge)
{
	age = pAge;
}

void Person::ChangeValue(char pGender)
{
	gender = pGender;
}

void Person::ChangeValue(string pName)
{
	name = pName;
}



void Person::InitializeMembers(string n, int a, char g)
{
	name = n;
	age = a;
	gender = g;

}

string Person::Display()const
{
	//NAME					  AGE   GENDER
	//--------------------   ----- --------

	ostringstream o;

	o << left;
	o << setw(20) << name;
	o << right;
	o << setw(5) << age;
	o << right;
	o << setw(8) << gender;

	return o.str();

}
