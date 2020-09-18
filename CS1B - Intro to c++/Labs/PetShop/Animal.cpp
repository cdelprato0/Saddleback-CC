/*
 * Animal.cpp
 *
 *  Created on: Apr 29, 2015
 *      Author: cdelprato0
 */

#include "Animal.h"

Animal::Animal()
{
	age    = -1;
	gender = '?';

}

Animal::Animal(int pAge, char pGender)
{
	age    = pAge;
	gender = pGender;
}


Animal::~Animal()
{
	// TODO Auto-generated destructor stub
}

//Getters
int Animal::GetAge()const
{
	return age;
}

char Animal::GetGender()const
{
	return gender;
}

void Animal::Speak()const
{
	cout << "Animal is Speaking " << endl;
}

string Animal::Display()const
{
	ostringstream oss;

	oss << left;
	oss << setw(5) << age;
	oss << setw(5) << gender;

	return oss.str();
}

//Setters
void Animal::ChangeAge(int pAge)
{
	age = pAge;
}

void Animal::ChangeGender(char pGender)
{
	gender = pGender;
}
