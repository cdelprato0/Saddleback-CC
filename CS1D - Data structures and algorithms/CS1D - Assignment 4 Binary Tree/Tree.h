/************************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #4:Binary Search Tree
 * CLASS	    :CS1D
 * SECTION	    :M/W 3:00 PM
 ************************************************************************************/
#ifndef TREE_H_
#define TREE_H_
#include "Node.h"
#include <queue>
#include <iostream>

class Tree {

	Node* root;
public:
	//Constructor and de-constructor
    Tree();
    ~Tree();

    //Adds using a queue
    Node* Root();
    void addNode(int key);

    //The print functions for each traversal
    void breathOrder(Node* n);
    void Inorder(Node* );
    void Postorder(Node* );
    void Preorder(Node* node);

    void Display(Node *current, int indent);

private:
    //Privately adds the nodes to the tree
   void addNode(int key, Node* leaf);
   void freeNode(Node* leaf);
};

#endif /* TREE_H_ */
