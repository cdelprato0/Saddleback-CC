/************************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #7:Double Hashing
 * CLASS	    :CS1D
 * SECTION	    :M/W 3:00 PM
 ************************************************************************************/
#ifndef NODE_H_
#define NODE_H_
#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Node {
public:
	Node();
	Node(int keyInt, string valueString);
	virtual ~Node();

	int getKey()   const;
	string getValue() const;

	void setKey(int keyInt);
	void setValue(string valueString);

private:
	int key;
	string value;
};

#endif /* NODE_H_ */
