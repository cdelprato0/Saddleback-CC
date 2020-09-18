/*
 * Fish.h
 *
 *  Created on: Apr 29, 2015
 *      Author: cdelprato0
 */

#ifndef FISH_H_
#define FISH_H_

#include "Pet.h"

class Fish: public Pet
{
public:
	Fish();
	Fish(bool pIsFreshWater, string pName, float pPrice, int pAge, char pGender);

	virtual ~Fish();

	//Getters
	bool IsFreahWater()const;
	virtual void Speak()const;
	virtual string Display()const;

	//Setters
	void SetIsFreahWater(bool pIsFreshWater);

protected:
	bool isFreshWater;
};

#endif /* FISH_H_ */
