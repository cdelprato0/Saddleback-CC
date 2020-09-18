/*
 * Queue.h
 *
 *  Created on: Apr 13, 2015
 *      Author: cdelprato0
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "Header.h"
#include "List.h"
using namespace std;

class Queue {
public:
	Queue();
	virtual ~Queue();

	//SETTERS
	void Enqueue(Person);
	Person Dequeue();
	void ClearQueue();

	//GETTERS
	int Size()const;
	bool IsEmpty()const;
	void Display()const;

private:
	List queueL;
};

#endif /* QUEUE_H_ */
