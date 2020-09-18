/*************************************************************************
 * AUTHOR     : Druox 2.0 & BBC
 * LAB #15    : Arrays & Linked Lists of Sheep
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   : 4/13/15
 ************************************************************************/
#include "Header.h"

//Class Constructor
SheepLinkedList::SheepLinkedList()
{
	sheepCount = 0;
	head = NULL;
	tail = NULL;
}


//Class Destructor
SheepLinkedList::~SheepLinkedList()
{

}


/*************************************************************************
 * FUNCTION AddSheep
 * ________________________________________________________________________
 * This function is designed to add an instance of a sheep into a linked list.
 * Loads to the head and tail of the linked list. Using a doubly linked list
 * so that we can keep track of the linked list in both directions
 * ________________________________________________________________________
 * PRECONDITIONS
 *   GetCommand : user selection
 *
 * POSTCONDITIONS
 *   <Nothing>
 ************************************************************************/
void SheepLinkedList::AddSheep(Sheep newSheep)
{
	SheepNode *currentNode; //Temp pointer to be used for adding and searching a linked list

	//Allocates new memory for the new node
	currentNode = new SheepNode;

	//Assigns the sheep name and age into the new node
	currentNode->sheepInfo = newSheep;

	//Assigns the next pointer to NULL
	currentNode->next = NULL;
	currentNode->prev = NULL;

	//PROCESSING - Checks to see if the list is empty or not
	if(head == NULL)
	{
		//Assigns head and tail to the first node in the linked list
		head = currentNode;
		tail = currentNode;

	}//END - IF
	else if(head == tail && head != NULL)
	{
		//PROCESSING  - If there is only one node in the linked list this
		//				will add the next node after the head and will also
		//				keep track of the prev node
		head = currentNode;
		head->next = tail;
		tail->prev = head;
	}
	else
	{

		//PROCESSING - Adds to the tail of the linked list so it can output
		//				the names in order
		tail->next = currentNode;
		tail = currentNode;
		tail->prev = head;

	}//END - ELSE

	//Increments the sheep count
	sheepCount++;

}


/*************************************************************************
 * FUNCTION ClearList
 * ________________________________________________________________________
 * This function will clear all the values that have been stored in the
 * current linked list
 * ________________________________________________________________________
 * PRECONDITIONS
 *   GetCommand : user selection
 *
 * POSTCONDITIONS
 *   <nothing>
 ************************************************************************/
void SheepLinkedList::ClearList()
{
	head = NULL; //Assigning head to NULL so it loses the current list
	tail = NULL; //Assigning tail to NULL so it loses the current list

	//OUTPUT - Outputs to the console when the list is cleared or is the
	//			list was already cleared
	if(sheepCount == 0)
	{
		cout << "The list is empty!\n\n";

	}//END - IF
	else
	{
		cout << "The list has been cleared!\n\n";
		sheepCount = 0;

	}//END - ELSE
}


/*************************************************************************
 * FUNCTION OutputFirst
 * ________________________________________________________________________
 * This function returns the values that are stored at the head of the
 * linked list
 *
 * returns -> head->sheepInfo
 * ________________________________________________________________________
 * PRECONDITIONS
 *   GetCommand : user selection
 *
 * POSTCONDITIONS
 *   returns the head of the linked list
 ************************************************************************/
Sheep SheepLinkedList::OutputFirst()const
{
	return head->sheepInfo;
}


/*************************************************************************
 * FUNCTION FindSheepName
 * ________________________________________________________________________
 * This function will be able to search a linked list for one instance of a
 * sheep's name. It will output whether if it was found or not and if found
 * it will out put a table that has the sheep's name in it
 * ________________________________________________________________________
 * PRECONDITIONS
 *   GetCommand : user selection
 *
 * POSTCONDITIONS
 *   <nothing>
 ************************************************************************/
void SheepLinkedList::FindSheepName(string searchName)const
{
	SheepNode *currentNode; //Temp pointer to be used for adding and searching a linked list
	bool found;				//CALC - Used to determine if something is found or not

	//Initializing found to false and currentNode to the head of the list
	found = false;
	currentNode = head;

	//PROCESSING - If the linked list is empty it will output so
	if(sheepCount == 0)
	{
		cout << "There are no sheep to be found!\n\n";

	}//END - IF

	//PROCESSING - This code will search through a linked list to find one
	//				instance of a certain named sheep. Once it is found it
	//				will output a table with the sheep's name and age.
	else
	{
		while(!found && currentNode != NULL)
		{
			if(searchName == currentNode->sheepInfo.GetName())
			{
				found = true;

				//OUTPUT - outputs to the console when the name is found
				cout << left
					 << setw(16) << "\nNAME" << "AGE" << endl
				  	 << "-------------- ---"        << endl;

				cout << setw(16) << currentNode->sheepInfo.GetName()
					 << currentNode->sheepInfo.GetAge() << endl << endl;

				cout << "Has been found.\n\n";

			}//END - IF


			//PROCESSING - Moves to the next node that is going to be searched
			else
			{
				currentNode = currentNode-> next;

			}//END - ELSE
		}//END - WHILE LOOP
	}//END - ELSE
}


/*************************************************************************
 * FUNCTION OutputList
 * ________________________________________________________________________
 * This function outputs to the console a table that has the name and ages
 * of all the sheep. It will determine if the linked list is empty. It will
 * also display how many sheep are in the linked list
 * ________________________________________________________________________
 * PRECONDITIONS
 *   GetCommand : user selection
 *
 * POSTCONDITIONS
 *   <Nothing>
 ************************************************************************/
void SheepLinkedList::OutputList()const
{
	SheepNode *currentNode; //Temp pointer to be used for adding and searching a linked list

	//Assigns the pointer to head so that the linked list can be displayed
	currentNode = head;

	//PROCESSING - If the linked list is not empty it will output a table to the
	//				console that has the sheep's name and age and will tell
	//				you how many sheep are in the linked list
	if(sheepCount != 0)
	{
		//OUTPTU - Outputs to the console the table with name and ages
		cout << left
			 << setw(15) << "NAME" << "AGE" << endl
			 << "-------------- ---"        << endl;

		//PROCESSING - Runs through the linked list and outputs each name and age
		//				that is in there
		while(currentNode != NULL)
		{
			cout << setw(16) << currentNode->sheepInfo.GetName()
				 << currentNode->sheepInfo.GetAge() << endl;

			currentNode = currentNode->next;

		}//END - WHILE LOOP

		cout << "\nThere are " << sheepCount << " sheep in the list!\n";

	}//END - IF

	//PROCESSING - If the linked list is empty it will output so
	else
	{
		cout << "The list is empty!\n";

	}//END - ELSE

	cout << endl;
}


/*************************************************************************
 * FUNCTION ListSize
 * ________________________________________________________________________
 * This function returns the number of sheep in the linked list
 *
 * returns -> sheepCount
 * ________________________________________________________________________
 * PRECONDITIONS
 *   GetCommand : user selection
 *
 * POSTCONDITIONS
 *   returns the number of sheep
 ************************************************************************/
int SheepLinkedList::ListSize()const
{
	return sheepCount;
}
