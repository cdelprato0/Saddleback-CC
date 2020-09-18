/************************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #3:Queues - Deques
 * CLASS	    :CS1D
 * SECTION	    :M/W 3:00 PM
 ************************************************************************************/
#include "Queue.h"

//Constructor
Queue::Queue()
{

}

//Deconstructor
Queue::~Queue()
{
	queueDeque.ClearList();
}

//SETTERS
void Queue::Enqueue(string nameString)
{
	//Inserts the next node to the tail of the list to create a queue and outputs to
	//the console. Uses the Deque method InsertTail
	cout << "Entering \"" << nameString << "\" into the Queue!\n\n";
	queueDeque.InsertTail(nameString);
}

string Queue::Dequeue()
{
	//Removes the elements off the queue and outputs what is being removed
	cout << "Removing \"" << queueDeque.PeekHead() << "\" from the Queue!\n\n";
	return queueDeque.RemoveHead();
}

void Queue::ClearQueue()
{
	//Clears the queue
	queueDeque.ClearList();
}

//GETTERS
int Queue::Size()const
{
	//Returns the size of the queue
	cout << "The size of the Queue is: " << queueDeque.Size() << endl << endl;
	return queueDeque.Size();
}

bool Queue::IsEmpty()const
{
	//Checks to see if the queue is empty
	cout << "Is the Queue empty?\n";
	return queueDeque.IsEmpty();
}

void Queue::Display()const
{
	//Calls the Deque display to outputs the elements of the queue
	queueDeque.Display();
}

string Queue::Peek()const
{
	//Returns the head of the queue and outputs to the console
	cout << "The front of the Queue is: \"" << queueDeque.PeekHead()  << "\"\n\n";
	return queueDeque.PeekHead();
}
