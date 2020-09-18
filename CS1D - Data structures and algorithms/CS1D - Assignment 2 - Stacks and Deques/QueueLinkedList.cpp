/************************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #2:Stacks & Dequeue
 * CLASS	    :CS1D
 * SECTION	    :M/W 3:00 PM
 ************************************************************************************/
#include "Header.h"

//Method uses a linked list to create a queue of strings (FIFO)
void queueLinkedList()
{
	List *head = NULL;  //Keeps tack of the head of the linked list
	List *newNode;      //Holds the new node that will be added to the linked list
	List *tail = NULL;  //Keeps track of the tail of the linked list
	int currentSize = 0;//Keeps track of the size of the Queue

	cout << "\n\n**********************\n"
			"*        Part E      *\n"
	     << "*  Queue Linked List *\n"
		 << "**********************\n\n";

	//PROCESSING - This will add the next element to the end of the queue and will
	//				output so
	for( int index = 0; index < 6; index ++){

		//Dynamically allocates memory
		newNode = new List;

		//Outputs to the console that the string is getting added to the list
		cout << "Adding: " << stringArray[index] << " to the Queue\n";

		//Saves the name to the member in the node of the linked list
		newNode->name = stringArray[index];

		//If the tail is equal to nothing then it will add it to the tail
		if(tail == NULL){
			head = tail = newNode;

		}//End IF
		else{
			//If the tail is not equal to nothing then it will add the next node to
			//the tail of the linked list
			tail->next = newNode;
			tail = newNode;
		}//End ELSE

		//Increments the size of the queue
		currentSize++;

	}//END FOR LOOP

	//Outputs the stack backwards for top to bottom
	cout << "\nThe items on the Queue are: (From front to back)\n";
	for( int index = 0; index < currentSize; index ++){

		cout << stringArray[index] << endl;

	}//End FOR LOOP

	cout << endl;

	//*****************
	//*****DOUBLE******
	//*****************
	List *headD = NULL;  //Keeps tack of the head of the linked list
	List *newDNode;      //Holds the new node that will be added to the linked list
	List *doubleTail = NULL;  //Keeps track of the tail of the linked list
	int doubleSize = 0;//Keeps track of the size of the Queue

	//PROCESSING - This will add the next element to the end of the queue and will
	//				output so
	for( int index = 0; index < 8; index ++){

		//Dynamically allocates memory
		newDNode = new List;

		//Outputs to the console that the number that is getting added to the list
		cout << "Adding: " << doubleArray[index] << " to the Queue\n";

		//Saves the number to the member in the node of the linked list
		newDNode->number = doubleArray[index];

		//If the tail is equal to nothing then it will add it to the tail
		if(doubleTail == NULL){
			headD = doubleTail = newDNode;

		}//End IF
		else{
			//If the tail is not equal to nothing then it will add the next node to
			//the tail of the linked list
			doubleTail->next = newDNode;
			doubleTail = newDNode;
		}//End ELSE

		//Increments the size of the queue
		doubleSize++;

	}//END FOR LOOP

	//Outputs the stack backwards for top to bottom
	cout << "\nThe items on the Queue are: (From front to back)\n";
	for( int index = 0; index < doubleSize; index ++){

		cout << doubleArray[index] << endl;

	}//End FOR LOOP

	cout << "\n\n*******************************\n"
			"*            Part F           *\n"
	     << "*  Removing Queue Linked List *\n"
		 << "*******************************\n\n";

	cout << "Removing from the STRING Queue: \n"
			"----------------------------------\n";
	//PROCESSING - Removes the head of the queue and outputs so
	List* removeNode = NULL;
	cout << "\nRemoving: \n";
	for( int index = 0; index < 5; index++){

		//Outputs the name that is getting removed
		cout << head->name << endl;

		//Sets the next node to the next object in the linked list
		removeNode = head;
		head = head->next;
		delete removeNode;

		//Decrements the size of the queue
		currentSize--;

	}//End FOR LOOP

	//PROCESSING - Outputs the rest of the Queue
	cout << "\nThe rest of the Queue is: \n";
	for( int index = 0; index < currentSize; index++){

		//Outputs the name of the rest of the queue and sets the head to the next
		cout << head->name << endl;
		head = head->next;
	}//End FOR LOOP

	//*****************
	//*****DOUBLE******
	//*****************
	cout << "\nRemoving from the DOUBLE Queue: \n"
			"----------------------------------\n";

	//PROCESSING - Removes the head of the queue and outputs so
	cout << "\nRemoving: \n";
	for( int index = 0; index < 7; index++){

		//Outputs the number that is getting removed
		cout << headD->number << endl;

		//Sets the next node to the next object in the linked list
		headD = headD->next;

		//Decrements the size of the queue
		doubleSize--;

	}//End FOR LOOP

	//PROCESSING - Outputs the rest of the Queue
	cout << "\nThe rest of the Queue is: \n";
	for( int index = 0; index < doubleSize; index++){

		//Outputs the numbers of the rest of the queue and sets the head to the next
		cout << headD->number << endl;
		headD = headD->next;
	}//End FOR LOOP
}//End METHOD
