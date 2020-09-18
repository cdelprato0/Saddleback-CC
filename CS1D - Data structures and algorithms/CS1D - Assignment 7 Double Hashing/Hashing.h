/************************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #7:Double Hashing
 * CLASS	    :CS1D
 * SECTION	    :M/W 3:00 PM
 ************************************************************************************/
#ifndef HASHING_H_
#define HASHING_H_
#include "Node.h"

class Hashing {
public:
	Hashing();
	Hashing(Node newCity);
	virtual ~Hashing();

	int HashFunctionOne(Node newCity);
	int HashFunctionTwo(Node newCity);

	void AddToHash(Node newCity);
	void DeleteFromHash(int key);

	void Print()const;
private:

	//Uses an ARRAY for data structure
	int size;
	Node cityHashTable[31];

};

#endif /* HASHING_H_ */
