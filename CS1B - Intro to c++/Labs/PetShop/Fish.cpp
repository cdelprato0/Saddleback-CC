/*
 * Fish.cpp
 *
 *  Created on: Apr 29, 2015
 *      Author: cdelprato0
 */

#include "Fish.h"

Fish::Fish()
{
	isFreshWater = false;

}

Fish::Fish(bool pIsFreshWater, string pName, float pPrice, int pAge, char pGender)
						: Pet(pName, pPrice, pAge, pGender)
{
	isFreshWater = pIsFreshWater;
}
Fish::~Fish()
{
	// TODO Auto-generated destructor stub
}

//Getters
bool Fish::IsFreahWater()const
{
	return isFreshWater;
}

void Fish::Speak()const
{
	cout << "Fish: " << name << " says Bloooooop! Blooooop!" << endl;
}

string Fish::Display()const
{
	ostringstream oss;

	oss << left;
	oss << "FISH: ";
	oss << setw(10) << (isFreshWater? "Fresh" : "Salty");
	oss << Pet::Display();

	return oss.str();
}


//Setters
void Fish::SetIsFreahWater(bool pIsFreshWater)
{
	isFreshWater = pIsFreshWater;
}

