/************************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #8:Skip Lists
 * CLASS	    :CS1D
 * SECTION	    :M/W 3:00 PM
 ************************************************************************************/
#ifndef SKIPLIST_H_
#define SKIPLIST_H_

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <limits>
using namespace std;

//keeps track of the node for the skip list
struct Skip_Node {
    int key;
    string value;

    // pointers to successor nodes
    vector<Skip_Node*> forward;

    Skip_Node (int k, const string& v, int level);
};


class SkipList {
public:
    SkipList ();
    ~SkipList ();

    // non-modifying member functions
    void print ();
    Skip_Node* find (int searchKey);
    int size();

    // modifying member functions
    void insert (int searchKey, string newValue);
    void erase (int searchKey);

private:
    // pointer to first node
    Skip_Node* head;
    // last node
    Skip_Node* NIL;

    // implicitly used member functions
    int randomLevel ();
    int nodeLevel(const vector<Skip_Node*>& v);
    Skip_Node* makeNode (int key, string val, int level);

    // data members
    float probability;
    int maxLevel;
};

#endif /* SKIPLIST_H_ */
