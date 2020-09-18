/************************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #4:Binary Search Tree
 * CLASS	    :CS1D
 * SECTION	    :M/W 3:00 PM
 ************************************************************************************/
#ifndef NODE_H_
#define NODE_H_
#include <string>
using namespace std;

//Struct that holds the node variables
class Node {

    int key;
    Node* left;
    Node* right;

public:
    //Constuctor
    Node() ;

    //SETTERS
    void setKey(int aKey);
    void setLeft(Node* aLeft);
    void setRight(Node* aRight);

    //GETTERS
    int Key();
    Node* Left();
    Node* Right();
};

#endif /* NODE_H_ */
