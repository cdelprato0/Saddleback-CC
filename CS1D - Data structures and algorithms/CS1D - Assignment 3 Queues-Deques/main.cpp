/************************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #3:Queues - Deques
 * CLASS	    :CS1D
 * SECTION	    :M/W 3:00 PM
 ************************************************************************************/
#include "Deque.h"
#include "Queue.h"
#include "ArrayVector.h"
#include <iostream>
#include <string.h>
using namespace std;

/************************************************************************************
 * Assignment #3 - Queues & Deques
 * ----------------------------------------------------------------------------------
 * Part One - This part of the program will be able to create a Queue with a Deque.
 *  In the program, Queue is a wrapper class of Deque. Queue will call functions of
 *  the deque class and will perform the operations of a Queue. The program will test
 *  the IsEmpty(), Front() or Peek(), Enqueue(), Dequeue(), Size() and a Display()
 *  methods. For the Peek method it will call Deque PeekHead method. For Enqueue, it
 *  will call the InsertTail()method of the Deque. For Dequeue, it will call the
 *  RemoveHead() method of the Deque class. The input will be read in from a string
 *  array and outputed to the console.
 * ----------------------------------------------------------------------------------
 * Part Two - This part of the program will be able to show the use of an extendable
 *  array and how it can be used in a circular fashion. This part will be able to
 *  add, delete and display the contents of the array. When the items are added to
 *  the array it will add to the back of the array. The add function has the
 *  capability to increase the capacity of the array incase the user wants to add
 *  more elements. The delete function will delete from the front of the array
 *  (at index 0) and will output if the array is empty. The user can check to see the
 *  size and capacity of the array at any time during the program. The program
 *  provied a display function that will output all the elements in the array.
 * ----------------------------------------------------------------------------------
 ************************************************************************************/
int main(){

	//The string array that holds the strings that are going to be run through the
	//queue
	string stringArray[] = {"A man, a plan, a canal, Panama",
							"Was it a car or a cat I saw?" ,
						    "Sit on a potato pan, Otis" ,
							"No lemon, no melon"};
	Queue queue;	//Creates a variable of class queue to run operations

//OUTPUT - Will output the header and a description of the output
cout << "**************************************************************************\n"
		"* PROGRAMMED BY : Chaz Del Prato                                         *\n"
		"* ASSIGNMENT #3 : Queues & Deques                                        *\n"
		"* CLASS         : CS1D                                                   *\n"
		"* SECTION       : MW 3:00p                                               *\n"
		"--------------------------------------------------------------------------\n"
		"* Description   :                                                        *\n"
		"*  PART ONE -                                                            *\n"
		"*  The Output of this program will display the testing of using a wrapper*\n"
		"*  class. The Queue class is the wrapper for the Deque class. The first  *\n"
		"*  part of the output will check to see if the Queue is empty or not.    *\n"
		"*  After that then it will add the first two elements to the queue and   *\n"
		"*  will output to the console the contents of the elements. Then it will *\n"
		"*  return the size of the Queue. It will show the head of the queue by   *\n"
		"*  the Peek method. The program will dequeue one element off the queue   *\n"
		"*  and will output what is getting removed. It will test the isEmpty     *\n"
		"*  method again and output so. After that it will add the last two       *\n"
		"*  elements to the queue. Finally it will display all of the elements of *\n"
		"*  the linked list.                                                      *\n"
		"*  PART TWO -                                                            *\n"
		"*  The output of the second part of the assignment will be displaying how*\n"
		"*  an extendable array is used in a circular fashion. The user will be   *\n"
		"*  prompt with how big of a capacity the user wants to make the array.   *\n"
		"*  Then the program will provide a menu with options to add, delete, and *\n"
		"*  display the size and capacity and also the contents inside the array. *\n"
		"*  The output will read in the first string and then will display. After *\n"
		"*  it will add another string and show that the capacity has been filled *\n"
		"*  and will output so. Then it will add a couple of more string and then *\n"
		"*  it will perform a delete from the front and output. After deleting    *\n"
		"*  the program will add another string to the array and output.          *\n"
		"**************************************************************************\n\n";

	cout << "**********\n"
			"*PART ONE*\n"
			"**********\n";

	cout << "\n<<<<isEMPTY TEST>>>>\n";
	//PROCESSING - Checks to see if the Queue is empty
	if(queue.IsEmpty())
	{
		//Outputs if the Queue is empty
		cout << "Yes! The Queue is empty!\n\n";
	}
	else
	{
		//Outputs if the queue is not empty
		cout << "The Queue is not empty!\n\n";
	}

	cout << "\n<<<<ENQUEUE TEST>>>>\n";
	//PROCESSING - The program will add the two first elements of the array to a queue
	//				and will output to the console what string is being added.
	queue.Enqueue(stringArray[0]);
	queue.Enqueue(stringArray[1]);

	cout << "\n<<<<SIZE TEST>>>>\n";
	//PROCESSING - The program will check the size of the Queue and output how many
	//				elements there are in the Queue
	queue.Size();

	cout << "\n<<<<FRONT(PEEK) TEST>>>>\n";
	//PROCESSING - The program will output the element that is at the head of the
	//				queue (The one that is in the front of the Queue)
	queue.Peek();

	cout << "\n<<<<DEQUEUE TEST>>>>\n";
	//PROCESSING - The program will remove the head of the queue and output what
	//				string is getting removed off the queue
	queue.Dequeue();

	cout << "\n<<<<isEMPTY TEST>>>>\n";
	//PROCESSING - Checks to see if the Queue is empty
	if(queue.IsEmpty())
	{
		//Outputs if the Queue is empty
		cout << "Yes! The Queue is empty!\n\n";
	}
	else
	{
		//Outputs if the queue is not empty
		cout << "The Queue is not empty!\n\n";
	}

	cout << "\n<<<<ENQUEUE TEST>>>>\n";
	//PROCESSING - The program will add the two last elements of the array to a queue
	//				and will output to the console what string is being added.
	queue.Enqueue(stringArray[2]);
	queue.Enqueue(stringArray[3]);

	//This method will display all the elements of the of the Queue
	queue.Display();


	//----------
	//-PART TWO-
	//----------
	cout << "\n**********\n"
			"*PART TWO*\n"
			"**********\n\n";

	ArrayVector extendArray; //Object for the extendable array
	int size = 0;			//keeps the capacity of the array
	string newString;	//used for user input of string
	int command = 0;	//holds the command the user enters
	int index = 0;		//keeps track of the index of the array

	//Asked the user to enter the beginning capacity of the array
	cout << "Please enter the beginning Capacity of the Extendable Array: \n";
	cin >> size;
	cin.ignore(1000, '\n');

	//Calls the reserve function to create the capacity of the array
	extendArray.reserve(size);

	//Prompted menu with reading in the users command
	cout << "\nPlease select from the following options: \n"
			"----------------------------------------- \n"
			"1 - Insert into the Back of the Extendable Array. \n"
			"2 - Delete from the Front of the Extendable Array. \n"
			"3 - Get the Size and Capacity of the Extendable Array. \n"
			"4 - Display the Extendable Array. \n"
			"-1 - To EXIT the program. \n\n";
	cin >> command;
	cin.ignore(1000, '\n');

	//While the user does not enter -1
	while(command != -1){
		switch(command){
			//Adding an element to the extenable array
			case 1:
				cout << "What string would you like to add? ";
				getline(cin, newString);
				extendArray.insert(index, newString);

				index++;
				break;
			//Deleting an element from the extendable array
			case 2:
				if(extendArray.isEmpty()){
					cout << "The Extendable Array is EMPTY!";
					break;
				}else{
					cout << "REMOVING an element from the Extendable Array...\n";
					extendArray.erase(0);
					index--;
				}
				break;
			//Outputs the size and capacity of the extendable array
			case 3:
				if(extendArray.isEmpty()){
					cout << "The Extendable Array is EMPTY!";
					break;
				}else{
					cout << "The size of the Extendable Array is: "
						 << extendArray.GetSize()
						 <<	"\nThe capacity of the Extendable Array is: "
						 << extendArray.getCapacity();
					break;
				}
			//Displays the contents of the extendable array
			case 4:
				extendArray.Display();
				break;
			default:
				break;

		}//End SWITCH
		//Prompted menu with reading in the users command
		cout << "\n\nPlease select from the following options: \n"
				"----------------------------------------- \n"
				"1 - Insert into the Back of the Extendable Array. \n"
				"2 - Delete from the Front of the Extendable Array. \n"
				"3 - Get the Size and Capacity of the Extendable Array. \n"
				"4 - Display the Extendable Array. \n"
				"-1 - To EXIT the program. \n\n";
		cin >> command;
		cin.ignore(1000, '\n');
	}//End WHILE
	return 0;
}//End MAIN
