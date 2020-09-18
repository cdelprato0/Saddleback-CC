/*
 * Pet.cpp
 *
 *  Created on: Apr 29, 2015
 *      Author: cdelprato0
 */

#include "Pet.h"

Pet::Pet()
{
	price  = -1.0;
	isSold = false;

}
Pet::Pet(string pName, float pPrice, int pAge, char pGender)
			: Animal(pAge, pGender)
{
	name = pName;
	price = pPrice;
	isSold = false;
}

Pet::~Pet() {
	// TODO Auto-generated destructor stub
}

//Getters
string Pet::GetName()const
{
	return name;
}

float Pet::GetPrice()const
{
	return price;
}

bool Pet::IsSold()const
{
	return isSold;
}

string Pet::Display()const
{
	ostringstream oss;

	oss << left;
	oss << setw(15) << name;
	oss << setw(5) << price;
	oss << setw(10) << (isSold? "Sold" : "For Sale");
	oss << Animal::Display();

	return oss.str();

}


//Setters
void Pet::SetName(string pName)
{
	name = pName;
}

void Pet::SetPrice(float pPrice)
{
	price = pPrice;
}

void Pet::SellPet()
{
	isSold = true;
}
