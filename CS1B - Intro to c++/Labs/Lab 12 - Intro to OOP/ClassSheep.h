/*************************************************************************
 * AUTHOR     : Rhader & BBC
 * LAB #12    : Intro to OOP
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   : 4/8/2015
 ************************************************************************/
#ifndef CLASSSHEEP_H_
#define CLASSSHEEP_H_

#include <string>
#include "Header.h"
using namespace std;

/*************************************************************************
* Sheep:
* 	This class makes a name, age & value private. This allows the code to
* 	perform functions which relate to changing an animals age & value, to
* 	set an original age, name, & value of the animals, & to retrieve any
* 	of the information of the animals.
*
* RETURNS: a class of the animals
**************************************************************************/
class Sheep
{
public:
	Sheep();
	~Sheep();

	void SetAge(int age);
	void SetName(string name);
	void SetValue(float value);
	int    GetAge();
	string GetName();
	float  GetValue();

	int ChangeAge(int newAge);
	float ChangeValue(float value);


private:
	string name;
	int age;
	float value;

};




#endif /* CLASSSHEEP_H_ */
