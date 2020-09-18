/*************************************************************************
 * AUTHOR     : Druox 2.0 & BBC
 * LAB #15    : Arrays & Linked Lists of Sheep
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   : 4/13/15
 ************************************************************************/
#ifndef SHEEP_H_
#define SHEEP_H_

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class Sheep
{
public:

	/***************************
	 * CONSTRUCTOR * DESTRUCTOR*
	 ***************************/
	Sheep();
	virtual ~Sheep();

	/************
	 * MUTATORS *
	 ************/
	void SetAge(int newAge);	  //This function will allow the user to set the age of any animal.
	void SetName(string newName); //This function will allow the user to set the name of any animal.

	/*************
	 * ACCESSORS *
	 *************/
	int GetAge()const;    //This function simply allows the code to retrieve the
						  //age of any animal.

	string GetName()const;//This function simply allows the code to retrieve the
						  //name of any animal.

private:
	string name;	//Name of the sheep
	int age;		//Age of the sheep
};

#endif /* SHEEP_H_ */
