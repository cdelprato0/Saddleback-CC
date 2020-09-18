/************************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #3:Queues - Deques
 * CLASS	    :CS1D
 * SECTION	    :M/W 3:00 PM
 ************************************************************************************/
#ifndef QUEUE_H_
#define QUEUE_H_

#include "Deque.h"
#include <iostream>
#include <string>
using namespace std;

class Queue {
public:
	Queue();
	virtual ~Queue();

	//SETTERS
	void Enqueue(string name);
	string Dequeue();
	void ClearQueue();

	//GETTERS
	int Size()const;
	bool IsEmpty()const;
	void Display()const;
	string Peek()const;

private:
	Deque queueDeque; //Calls the Deque class in order to perform its operations
};

#endif /* QUEUE_H_ */
