/************************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #4:Binary Search Tree
 * CLASS	    :CS1D
 * SECTION	    :M/W 3:00 PM
 ************************************************************************************/
#include "Tree.h"
#include <iostream>
#include <iomanip>
#include <sstream>


// Constructor
Tree::Tree() {
     root = NULL;
}

// Destructor
Tree::~Tree() {
     freeNode(root);
}

//Returns the rood of the tree
Node* Tree::Root() {
	return root;
}

// Frees the node off the tree
void Tree::freeNode(Node* leaf)
{
	//Deletes the contents off the left
    if ( leaf != NULL )
    {
       freeNode(leaf->Left());
       freeNode(leaf->Right());
       delete leaf;
    }
}

// Adds a node to the tree
void Tree::addNode(int key) {

    // If no elements in the tree, it creates the root. If not then it just adds the
	//node to the tree
    if ( root == NULL ) {

       cout << "Adding root node ... " << key << endl;

       Node* n = new Node();

       n->setKey(key);
       root = n;
    }
    else {

    cout << "Adding other node ... " << key << endl;

    addNode(key, root);
    }
}

// Adds a node using private functions
void Tree::addNode(int key, Node* leaf) {

	if ( key <= leaf->Key() ) {
	   if ( leaf->Left() != NULL ){

		   addNode(key, leaf->Left());
	   }
      else {
    	  Node* n = new Node();

    	  n->setKey(key);
    	  leaf->setLeft(n);
      }
    }
    else {

       if ( leaf->Right() != NULL ){
    	   addNode(key, leaf->Right());
       }
       else
       {
    	   Node* n = new Node();
       	   n->setKey(key);
       	   leaf->setRight(n);
       }
   }
}

// Prints the tree Breath Order Traversal assisted by queue
void Tree::breathOrder(Node* n) {
   // Create a queue
   queue<Node*> q;

   // Push the root
   q.push(n);

   while ( ! q.empty() )
   {
       // Dequeue a node from front
       Node* v = q.front();
       cout << v->Key() << " ";

       // Enqueue the left children
       if ( v->Left() != NULL )
            q.push(v->Left());

       // Enqueue the right children
       if ( v->Right() != NULL )
            q.push(v->Right());

       // Pop the visited node
       q.pop();
   }
}

//Creates the pre-order traversal for the tree
void Tree::Preorder(Node* node)
{
    if ( node )
    {
        cout << node->Key() << " ";
        Preorder(node->Left());
        Preorder(node->Right());
    }
}

//Displays the inorder traversal for the tree
void Tree:: Inorder(Node* Root)
{
    if(Root != NULL)
    {
        Inorder(Root->Left());
        cout << Root->Key() << endl;
        Inorder(Root->Right());

    }
}

//Prints out the postorder traversal for the tree
void Tree::Postorder(Node* Root)
{
    if(Root != NULL)
    {

        Postorder(Root->Left());
        Postorder(Root->Right());
        cout << Root->Key() << endl;

    }
}

//Prints out the binary search tree
void Tree::Display(Node *current, int indent)
{
   if (current != NULL)
   {
       Display(current->Left(), (indent + 4));

       if (indent > 0)
           cout << setw(indent) << " ";

       cout << current->Key() << endl;

       Display(current->Right(), indent + 4);
   }
}
