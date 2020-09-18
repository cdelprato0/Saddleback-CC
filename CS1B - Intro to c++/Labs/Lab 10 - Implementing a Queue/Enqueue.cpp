/*************************************************************************
 * AUTHOR     : Myrmidon & BBC
 * LAB #10    : Implementing a Queue
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   : 3/18/15
 ************************************************************************/
#include "Header.h"

PersonNode* Enqueue(PersonNode *head)
{
	PersonNode person;	   // IN   - the person and their info
	PersonNode *newPerPtr; // PROC - the pointer that indexes the nodes
	PersonNode tempPtr;
	bool 	   invalid;	   // PROC - the invalid condition for error
						   //		 checking user input

	 cout << left;
	 cout << "Who would you like to add?\n";

	 // INPUT - name to be entered to stack from PersonNode struct
	 cout << setw(14) << "Enter name: ";
	 getline(cin, person.name);

	 // INPUT - gender to be entered and error check to queue
	 //         from PersonNode struct
	 do
	 {
	     cout << setw(14) << "Enter gender: ";
	     cin.get(person.gender);
	     cin.ignore(1000, '\n');

	     person.gender = toupper(person.gender);

	     invalid = person.gender != 'M'
	   			  && person.gender != 'F';

	   	 if(invalid)
	   	 {
	   		 cout << "\n**** Invalid entry - "
	   				 "please enter only M or F ****\n\n";
	   	 }
	  }while(invalid);

	  // INPUT - age to be entered and error check to queue
	  //         from PersonNode struct
	  do
	  {
		  invalid = false;

		  cout << setw(14) << "Enter Age: ";

		  if(!(cin >> person.age))
		  {
			  cout << "\n**** Please input an age ****\n\n";
			  cin.clear();
			  cin.ignore(numeric_limits<streamsize>::max(), '\n');

			  invalid = true;
		  }
		  if(!invalid)
		  {
			  cin.ignore(100,'\n');
		  }

	   }while(invalid);

	   cout << right;


	   // allocates memory for a new node on the queue
	   newPerPtr = new PersonNode;

	   // INITIALIZE - the name, gender, and age into one node from the struct
	   if(newPerPtr != NULL)
	    {
			 newPerPtr->name   = person.name;
			 newPerPtr->gender = person.gender;
			 newPerPtr->age    = person.age;


		    // PROC - links the node to the list
			newPerPtr->next   = head;
			head              = newPerPtr;
	    }

	return newPerPtr;
}
