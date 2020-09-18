/*
 * Birds.cpp
 *
 *  Created on: Apr 29, 2015
 *      Author: cdelprato0
 */

#include "Birds.h"

Birds::Birds()
{
	canFly = false;

}

Birds::Birds(bool pCanFly, string pName, float pPrice, int pAge, char pGender)
											: Pet(pName, pPrice, pAge, pGender)
{
	canFly = pCanFly;
}

Birds::~Birds() {
	// TODO Auto-generated destructor stub
}

//Getters
bool Birds::CanFly()const
{
	return canFly;
}

void Birds::Speak()const
{
	cout << "Bird: " << name << " says Mine! Mine! Mine!" << endl;
}

string Birds::Display()const
{
	ostringstream oss;

	oss << left;
	oss << "BIRD: ";
	oss << setw(10) << (canFly? "Can Fly" : "Grounded");
	oss << Pet::Display();

	return oss.str();

}


//Setters
void Birds::SetCanFly(bool pCanFly)
{
	canFly = pCanFly;
}
