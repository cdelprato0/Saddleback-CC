/************************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #4:Binary Search Tree
 * CLASS	    :CS1D
 * SECTION	    :M/W 3:00 PM
 ************************************************************************************/

/************************************************************************************
 * Assignment #4 - Binary Search Tree
 * ----------------------------------------------------------------------------------
 *  This program will be able to create a binary search tree and output different
 *  traversals. The program will add each of the numbers that was provided and will
 *  save the number into the tree. After it has been saved into the tree it will
 *  perform the traversals. The first will output the breathOrder traversal which
 *  will print level order. Next it will print out the Pre-order traversal goes from
 *  root down all the way left then switches side and goes all the way down the tree.
 *  Then the Inorder traversal will be called and will read the tree from left to
 *  right like a scanner. After that it will output the Postorder traversal which
 *  will starts at the bottom left of the tree and makes its way up left from right
 *  to the root. Finally it will output the the whole binary search tree.
 * ----------------------------------------------------------------------------------
 ************************************************************************************/
#include "Tree.h"
#include "Node.h"

int main(){

cout << "**************************************************************************\n"
		"* PROGRAMMED BY : Chaz Del Prato                                         *\n"
		"* ASSIGNMENT #4 : Binary Search Tree                                     *\n"
		"* CLASS         : CS1D                                                   *\n"
		"* SECTION       : MW 3:00p                                               *\n"
		"--------------------------------------------------------------------------\n"
		"* Description   :                                                        *\n"
		"*  The output of this program will display the adding of nodes to the    *\n"
		"*  tree and will show different traversals that the tree can perform and *\n"
		"*  will be able to output the tree to the console. It will display adding*\n"
		"*  the nodes to the tree. It will then output the Breath order traversal *\n"
		"*  and after that it will display the Pre-order traversal. After that it *\n"
		"*  will show the Inorder traversal and then will finally output the post *\n"
		"*  order traversal.                                                      *\n"
		"*  The output of the binary tree is not the best but hopefully can get   *\n"
		"*  the picture accross.                                                  *\n"
		"**************************************************************************\n\n";
	//Dynamically creates new tree
    Tree* tree = new Tree();

    //Adds all the numbers into the tree
    tree->addNode(88);
	tree->addNode(12);
	tree->addNode(24);
	tree->addNode(49);
	tree->addNode(7);
	tree->addNode(25);
	tree->addNode(55);
	tree->addNode(18);
	tree->addNode(19);
	tree->addNode(13);
	tree->addNode(109);
	tree->addNode(18);
	tree->addNode(44);
	tree->addNode(1001);

	//Prints out the Breath Order traversal
    cout << "\nBreath Order Traversal...\n";
    tree->breathOrder(tree->Root());
    cout << endl;

    //Prints out the Pre-Order traversal
    cout << "\nPre-order traversal...\n";
    tree->Preorder(tree->Root());
	cout << endl;

	//Prints out the In-Order Traversal
    cout << "\nIn-order traversal...\n";
	tree->Inorder(tree->Root());
	cout << endl;

	//Prints out the Postorder traversal
    cout << "\nPost-order traversal...\n";
	tree->Postorder(tree->Root());
	cout << endl;

	//Print out the Binary Search Tree
	cout << "Displaying the Binary Search Tree...\n\n";
	tree->Display(tree->Root(), 0);

	//Deletes the tree so no memory leaks
    delete tree;

    return 0;
}
