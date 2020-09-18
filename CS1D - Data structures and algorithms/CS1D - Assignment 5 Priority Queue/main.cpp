/************************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #5:Priority Queue
 * CLASS	    :CS1D
 * SECTION	    :M/W 3:00 PM
 ***********************************************************************************/

/************************************************************************************
 * Assignment #5 - Priority Queues
 * -------------------------------
 * This program will be able to take in an integer array and load the integer array
 * into a priority queue and save the values from least to greatest. The program
 * will run through the priority queue and determine when each patient is allowed to
 * see Dr. DoGood. Each patient will be allowed 20 minutes but if there was a life
 * threatening emergency then the current patients time will stop and the Dr will
 * go take care of the emergency for 20 minutes and then will return to the patient
 * before the emergency.
 * ----------------------------------------------------------------------------------
 ***********************************************************************************/
#include <queue>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

//Used for PriorityQueue STL
priority_queue <int, std::vector<int>, std::greater<int> > p2;

//Holds the value of the ER waiting hours
int intArray[] = {-6,-7,-4,2,-5,-2,-3,-1,1};


//*******************************************
//************CLASS DEFINITION***************
//*******************************************
#ifndef PRIORITYQUEUE_H_
#define PRIORITYQUEUE_H_
#include <string>
#include <list>
using namespace std;

template <class E>
class PriorityQueue {

protected:
	typedef std::list<E> prioQueue;

public:
	class PositionClass{
		const E& operator*() {return *q;}
		friend class PriorityQueue;

	private:
		typename prioQueue::iterator q;
	};

public:
	PriorityQueue(int max);
	virtual ~PriorityQueue();

	int getSize()const;
	bool isEmpty()const;
	const E& min()const;
	void removeMin();
	void remove(const PositionClass& pos);

	PositionClass replace(const PositionClass& p, const E& element);
	PositionClass insert(const E& element);


private:

	prioQueue priority;

};

#endif


//***********************************************************
//*****************METHODS IMPLEMENTATION********************
//***********************************************************
//Constructor
template <class E>
PriorityQueue<E>::PriorityQueue(int max){
	max = 0;
}

//De-constructor
template <class E>
PriorityQueue<E>::~PriorityQueue(){

}

//Returns the size of the queue
template <class E>
int PriorityQueue<E>::getSize() const
{
	return priority.size();
}

//Checks to see if the queue is empty
template <class E>
bool PriorityQueue<E>::isEmpty() const
{
	return (priority.empty());
}

//Returns the min value of queue
template <class E>
const E& PriorityQueue<E>::min() const
{
	return (priority.front());
}

//Removed the in value from the queue
template <class E>
void PriorityQueue<E>::removeMin()
{
	priority.pop_front();
}

//Remove a certain element off the queue
template <class E>
void PriorityQueue<E>::remove(const PositionClass& pos)
{
	priority.erase(pos,pos.q);
}

template <class E>
typename PriorityQueue<E>::
PositionClass PriorityQueue<E>::insert(const E& element)
{
	typename prioQueue::iterator pos = priority.begin();

	//Find a larger element
	while(pos != priority.end() && !(element < *pos)) ++pos;

	//inserts before pos
	priority.insert(pos, element);

	PositionClass position;
	position.q = --pos;

	//returns the position
	return position;
}

//Replaces an element on the queue
template <class E>
typename PriorityQueue<E>::
PositionClass PriorityQueue<E>::replace(const PositionClass& pos, const E& element)
{
	priority.erase(pos,pos.q);

	return insert(element);
}

//MAIN
int main()
{
	int hour = 12;
	int minutes = 0;
	int index = 0;

	//OUTPUT - Will output the header and a description of the output
cout << "**************************************************************************\n"
		"* PROGRAMMED BY : Chaz Del Prato                                         *\n"
		"* ASSIGNMENT #5 : Priority Queues                                        *\n"
		"* CLASS         : CS1D                                                   *\n"
		"* SECTION       : MW 3:00p                                               *\n"
		"--------------------------------------------------------------------------\n"
		"* Description   :                                                        *\n"
		"*  This program will start with outputting PART ONE of the assignment    *\n"
		"*  which is using the UN-SORTED list to complete the emergency room      *\n"
		"*  Scenario. The output will start with the patient that has been waiting*\n"
		"*  the longest since before 12(noon). Then it will output the remaining  *\n"
		"*  in the order they have waited. There will be two life threatening     *\n"
		"*  Emergencies that will happen throughout the output and will state when*\n"
		"*  they are occurring. After the emergencies, the remaining time will be *\n"
		"*  fulfilled to the patient that was left and then will carry on through *\n"
		"*  the priority queue. After the first implementation of the UN-SORTED   *\n"
		"*  list, now it will go into the STL priority queue. It will be reusing  *\n"
		"*  Most of the output but will be using the STL to complete the          *\n"
		"*  operations.                                                           *\n"
		"**************************************************************************\n";

	//PART ONE
	cout << "\n\n*********************************\n"
			"*           PART ONE            *\n"
			"*USING IMPLMENTED UN-SORTED LIST*\n"
			"*********************************\n\n";

	//Will call the priority queue template implementation
	PriorityQueue<int> newQueue(9);
	hour = 12;
	minutes = 0;

	//Adds the times into a queue
	for( index = 0; index < 9; index++  ){

		newQueue.insert(intArray[index]);
	}//End FOR

	while ( !newQueue.isEmpty() ){
		switch(newQueue.min())
		{
		case -7: cout << "The patient, Frank Feelingbad has be been waiting "
					 << std::abs(newQueue.min()) << " hours!!\n"
					 << "They will now be admitted at " << hour << ":" << minutes
					 << minutes << endl;
				minutes = minutes + 20;
				cout << "Frank Feelingbad has been released at " << hour << ":"
					 << minutes << endl << endl;
				newQueue.removeMin();
				break;
		case -6: cout << "The patient, Irene Ill has be been waiting "
					 << std::abs(newQueue.min()) << " hours!!\n"
					 << "They will now be admitted at " << hour << ":" << minutes
					 << endl;
				minutes = minutes + 2;

				cout << "\n*******LIFE THREATENING EMERGENCY*******\n" << "Admitting "
						"Bob Bleeding at " << hour << ":" << minutes << endl;
				minutes  = minutes + 20;
				cout << "Bob Bleeding has been released at " << hour << ":" << minutes
					 << endl << endl;

				hour = 1;
				minutes = 0;
				cout << "Irene Ill has been released at " << hour << ":"
					 << minutes << minutes << endl << endl;
				newQueue.removeMin();
				break;
		case -5: cout << "The patient, Alice Ailment has be been waiting "
					 << std::abs(newQueue.min()) << " hours!!\n"
					 << "They will now be admitted at " << hour << ":" << minutes
					 << minutes << endl;
				minutes = 20;
				newQueue.removeMin();

				cout << "Alice Ailment has been released at " << hour << ":"
					 << minutes << endl << endl;

				break;
		case -4: cout << "The patient, Cathy Coughing has be been waiting "
					 << std::abs(newQueue.min()) << " hours!!\n"
					 << "They will now be admitted at " << hour << ":" << minutes
					 << endl;
				minutes = minutes + 20;
				cout << "Cathy Coughing has been released at " << hour << ":"
					 << minutes << endl << endl;
				newQueue.removeMin();

				break;
		case -3: cout << "The patient, Sam Sneezing has be been waiting "
					 << (std::abs(newQueue.min()) - .5)<< " hours!!\n"
					 << "They will now be admitted at " << hour << ":" << minutes
					 << endl;
				minutes = minutes + 5;

				cout << "\n*******LIFE THREATENING EMERGENCY*******\n" << "Admitting "
						"Sid Sickly at " << hour << ":" << minutes << endl;
				hour = 2;
				minutes = 0;
				cout << "Sid Sickly has been released at " << hour << ":" << minutes;
				minutes = minutes + 5;
				cout << minutes << endl << endl;

				minutes = minutes + 15;
				cout << "Sam Sneezing has been released at " << hour << ":"
					 << minutes << endl << endl;
				newQueue.removeMin();
				break;

		case -2: cout << "The patient, Paula Pan has be been waiting "
					 << std::abs(newQueue.min()) << " hours!!\n"
					 << "They will now be admitted at " << hour << ":" << minutes
					 << endl;
				minutes = minutes + 20;
				cout << "Paula Pain has been released at " << hour << ":"
					 << minutes << endl << endl;
				newQueue.removeMin();
				break;

		case -1: cout << "The patient, Tom Temperature has be been waiting "
					 << std::abs(newQueue.min()) << " hour!!\n"
					 << "They will now be admitted at " << hour << ":" << minutes
					 << endl;
				hour = 3;
				minutes = 0;
				cout << "Tom Temperture has been released at " << hour << ":"
					 << minutes << minutes << endl << endl;
				newQueue.removeMin();
				newQueue.removeMin();
				newQueue.removeMin();
				break;
		}//End SWITCH
	}//End WHILE


//PART TWO STL
	cout << "\n**************************\n"
			"*        PART TWO        *\n"
			"*USING STL PRIORITY QUEUE*\n"
			"**************************\n";

	hour = 12;
	minutes = 0;

	for( index = 0; index < 9; index++  ){

		p2.push(intArray[index]);

	}//End FOR

	while ( !p2.empty() ){
		switch(p2.top())
		{
		case -7: cout << "The patient, Frank Feelingbad has be been waiting "
				 	 << std::abs(p2.top()) << " hours!!\n"
					 << "They will now be admitted at " << hour << ":" << minutes
					 << minutes << endl;
				minutes = minutes + 20;
				cout << "Frank Feelingbad has been released at " << hour << ":"
					 << minutes << endl << endl;
				p2.pop();
				break;
		case -6: cout << "The patient, Irene Ill has be been waiting "
					 << std::abs(p2.top()) << " hours!!\n"
					 << "They will now be admitted at " << hour << ":" << minutes
					 << endl;
				minutes = minutes + 2;

				cout << "\n*******LIFE THREATENING EMERGENCY*******\n" << "Admitting "
						"Bob Bleeding at " << hour << ":" << minutes << endl;
				minutes  = minutes + 20;
				cout << "Bob Bleeding has been released at " << hour << ":" << minutes
					 << endl << endl;

				hour = 1;
				minutes = 0;
				cout << "Irene Ill has been released at " << hour << ":"
					 << minutes << minutes << endl << endl;
				p2.pop();
				break;
		case -5: cout << "The patient, Alice Ailment has be been waiting "
					 << std::abs(p2.top()) << " hours!!\n"
					 << "They will now be admitted at " << hour << ":" << minutes
					 << minutes << endl;
				minutes = 20;

				cout << "Alice Ailment has been released at " << hour << ":"
					 << minutes << endl << endl;
				p2.pop();
				break;
		case -4: cout << "The patient, Cathy Coughing has be been waiting "
					 << std::abs(p2.top()) << " hours!!\n"
					 << "They will now be admitted at " << hour << ":" << minutes
					 << endl;
				minutes = minutes + 20;
				cout << "Cathy Coughing has been released at " << hour << ":"
					 << minutes << endl << endl;
				p2.pop();

				break;
		case -3: cout << "The patient, Sam Sneezing has be been waiting "
					 << (std::abs(p2.top()) - .5)<< " hours!!\n"
					 << "They will now be admitted at " << hour << ":" << minutes
					 << endl;
				minutes = minutes + 5;

				cout << "\n*******LIFE THREATENING EMERGENCY*******\n" << "Admitting "
						"Sid Sickly at " << hour << ":" << minutes << endl;
				hour = 2;
				minutes = 0;
				cout << "Sid Sickly has been released at " << hour << ":" << minutes;
				minutes = minutes + 5;
				cout << minutes << endl << endl;

				minutes = minutes + 15;
				cout << "Sam Sneezing has been released at " << hour << ":"
					 << minutes << endl << endl;
				p2.pop();
				break;
		case -2:cout << "The patient, Paula Pan has be been waiting "
					 << std::abs(p2.top()) << " hours!!\n"
					 << "They will now be admitted at " << hour << ":" << minutes
					 << endl;
				minutes = minutes + 20;
				cout << "Paula Pain has been released at " << hour << ":"
					 << minutes << endl << endl;
				p2.pop();
				break;

		case -1: cout << "The patient, Tom Temperature has be been waiting "
					 << std::abs(p2.top()) << " hour!!\n"
					 << "They will now be admitted at " << hour << ":" << minutes
					 << endl;
				hour = 3;
				minutes = 0;
				cout << "Tom Temperture has been released at " << hour << ":"
					 << minutes << minutes << endl << endl;
				p2.pop();
				p2.pop();
				p2.pop();
			break;
		}//End SWITCH
	}//End WHILE
	return 0;
}//End Main
