/************************************************************************************
 * AUTHOR	     :Chaz Del Prato
 * STUDENT ID    :382108
 * Assignment #11:BFS and DFS Graphs
 * CLASS	     :CS1D
 * SECTION	     :M/W 3:00 PM
 ************************************************************************************/

/************************************************************************************
 * Assignment #11
 * ------------------------------
 * 	This program will be working with a DFS and BFS traversals in a graph.
 *	We will be checking the Depth First Search first. We will be starting at Atlanta
 *	and moving across the United States. There is a total of 12 cities to visit.
 *	The DFS will determine the order of the cities by going to the next smallest edge
 *	of the graph. It will output the city we start at then it will show the next city
 *	and if the edge is a discovery or back edge. After the DFS we go to the Breath
 *	First Search, which will do a level by level output of the graph. There will be
 *	a total of four levels that will output the corresponding cities. At the end of
 *	the program it will output and describe strong connectivity
 ************************************************************************************/
#include"MyGraph.h"

int main(){
//OUTPUT - Will output the header and a description of the output
cout << "*************************************************************************\n"
		"* PROGRAMMED BY  : Chaz Del Prato                                       *\n"
		"* ASSIGNMENT #11 : BFS and DFS Graphs                                   *\n"
		"* CLASS          : CS1D                                                 *\n"
		"* SECTION        : MW 3:00p                                             *\n"
		"-------------------------------------------------------------------------\n"
		"* Description   :                                                       *\n"
		"*  This program demonstrates the implementation of a Depth-First        *\n"
		"*  Traversal and Breadth-First Traversal.  The program will traverse a  *\n"
		"*  map that goes across the United States.  The starting point will be  *\n"
		"*  Atlanta. The program will out put the current city and then will say *\n"
		"*  if the next city to visit is going to be a discovery edge or a back  *\n"
		"*  edge. After that DFS traversal is done, then it will out put the     *\n"
		"*  levels of the BFS traversal with the cities that are stored there.   *\n"
		"*  At the end of the program, it will display that the graph and strong *\n"
		"*  Connectivity and will give a brief description.                      *\n"
		"*************************************************************************\n\n";

	/**************************
	 * INITIALIZE AND DECLARE *
	 **************************/
	int     sizes[] = {1,3,2,1,1,2,1,2,2,1,2,5}; //array of number of adjacent cities for a vertex
	int     k = 0;                               //temporary index
	MyGraph myGr;                                //graph object

	//array of cities
	string cities[] ={"Los Angeles", "Dallas",   "Houston",  "Miami",
			          "Atlanta",     "New York", "Boston",   "Chicago",
					  "Seattle",     "San Francisco", "Denver", "Kansas City"};
	//array of verticies w/ adjacent cities
	string edges[]= {"Los Angeles",   "Denver",        "1015", 																								  // 1
					 "Dallas",        "Kansas City",   "496",  "Atlanta",       "781",  "Los Angeles", "1435",												  // 3
					 "Houston",       "Atlanta",       "810",  "Dallas",        "239", 																		  // 2
					 "Miami",         "Houston",       "1187",																							      // 1
					 "Atlanta",       "Miami",         "661",																								  // 1
					 "New York",      "Chicago",       "787",  "Atlanta",       "888", 																		  // 2
					 "Boston",        "New York",      "214", 																								  // 1
					 "Chicago",       "Seattle",       "2097", "Boston",        "983", 												                          // 2
					 "Seattle",       "Denver",        "1331", "San Francisco", "807",																		  // 2
					 "San Francisco", "Los Angeles",   "381", 																								  // 1
					 "Denver",        "Chicago",       "1003", "San Francisco", "1267",                                                                       // 2
					 "Kansas City",   "Atlanta",       "864",  "New York",    "1260", "Chicago",       "533",  "Denver",      "599",  "Los Angeles", "1663"}; // 5

	/**************
	 * PROCESSING *
	 **************/
	//initialize cities and their adjacent cities
	for(int i = 0; i < 12 ; i++){
		string key = edges[k++];         //temporary string variable w/city
		vector<E> temp;                  //temporary vector
		map <string, vector <E> > myMap; //cities(key), adjacent cities(value)

		//puts together vector of adjacent cities
		for(int p = 0 ; p < sizes[i]; p++){
			edge.city = edges[k++];
			edge.miles = atof(edges[k++].c_str());
			temp.push_back(edge);
		}

		myMap[key] = temp;                          //initializes adjacent cities to vertex
		vector < map <string, vector <E> > > myVec; //vector of verticies w/ adjacent cities
		myVec.push_back(myMap);                     //initializes vector of verticies w/ adjacent cities
		myGr.addObject(myMap);                      //adds vector as an attribute to the object
	}

	cout << "**********************\n"
			"* Depth-First Search *\n"
			"**********************\n";
	myGr.DFS("Atlanta");

	cout << "\nBack Edges: \n"
			"------------\n"
		    "Houston to Atlanta\n"
			"Dallas to Atlanta\n"
			"Kansas City to Atlanta\n"
			"New York to Atlanta\n"
			"New York to Chicago\n"
			"Denver to San Francisco\n"
			"Denver to Chicago\n\n";

	cout << "************************\n"
			"* Breadth-First Search *\n"
			"************************\n";
	myGr.BFS("Atlanta");

	cout << "***********************\n"
			"* Strong Connectivity *\n"
			"***********************\n";
	cout << "The graph is strongly connected because you are able to visit\n"
			"each city starting at any vertex.\n";

	return 0;
}




