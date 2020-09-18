/*
 * Animal.h
 *
 *  Created on: Apr 29, 2015
 *      Author: cdelprato0
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_\

#include <sstream>
#include <iomanip>
#include <iostream>
using namespace std;

class Animal
{
public:
	Animal();
	Animal(int pAge, char pGender);

	virtual ~Animal();

	//Getters
	int GetAge()const;
	char GetGender()const;
	virtual void Speak()const;
	virtual string Display()const;

	//Setters
	void ChangeAge(int pAge);
	void ChangeGender(char pGender);


protected:
	int age;
	char gender;

};

#endif /* ANIMAL_H_ */
