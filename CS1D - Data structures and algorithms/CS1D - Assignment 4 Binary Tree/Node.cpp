/************************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #4:Binary Search Tree
 * CLASS	    :CS1D
 * SECTION	    :M/W 3:00 PM
 ************************************************************************************/
#include "Node.h"

Node::Node() {
	// TODO Auto-generated constructor stub
	key = -1;
	left = NULL;
	right = NULL;
}

//Sets the integer key
void Node::setKey(int aKey) {
	key = aKey;
}

//Sets the node to the left of the tree
void Node::setLeft(Node* aLeft) {
	left = aLeft;
}

//Sets the node to the right of the tree
void Node::setRight(Node* aRight) {
	right = aRight;
}

//Returns the key that is saved in the node
int Node::Key() {
	return key;
}

//Returns the number in the left node
Node* Node::Left() {
	return left;
}

//Returns the number in the right node
Node* Node::Right() {

	return right;
}
