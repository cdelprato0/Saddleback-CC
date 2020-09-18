/************************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #2:Stacks & Dequeue
 * CLASS	    :CS1D
 * SECTION	    :M/W 3:00 PM
 ************************************************************************************/
#include "Header.h"

/************************************************************************************
 * Assignment #2 - Stacks & Queues & Deques
 * ----------------------------------------------------------------------------------
 * This program will be able to read in information and store the information into
 * a stack, queue, and deque. The program will also be able to check to see if the
 * brackets surrounding an expression, have an opening bracket and a closing bracket
 * and will output true or false. For adding item to the stack, queue, and deque,
 * there are already arrays that are saved as global variables and in each function,
 * it will call and use those variables to occupy the lists. First function uses
 * the Standard Template Library to create a stack. The next function is a singly
 * linked list that loads the items into a stack. The next functions are the Queue
 * It will read in items using a singly linked list and will insert at the tail of
 * the list instead of the head. The Last function for the lists is a Deque, which
 * uses a double linked list to save its variables. The final function of the program
 * will be able to take in users input of an expression and determine if the brackets
 * that surround the expression is mathematically correct.
 * ----------------------------------------------------------------------------------
 ************************************************************************************/
int main()
{
	//OUTPUT - Will output the header and a description of the output
cout << "**************************************************************************\n"
		"* PROGRAMMED BY : Chaz Del Prato                                         *\n"
		"* ASSIGNMENT #2 : Stacks & Queues & Deques                               *\n"
		"* CLASS         : CS1D                                                   *\n"
		"* SECTION       : MW 3:00p                                               *\n"
		"--------------------------------------------------------------------------\n"
		"* Description   :                                                        *\n"
		"*  The Output of this program will start off with the first part of the  *\n"
		"*  assignment requirements. Each of the functions will add all the items *\n"
		"*  string and double items from arrays and will remove all the way up to *\n"
		"*  'Cathy' for the strings, and '1.2' for the doubles. It will provide   *\n"
		"*  the STL stack adding each member of the stack, and then it will remove*\n"
		"*  items off the stack. The next process will use a singly linked list   *\n"
		"*  to add and remove items from the stack. After that, there will be a   *\n"
		"*  Singly linked list that adds and removes from a queue. The last       *\n"
		"*  function for the string and double information, will use a doubly     *\n"
		"*  linked list to add and remove from the Deque. The final operation     *\n"
		"*  of the program will read in users input and determine if an           *\n"
		"*  expression is true or not, regarding the parenthesis around it.       *\n"
		"**************************************************************************\n\n";

	//Calls the method that uses a STL Stack to complete the instructions
	stlStack();

	//Calls the method that uses a stack singly linked list to complete the
	//instructions
	singlyLinkedList();

	//Calls the method that uses a queue singly linked list to complete the
	//instructions
	queueLinkedList();

	//Calls the method that uses a Deque double linked list to complete the
	//instructions
	dequeLinkedList();


	cout << "\n***********************\n"
			"*       Part I        *\n"
		 << "*Parenthesis Algorithm*\n"
		 << "***********************";
	//Calls the Parenthesis Algorithm to determine if the order of brakets and correct
	for( int index = 0; index < 7; index++){

		//Checks to see if the expression is true or false
		if(paraCheck()){
			cout << "True!";

		}//End IF
		else{
			cout << "False!";
		}//End Else
	}//End FORR LOOP

	return 0;
}
