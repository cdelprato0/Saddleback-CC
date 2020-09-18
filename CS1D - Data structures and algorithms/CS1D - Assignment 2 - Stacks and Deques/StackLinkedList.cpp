/************************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #2:Stacks & Dequeue
 * CLASS	    :CS1D
 * SECTION	    :M/W 3:00 PM
 ************************************************************************************/
#include "Header.h"

//Method uses a singly linked list to incorporate a stack of strings (LIFO)
void singlyLinkedList()
{
	List *head;          //Keeps track of the head of the linked list
	List *newNode;       //Used to create a new Node of the linked list
	int currentSize = 0; //Used to keep count of how many objects in the stack

	cout << "\n\n*****************************\n"
			"*           Part C          *\n"
	     << "*  Singly Linked List Stack *\n"
		 << "*****************************\n\n";
	//PROCESSING - This block is the Push function of a singly linked list Stack, it
	//				will add the new element to the stack and output so
	for( int index = 0; index < 6; index ++){

		//Dynamically allocates memory for the new node
		newNode = new List;

		//Outputs to the console that the name is getting added to the stack
		cout << "Adding: " << stringArray[index] << " to the stack\n";

		//Adds the name in the string array to the node in the linked list
		newNode->name = stringArray[index];

		//Adds the new node to the head of the linked list
		newNode->next = head;
		head = newNode;

		//Increments the size of the stack
		currentSize++;

	}//End FOR LOOP

	//Outputs the stack backwards for top to bottom
	cout << "\nThe items on the stack are: (From top to bottom)\n";
	for( int index = currentSize -1; index >= 0; index --){

		cout << stringArray[index] << endl;

	}//End FOR LOOP

	cout << endl;

	//*****************
	//*****DOUBLE******
	//*****************
	List *newHead;             //Keeps track of the head of the linked list
	List *newDoubleNode;       //Used to create a new Node of the linked list
	int doubleSize = 0;       //Used to keep count of how many objects in the stack

	//PROCESSING - This block is the Push function of a singly linked list Stack, it
	//				will add the new element to the stack and output so
	for( int index = 0; index < 8; index ++){

		//Dynamically allocates memory for the new node
		newDoubleNode = new List;

		//Outputs to the console that the number is getting added to the stack
		cout << "Adding: " << doubleArray[index] << " to the stack\n";

		//Adds the number in the double array to the node in the linked list
		newDoubleNode->number = doubleArray[index];

		//Adds the new node to the head of the linked list
		newDoubleNode->next = newHead;
		newHead = newDoubleNode;

		//increments the size of the stack
		doubleSize++;
	}//End FOR LOOP

	//Outputs the stack backwards for top to bottom
	cout << "\nThe items on the stack are: (From top to bottom)\n";
	for( int index = doubleSize -1; index >= 0; index --){

		cout << doubleArray[index] << endl;

	}//End FOR LOOP

	cout << "\n\n*************************************\n"
			"*             Part D                *\n"
	     << "* Removing Singly Linked List Stack *\n"
		 << "*************************************\n\n";

	List* removeNode; //Creates a remove node to be removed from the list

	cout << "Removing from the STRING Stack: \n"
			"----------------------------------\n";

	//PROCESSING - This block will use the pop function of a stack to remove the head
	//				of the stack and will output so
	cout << "\nRemoving: \n";
	for( int index = 0; index < 2; index++ ){

		//Dynamically allocates memory
		removeNode = new List;

		//Assigns the head of the stack to the remove node
		removeNode = head;

		//Outputs the name of the head of the stack that is going to get removed
		cout << head->name << endl;

		//Assigns the head to the next variable in the stack and then deletes the
		//remove Node
		head = removeNode->next;
		delete removeNode;

		//Decrements the size of the stack
		currentSize--;
	}//End FOR LOOP

	//PROCESSING - Prints out the rest of the stack
	cout << "\nThe rest of the stack is: \n";
	for( int index = 0; index < currentSize; index++){

		//outputs the name of the head and cycles through the stack
		cout << head->name << endl;
		head = head->next;

	}//End FOR LOOP

	//*****************
	//*****DOUBLE******
	//*****************
	cout << "\nRemoving from the DOUBLE Stack: \n"
			"----------------------------------\n";

	List* removeDoubleNode;  //Creates a remove node to be removed from the list

	//PROCESSING - This block will use the pop function of a stack to remove the head
	//				of the stack and will output so
	cout << "\nRemoving: \n";
	for( int index = 0; index < 2; index++ ){

		//Dynamically allocates memory
		removeDoubleNode = new List;

		//Assigns the head of the stack to the remove node
		removeDoubleNode = newHead;

		//Outputs the number of the head of the stack that is going to get removed
		cout << newHead->number << endl;

		//Assigns the head to the next variable in the stack and then deletes the
		//remove Node
		newHead = removeDoubleNode->next;
		delete removeDoubleNode;

		//Decrements the size of the stack
		doubleSize--;
	}//End FOR LOOP

	//PROCESSING - Prints out the rest of the stack
	cout << "\nThe rest of the stack is: \n";
	for( int index = 0; index < doubleSize; index++){

		//outputs the numbers of the rest of the linked list and sets the next one to
		//be displayed
		cout << newHead->number << endl;
		newHead = newHead->next;
	}//End FOR LOOP
}
