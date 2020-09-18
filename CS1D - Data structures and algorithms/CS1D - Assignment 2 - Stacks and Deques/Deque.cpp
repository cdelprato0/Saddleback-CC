/************************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #2:Stacks & Dequeue
 * CLASS	    :CS1D
 * SECTION	    :M/W 3:00 PM
 ************************************************************************************/
#include "Header.h"

//Method uses a doubly linked list that has the capability to go next and previous
// a linked list
void dequeLinkedList(){

	List *head = NULL;  //Keeps tack of the head of the linked list
	List *currentNode;  //Holds the new node that will be added to the linked list
	List *tail = NULL;  //Keeps track of the tail of the linked list
	int currentSize = 0;//Keeps track of the size of the Deque

	cout << "\n\n***********************\n"
			"*        Part G       *\n"
	     << "*  Deque Linked Lists *\n"
		 << "***********************\n\n";

	//PROCESSING - This block will be able to add to either to the tail of the head
	//				of the linked list and will keep track of the doubly linked list
	for(int index = 0; index < 6; index++){

		//Dynamically allocates memory
		currentNode = new List;

		//Sets the next and previous pointers to NULL or nothing
		currentNode->next = NULL;
		currentNode->prev = NULL;

		//Save the data into the Node of the linked list
		currentNode->name = stringArray[index];

		//Outputs that the name is being added to the deque
		cout << "Adding: "<< currentNode->name << " to the Deque!"<< endl;

		//Will detemine where to add the node into the linked list
		if(head == NULL){

			//If the head is equal to nothing then it will add the first node to the
			//list
			head = tail = currentNode;
		}
		else if(head == tail && head != NULL){

			//If there is one node already in the list, this will add the next one to
			//the list
			head = currentNode;
			head->next = tail;
			tail->prev = head;
		}
		else{

			//If there is more than one node in the list, then this will add the next
			//node to the linked list
			tail->next = currentNode;
			tail = currentNode;
			tail->prev = head;
		}

		//Increments the size of the Deque
		currentSize++;
	}

	//Outputs the stack backwards for top to bottom
	cout << "\nThe items on the Deque are: (From front to back)\n";
	for( int index = 0; index < currentSize; index ++ ){

		cout << stringArray[index] << endl;

	}//End FOR LOOP

	cout << endl;

	//*****************
	//*****DOUBLE******
	//*****************
	List *headD = NULL;  //Keeps tack of the head of the linked list
	List *currentDNode;  //Holds the new node that will be added to the linked list
	List *tailD = NULL;  //Keeps track of the tail of the linked list
	int currentDSize = 0;//Keeps track of the size of the Deque


	//PROCESSING - This block will be able to add to either to the tail of the head
	//				of the linked list and will keep track of the doubly linked list
	for(int index = 0; index < 8; index++){

		//Dynamically allocates memory
		currentDNode = new List;

		//Sets the next and previous pointers to NULL or nothing
		currentDNode->next = NULL;
		currentDNode->prev = NULL;

		//Save the data into the Node of the linked list
		currentDNode->number = doubleArray[index];

		//Outputs that the number that is being added to the deque
		cout << "Adding: "<< currentDNode->number << " to the Deque!"<< endl;

		//Will determine where to add the node into the linked list
		if(headD == NULL){

			//If the head is equal to nothing then it will add the first node to the
			//list
			headD = tailD = currentDNode;
		}
		else if(headD == tailD && headD != NULL){

			//If there is one node already in the list, this will add the next one to
			//the list
			headD = currentDNode;
			headD->next = tailD;
			tailD->prev = headD;
		}
		else{

			//If there is more than one node in the list, then this will add the next
			//node to the linked list
			tailD->next = currentDNode;
			tailD = currentDNode;
			tailD->prev = headD;
		}

		//Increments the size of the Deque
		currentDSize++;
	}

	//Outputs the stack backwards for top to bottom
	cout << "\nThe items on the Deque are: (From front to back)\n";
	for( int index = 0; index < currentDSize; index ++ ){

		cout << doubleArray[index] << endl;

	}//End FOR LOOP

	cout << "\n\n******************************\n"
			"*           Part H            *\n"
	     << "* Removing Deque Linked Lists *\n"
		 << "*******************************\n\n";

	cout << "Removing from the STRING Deque: \n"
			"----------------------------------\n";

	List* remove = NULL;  //Creates a remove Node

	//PROCESSING - Removes the head of the list
	cout << "\nRemoving: \n";
	for( int index = 0; index < 5; index++){

		//Saves the head to the remove node
		remove = head;

		//Outputs the name that is getting removed
		cout << head->name << endl;

		//Sets the new head and deletes the old one
		head = head->next;
		delete remove;

		//Decrements the size of the Deque
		currentSize--;
	}

	//Outputs the rest of the linked list to the console
	cout << "\nThe rest of the Deque is: \n";
	for( int index = 0; index < currentSize; index++){

		//Outputs the names of the objects that are left on the Deque
		cout << head->name << endl;
		head = head->next;
	}

	cout << "\nRemoving from the DOUBLE Deque: \n"
			"----------------------------------\n";

	//*****************
	//*****DOUBLE******
	//*****************
	List* removeD = NULL;  //Creates a remove Node

	//PROCESSING - Removes the head of the list
	cout << "\nRemoving: \n";
	for( int index = 0; index < 7; index++){

		//Saves the head to the remove node
		removeD = headD;

		//Outputs the name that is getting removed
		cout << headD->number << endl;

		//Sets the new head and deletes the old one
		headD = headD->next;
		delete removeD;

		//Decrements the size of the Deque
		currentDSize--;
	}

	//Outputs the rest of the linked list to the console
	cout << "\nThe rest of the Deque is: \n";
	for( int index = 0; index < currentDSize; index++){

		//Outputs the names of the objects that are left on the Deque
		cout << headD->number << endl;
		headD = headD->next;
	}
}
