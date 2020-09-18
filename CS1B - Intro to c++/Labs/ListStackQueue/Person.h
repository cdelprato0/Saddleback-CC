/*
 * Person.h
 *
 *  Created on: Apr 13, 2015
 *      Author: cdelprato0
 */

#ifndef PERSON_H_
#define PERSON_H_

#include "Header.h"

class Person {
public:
	Person();
	virtual ~Person();

	//GETTERS
	string GetName()const;
	int GetAge()const;
	void Display()const;


	//SETTERS
	void SetAge(int);
	void SetName(string);


private:
	string name;
	int age;
};

#endif /* PERSON_H_ */
