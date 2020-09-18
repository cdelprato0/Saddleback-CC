/*************************************************************************
 * AUTHOR     : Zeta & BBC
 * LAB #11    : Creating an Ordered List
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   : 4/1/15
 ************************************************************************/
#include "Header.h"

/**************************************************************************
 * RemovingNode Function
 * ________________________________________________________________________
 * This function will remove a node from the linked list. It will first
 * check to see if the list is empty and if so, will output so. If not,
 * then it will prompt the user and ask what person name they would like to
 * remove and it will check to see if that name is in the linked list. If
 * it is not in the linked list it will output so. If it is found in the
 * list it will remove the node from the list and will connect the list
 * back together minus the node that was asked to be removed.
 * ________________________________________________________________________
 * PRECONDITIONS
 *   head : the head of the list must be previously defined
 *   tail : the tail of the list must be previously defined
 * POSTCONDITIONS
 *   head : the head of the list could be changed
 *   tail : the tail of the list could be changed
 *************************************************************************/
void RemovingNode(PersonNode *&head, //PROC - Head points to the top of list
									 //Pass by reference IN & OUT of function
		          PersonNode *&tail) //PROC - Tail points to the bottom of list
									 //Pass by reference IN & OUT of function
{
	PersonNode *currentNode; //PROC - the pointer for head
	PersonNode *searchPtr;	 //PROC - the search pointer
	PersonNode *tempPtr;	 //PROC - the temp pointer
	string removeName;		 //IN   - The name that wants to be removed
	bool found;				 //PROC - will determine if found or not found

	//Initializes a pointer equal to head and found equal to false
	currentNode = head;
	found = false;

	//PROC&OUT - Checks to see if the list is empty and will output so
	if(head == NULL)
	{
		cout << "Can\'t remove from an empty list!\n\n";
	}//END - IF

	//PROCCESING - if not empty the program will prompt for the name to be removed
	else
	{
		//INPUT - Prompts the user to enter the name to be removed
		cout << "Who would you like to remove? ";
		getline(cin, removeName);

		//OUPUT - outputs the name that is being searched
		cout << "\nSearching for " << removeName << "...\n";

		//PROCCESING - Searches the list to see if the name is in the list
		while(!found && currentNode != NULL)
		{
			//If the name is found , found will equal true
			if(currentNode-> name == removeName)
			{
				found = true;
			}//END - IF

			//If not found then it will move onto the next node
			else
			{
				currentNode = currentNode-> next;
			}//END - ELSE

		}//END - WHILE - LOOP

		//PROCCESING - If the name is found in the linked list it will go
		//			   into the process of removing it
		if(found)
		{
			//OUPUT - outputs the name that is being removed
			cout << "Removing " << removeName << "!\n\n";

			//PROCCESING - Checks to see if the node is head that is needed
			//				to be removed
			if(currentNode == head)
			{
				//Assigns the head to the next node and deletes the original
				//head
				head = currentNode-> next;
				delete currentNode;

				//Set back to null for safety
				currentNode = NULL;
			}//END - IF

			//PROCCESING - Checks to see if there is only one node in the
			//				list left to be removed
			else if(head-> next == NULL)
			{
				//Assigns head and tail to NULL and deletes tail
				head = NULL;
				delete tail;
				tail = NULL;
			}//END - ELSE - IF

			//PROCCESING - Checks to see if the node is located in the
			//				middle and will go into the process of removing it
			else if(head-> next ->next != NULL)
			{
				//Assigns the search pointer to head and found to false
				searchPtr = head;
				found = false;

				//PROCCESING - Searches for the next nodes name in the list
				//				and sets the pointer before the node that
				//				is being deleted
				while(searchPtr-> next != NULL && !found)
				{
					//PROCCESING - Searches for the next nodes name
					if(searchPtr-> next->name == removeName)
					{
						found = true;

						//Assigns the temp pointer to the node that is going
						//to be deleted and the search node is assigned to
						//the node after the node that was deleted.
						tempPtr = searchPtr-> next;
						searchPtr-> next = tempPtr-> next;
						delete tempPtr;
					}//END - IF

					//PROCCESING - If not found then will move onto next node
					else
					{
						searchPtr =searchPtr-> next;
					}//END - ELSE

				}//END - WHILE - LOOP

				//Safety assigning the pointers to NULL
				searchPtr = NULL;
				tempPtr = NULL;
			}//END - ELSE - IF

			//PROCESSING - if the node that is going to be removed is the tail
			else
			{
				//Assinging the tail to head
				tail = head;

				//PROCESSING - Will make sure that the tail is deleted and
				//				that the tail is not lost in the process
				while(tail-> next-> next != NULL)
				{
					tail = tail-> next;
				}//END - WHILE - LOOP

				//Deletes the tail and assigns the new tail
				delete tail-> next;
				tail-> next = NULL;
			}//END - ELSE

		}//END - IF

		//PROCESSING - Outputs that the name was not found in the linked list
		else
		{
			//OUTPUT - Outputs the name that is not in the list
			cout << "I\'m sorry, \"" << removeName << "\" was NOT found!\n\n";
		}//END - ELSE

	}//END - ELSE
}
