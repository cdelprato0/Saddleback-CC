/************************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #3:Queues Deques
 * CLASS	    :CS1D
 * SECTION	    :M/W 3:00 PM
 ************************************************************************************/
#ifndef ARRAYVECTOR_H_
#define ARRAYVECTOR_H_

#include <iostream>
#include <string>
using namespace std;

class ArrayVector {
public:
	ArrayVector();
	virtual ~ArrayVector();

	int GetSize();
	bool isEmpty();
	int getCapacity();

	void erase(int index);
	void insert(int index, string newString);
	void reserve(int newCapacity);

	void Display();

private:
	int capacity;
	int size;
	string* strArray;
};

#endif /* ARRAYVECTOR_H_ */
