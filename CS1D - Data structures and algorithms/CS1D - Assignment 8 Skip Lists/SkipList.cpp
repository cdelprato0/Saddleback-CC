/************************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #8:Skip Lists
 * CLASS	    :CS1D
 * SECTION	    :M/W 3:00 PM
 ************************************************************************************/
#include "SkipList.h"

// constructor
Skip_Node::Skip_Node (int k, const string& v, int level)
    :  key(k), value(v)
{
    for (int i = 0; i < level; ++i){
    	forward.push_back(NULL);
    }
}

// constructor
SkipList::SkipList() : probability(0.5), maxLevel(16)
{
     // smallest possible key
     int headKey = numeric_limits<int>::min();
     head = new Skip_Node(headKey, "head", maxLevel);

     // Initialize the last element of the list

     // largest possible key
     int nilKey = numeric_limits<int>::max();
     NIL = new Skip_Node(nilKey, "NIL", maxLevel);

     // Connect start to end
     // connect all the levels/forward pointers of the header to NIL
     for (size_t i = 0; i < head->forward.size(); ++i) {
         head->forward[i] = NIL;
     }
}

// destructor
SkipList::~SkipList () {
    delete head;
    delete NIL;
}

//It uses rand() scaled by its maximum value: RAND_MAX, so that the randomly
//generated numbers are within [0,1).
int SkipList::randomLevel () {
    int v = 1;

    while ((((double)rand() / RAND_MAX)) < probability &&
           abs(v) < maxLevel) {

        v += 1;
    }
    return abs(v);
}


//It returns the number of non-null pointers corresponding to the level of the
//current node.(the node that contains the checked vector of forward pointers)
//if list empty returns 1.

int SkipList::nodeLevel (const vector<Skip_Node*>& v) {
    int currentLevel = 1;
    // last element's key is the largest
    int nilKey = numeric_limits<int>::max();

    if (v[0]->key == nilKey) {
        return currentLevel;
    }

    for (size_t i = 0; i < v.size(); ++i) {

        if (v[i] != NULL && v[i]->key != nilKey) {
            ++currentLevel;
        } else {
            break;
        }
    }
    return currentLevel;
}

//It prints the key, value, level of each node of the skip list.
//Prints two nodes per line.
void SkipList::print () {
    Skip_Node* list = head;
    int lineLenght = 1;

    cout <<"{\n";

    while (list->forward[0] != NULL) {
        cout <<"Value: "<< list->forward[0]->value
             <<", Key: "<< list->forward[0]->key
             <<", Level: "<< nodeLevel(list->forward);

        list = list->forward[0];

        if (list->forward[0] != NULL) cout <<" | ";

        if (++lineLenght % 2 == 0) cout <<"\n";
    }
    cout <<"}\n";
}

//It searches the skip list and returns the element corresponding
//to the searchKey; otherwise it returns failure, in the form of null pointer.
Skip_Node* SkipList::find(int searchKey) {
    Skip_Node* x = head;
    unsigned int currentMaximum = nodeLevel(head->forward);

    for (unsigned int i = currentMaximum; i-- > 0;) {
        while (x->forward[i] != NULL && x->forward[i]->key < searchKey) {
            x = x->forward[i];
        }
    }
    x = x->forward[0];

    if (x->key == searchKey) {
        return x;
    } else {
        return NULL;
    }
}

//It wraps the Skip_Node constructor which creates a node on the heap and returns
//a pointer to it.
Skip_Node* SkipList::makeNode (int key, string val, int level) {
    return new Skip_Node(key, val, level);
}

//It searches the skip list for elements with seachKey, if there is an element
//with that key its value is reassigned to the newValue, otherwise it creates and
//splices a new node, of random level.
void SkipList::insert(int searchKey, string newValue) {

    Skip_Node* x = NULL;

    // vector of pointers that needs to be updated to account for the new node
    vector<Skip_Node*> update(head->forward);
    unsigned int currentMaximum = nodeLevel(head->forward);
    x = head;

//    // search the list
    for (unsigned int i = currentMaximum; i-- > 0;) {

        while (x->forward[i] != NULL && x->forward[i]->key < searchKey) {

            x = x->forward[i];
        }
        update[i] = x;
    }
    x = x->forward[0];

    // create new node
    int newNodeLevel = 1;

        newNodeLevel = randomLevel();
        int currentLevel = nodeLevel(update);

        if (newNodeLevel > currentLevel) {

            for (int i = currentLevel + 1; i < newNodeLevel; ++i) {

                update[i] = head;
            }
        }
        x = makeNode(searchKey, newValue, newNodeLevel);

    // connect pointers of predecessors and new node to successors
    for (int i = 0; i < newNodeLevel; ++i) {

        x->forward[i] = update[i]->forward[i];
        update[i]->forward[i] = x;
    }
}


//It deletes the element containing searchKey, if it exists.
void SkipList::erase (int searchKey) {
    // vector of pointers that needs to be updated to account for the deleted node
    vector<Skip_Node*> update(head->forward);
    Skip_Node* x = head;
    unsigned int currentMaximum = nodeLevel(head->forward);

    // search and update pointers
    for (unsigned int i = currentMaximum; i-- > 0;) {

        while (x->forward[i] != NULL && x->forward[i]->key < searchKey) {

            x = x->forward[i];
        }
        update[i] = x;
    }
    x = x->forward[0];

    // update pointers and delete node
    if (x->key == searchKey) {
        for (size_t i = 0; i < update.size(); ++i) {

            if (update[i]->forward[i] != x) {

                break;
            }
            update[i]->forward[i] = x->forward[i];
        }
        delete x;
    }
    else{
    	cout << "*****   KEY NOT FOUND   *****\n\n";
    }
}

//returns the size of the skip list
int SkipList::size(){
	int size = 0;
	Skip_Node* list = head;

	while(list->forward[0] != NULL){
		size++;
		list = list->forward[0];
	}

	return size;
}
