/*
 * PetShop.h
 *
 *  Created on: Apr 29, 2015
 *      Author: cdelprato0
 */

#ifndef PETSHOP_H_
#define PETSHOP_H_

#include "Pet.h"

class PetShop
{
public:
	PetShop();
	virtual ~PetShop();

	//Getters
	void DisplayInventory()const;

	//Setters
	void SellPet(int petNumber);
	void AddPet(Pet *pPet);

private:
	Pet* inventory[5];

};

#endif /* PETSHOP_H_ */
