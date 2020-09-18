/*************************************************************************
 * AUTHOR     : Druox 2.0 & BBC
 * LAB #15    : Arrays & Linked Lists of Sheep
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   : 4/13/15
 ************************************************************************/
#ifndef SHEEPLINKEDLIST_H_
#define SHEEPLINKEDLIST_H_

#include "Header.h"
#include "Sheep.h"

class SheepLinkedList
{
public:
	SheepLinkedList();
	virtual ~SheepLinkedList();

	/************
	 * MUTATORS *
	 ************/
	void AddSheep(Sheep);	//This function is designed to add an instance of a
							//sheep into a linked list.

	void ClearList();		//This function will clear all the values
							//that have been stored in the current linked list

	/*************
	 * ACCESSORS *
	 *************/
	Sheep OutputFirst()const;	//This function returns the values that are
								//stored at the head of the linked list

	void FindSheepName(string)const; //This function will be able to
									 //search a linked list for one instance
									 //of a sheep's name

	void OutputList()const;		//This function outputs to the console a table that
								//has the name and ages of all the sheep

	int ListSize()const;		//This function returns the number of sheep in the linked list

private:

	//PROCESSING - Needed for the making of the linked list
	struct SheepNode
	{
		Sheep sheepInfo;	//Holds the name and age of the sheep
		SheepNode *next;	//Used to create and specify nodes
		SheepNode *prev;	//Used to go in both ways using a linked list
	};

	SheepNode *head;		//The head of the linked list
	SheepNode *tail;		//The tail of the linked list
	int sheepCount;			//The counter that keeps track of all the sheep
};

#endif /* SHEEPLINKEDLIST_H_ */
