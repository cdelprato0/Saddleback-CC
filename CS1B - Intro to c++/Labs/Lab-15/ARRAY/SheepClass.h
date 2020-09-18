/*************************************************************************
 * AUTHOR     : Druox 2.0 & BBC
 * LAB #15    : Arrays & Linked Lists of Sheep
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   : 4/13/15
 ************************************************************************/
#ifndef SHEEPCLASS_H_
#define SHEEPCLASS_H_

#include "Header.h"
#include "Sheep.h"
const int AR_SIZE = 5;

class SheepClass {
public:

	/***************************
	 * CONSTRUCTOR * DESTRUCTOR*
	 ***************************/
	SheepClass();
	virtual ~SheepClass();

	/************
	 * MUTATORS *
	 ************/
	void AddSheep(Sheep newSheep);	//This function is designed to add an instance of a
									//sheep into an array.

	void ClearList();				//This function will clear all the values
									//that have been stored in the current array

	/*************
	 * ACCESSORS *
	 *************/
	Sheep OutputFirst()const;		//This function returns the values that are
									//stored in the first index of the array

	void FindSheepName(string sheepName) const; //This function will be able to
												//search an array for one instance
												//of a sheeps name

	void OutputList()const;			//This function outputs to the console a table that
									//has the name and ages of all the sheep

	int ListSize()const;			//This function returns the number of sheep in the array.

private:

	Sheep sheepArray[AR_SIZE];
	int sheepCount;
};

#endif /* SHEEPCLASS_H_ */
