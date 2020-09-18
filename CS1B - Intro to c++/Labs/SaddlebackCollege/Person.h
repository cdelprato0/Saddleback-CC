/*
 * Person.h
 *
 *  Created on: Apr 22, 2015
 *      Author: cdelprato0
 */

#ifndef PERSON_H_
#define PERSON_H_

#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Person //BASE CLASS and SUPER CLASS
{
public:

	//OVERLOADING: Same name ,same scope, different parameters signatures
	Person();				   					  //DEFAULT Constructor
	Person(string pName, int pName, char pGender); //NON-DEFAULT Constructor

	virtual ~Person();

	//GETTERS
	string GetName()const;
	int GetAge()const;
	char GetGender()const;


	//SETTERS
	void InitializeMembers(string n, int a, char a);

	//OVERLOADING: Same name ,same scope, different parameters signatures
	void ChangeValue(int pAge);
	void ChangeValue(char pGender);
	void ChangeValue(string pName);

	string Display()const;

private:
	long SSN;

protected:
	string name;
	int age;
	char gender;


};

#endif /* PERSON_H_ */
