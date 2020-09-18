/*
 * PetShop.cpp
 *
 *  Created on: Apr 29, 2015
 *      Author: cdelprato0
 */

#include "PetShop.h"

PetShop::PetShop()
{
	//Initializing Inventory
	for(int i = 0; i < 5; i++)
	{
		inventory[i] = NULL;
	}

}

PetShop::~PetShop()
{
	//Deallocate Inventory
	for(int i = 0; i < 5; i++)
	{
		delete inventory[i];
	}
}

//Getters
void PetShop::DisplayInventory()const
{

	//Print Inventory
	for(int i = 0; i < 5; i++)
	{
		if(inventory[i] != NULL)
		{
			cout << inventory[i]->Display() << endl;
		}
	}
}

//Setters
void PetShop::SellPet(int petNumber)
{
	if(inventory[petNumber] != NULL)
	{
		inventory[petNumber]->Pet::SellPet();
	}
}

void PetShop::AddPet(Pet *pPet)
{
	int availableIndex = 0;

	while(inventory[availableIndex] != NULL)
	{
		availableIndex++;
	}
	if(availableIndex < 5)
	{
		inventory[availableIndex] = pPet;
	}

}
