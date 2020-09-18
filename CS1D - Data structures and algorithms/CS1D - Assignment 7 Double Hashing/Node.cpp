/************************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #7:Double Hashing
 * CLASS	    :CS1D
 * SECTION	    :M/W 3:00 PM
 ************************************************************************************/
#include "Node.h"

//Constructor
Node::Node() {
	key = 0;

}

//DeConstructor
Node::~Node() {

}

//Non default constructor
Node::Node(int keyInt, string valueString){
	key = keyInt;
	value = valueString;
}

//returns key
int Node::getKey()const{
	return key;
}

//returns the value
string Node::getValue()const{
	return value;
}

//sets the key
void Node::setKey(int keyInt){
	key = keyInt;
}

//sets the value
void Node::setValue(string valueString){
	value = valueString;
}
