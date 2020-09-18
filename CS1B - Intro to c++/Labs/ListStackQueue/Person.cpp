/*
 * Person.cpp
 *
 *  Created on: Apr 13, 2015
 *      Author: cdelprato0
 */

#include "Person.h"

Person::Person()
{
	age = 0;

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

void Person::SetName(string newName)
{
	name = newName;

}
void Person::SetAge(int newAge)
{
	age = newAge;
}

void Person::Display()const
{
	cout << "Name: " << name << "  " << "Age: " << age << " \n";
}
