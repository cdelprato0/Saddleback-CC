/*
 * Birds.h
 *
 *  Created on: Apr 29, 2015
 *      Author: cdelprato0
 */

#ifndef BIRDS_H_
#define BIRDS_H_

#include "Pet.h"

class Birds: public Pet
{
public:
	Birds();
	Birds(bool pCanFly, string pName, float pPrice, int pAge, char pGender);

	virtual ~Birds();

	//Getters
	bool CanFly()const;
	virtual void Speak()const;
	virtual string Display()const;

	//Setters
	void SetCanFly(bool pCanFly);


protected:
	bool canFly;
};

#endif /* BIRDS_H_ */
