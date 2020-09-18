/*************************************************************************
 * AUTHOR     : Zeta & BBC
 * LAB #11    : Creating an Ordered List
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   : 4/1/15
 ************************************************************************/
#include "Header.h"

/**************************************************************************
 * CreateList Function
 * ________________________________________________________________________
 * This function will read in from an input file and will create a linked
 * list that contains the name, gender, and age of the people. As the list
 * is being created it will output top the console the names that are being
 * added to the linked list. Also the list is being created in alphabetical
 * order staring with their last names at 'A' and ending with 'Z'.
 * ________________________________________________________________________
 * PRECONDITIONS
 *   head : the head of the list must be previously defined
 *   tail : the tail of the list must be previously defined
 * POSTCONDITIONS
 *   head : the head of the list will be created and the list will form
 *   tail : the tail of the list will be created
 *************************************************************************/
void CreateList(PersonNode *&head, //PROC - Head points to the top of list
								   //Pass by reference IN & OUT of function
		        PersonNode *&tail) //PROC - tail points to the bottom of list
								   //Pass by reference IN & OUT of function
{
	ifstream inFile;		//PROC - file that will be inputed from
	PersonNode *perPtr;		//PROC - the pointer for head
	PersonNode *searchPtr;	//PROC - the pointer to help with inserting
	bool found;				//PROC - will determine if found or not found

	//Initializing the pointer to NULL before the list is created
	perPtr = NULL;
	searchPtr = NULL;

	//Allocates memory for a new node in the linked list - Initialize
	perPtr = new PersonNode;

	//Opens the input file
	inFile.open("inFile.txt");

	//PROCESSING - Taking in from the input file the persons' name, age,
	//				and gender. As the list is being created it will put
	//				them in alphabetical order and will display in the
	//				console the names that have been added. - Check
	while(inFile && perPtr != NULL)
	{
		//INPUT - Persons name
		getline(inFile, perPtr-> name);

		//INPUT - Persons gender
		inFile.get(perPtr-> gender);

		//INPUT - Persons age
		inFile >> perPtr-> age;
		inFile.ignore(1000, '\n');

		//OUTPUT - will output the names that are being added
		cout << "Adding : " << perPtr->name << endl;

		//PROCCESING - Inserting into an empty list and assigning head and tail
		if(head == NULL)
		{
			//Assigning head and tail to the first node
			head = perPtr;
			tail = perPtr;
		}//END - IF

		//PROCCESING - Inserting a node before the head of the list
		else if(head->name > perPtr->name)
		{
			//Assigning the new node to head
			perPtr->next = head;
			head = perPtr;
		}//END - IF - ELSE

		//PROCCESING - Inserting a node after the tail of the list
		else if(tail->name < perPtr->name)
		{
			//Assigning the new node to the tail
			tail->next = perPtr;
			tail = perPtr;
			tail->next = NULL;

		}//END - IF - ELSE

		else
		{
			//Assigning the temp pointer to head and found equal to false
			searchPtr = head;
			found = false;

			//PROCCESING - Inserting a node in the middle of the list
			while(!found && searchPtr->next != NULL)
			{
				//Checks to see if the temp pointers next node's name is
				//greater than the current node's name
				if (searchPtr-> next-> name > perPtr-> name)
				{
					found = true;

					//Inserts the node into the middle of nodes
					perPtr-> next = searchPtr-> next;
					searchPtr->next = perPtr;
				}//END - IF

				else
				{
					//If not found then it will move on to the next node
					searchPtr = searchPtr-> next;
				}//END - ELSE

			}//END - WHILE - LOOP

		}//END - ELSE

		//Change - creates new memory for the next node to be created
		perPtr = NULL;
		perPtr = new PersonNode;

		//Ignores the space in the input file
		inFile.ignore(1000, '\n');

	}//END - WHILE - LOOP

	cout << endl;

	//Deletes any extra memory slots that have been created and sets the
	//pointer to NULL
	delete perPtr;
	perPtr = NULL;

	//Closes the input file
	inFile.close();
}
