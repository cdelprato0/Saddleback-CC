/*
 * Pet.h
 *
 *  Created on: Apr 29, 2015
 *      Author: cdelprato0
 */

#ifndef PET_H_
#define PET_H_

#include "Animal.h"
#include <string>

class Pet: public Animal
{
public:
	Pet();
	Pet(string pName, float pPrice, int pAge, char pGender);

	virtual ~Pet();

	//Getters
	string GetName()const;
	float GetPrice()const;
	bool IsSold()const;
	virtual string Display()const;

	//Setters
	void SetName(string pName);
	void SetPrice(float pPrice);
	void SellPet(); 			//Sets isSold = true

protected:
	string name;
	float price;
	bool isSold;

};

#endif /* PET_H_ */
