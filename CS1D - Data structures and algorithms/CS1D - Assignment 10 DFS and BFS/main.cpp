/************************************************************************************
 * AUTHOR	     :Chaz Del Prato
 * STUDENT ID    :382108
 * Assignment #10:BFS and DFS Graphs
 * CLASS	     :CS1D
 * SECTION	     :M/W 3:00 PM
 ************************************************************************************/

/************************************************************************************
 * Assignment #10
 * ------------------------------
 * 	This program will be working with a DFS and BFS traversals in a graph.
 *	We will be checking the Depth First Search first. We will be starting at Seattle
 *	and moving across the United States. There is a total of 12 cities to visit.
 *	The DFS will determine the order of the cities by going to the next smallest edge
 *	of the graph. It will output the city we start at then it will show the next city
 *	and if the edge is a discovery or back edge. After the DFS we go to the Breath
 *	First Search, which will do a level by level output of the graph. There will be
 *	a total of four levels that will output the corresponding cities.
 ************************************************************************************/
#include"MyGraph.h"

int main(){
//OUTPUT - Will output the header and a description of the output
cout << "*************************************************************************\n"
		"* PROGRAMMED BY  : Chaz Del Prato                                       *\n"
		"* ASSIGNMENT #10 : BFS and DFS Graphs                                   *\n"
		"* CLASS          : CS1D                                                 *\n"
		"* SECTION        : MW 3:00p                                             *\n"
		"-------------------------------------------------------------------------\n"
		"* Description   :                                                       *\n"
		"*  This program demonstrates the implementation of a Depth-First        *\n"
		"*  Traversal and Breadth-First Traversal.  The program will traverse a  *\n"
		"*  map that goes across the United States.  The starting point will be  *\n"
		"*  Seattle. The program will out put the current city and then will say *\n"
		"*  if the next city to visit is going to be a discovery edge or a back  *\n"
		"*  edge. After that DFS traversal is done, then it will out put the     *\n"
		"*  levels of the BFS traversal with the cities that are stored there.   *\n"
		"*************************************************************************\n\n";

	string edges[]= {"Los Angeles", "San Francisco", "381", "Denver", "1015", "Kansas City", "1663", "Dallas","1435",
					"Dallas", "Kansas City", "496", "Atlanta", "781", "Houston", "239","Los Angeles", "1435",
					"Houston", "Miami", "1187", "Atlanta", "810", "Dallas", "239",
					"Miami", "Atlanta", "661", "Houston","1187",
					"Atlanta", "Kansas City", "864", "New York", "888", "Dallas", "781", "Houston", "810", "Miami", "661",
					"New York", "Boston", "214","Chicago", "787","Kansas City", "1260", "Atlanta", "888",
					"Boston", "Chicago", "983", "New York", "214",
					"Chicago", "Kansas City", "533", "Denver", "1003", "Seattle", "2097","New York","787","Boston","983",
					"Seattle", "Denver", "1331", "San Francisco", "807", "Chicago", "2097",
					"San Francisco", "Denver", "1267", "Seattle","807","Los Angeles", "381",
					"Denver", "Kansas City", "599", "Chicago", "1003", "Seattle","1331","San Francisco","1267","Los Angeles", "1015",
					"Kansas City","Dallas", "496", "Atlanta","864","New York", "1260", "Chicago","533","Denver","599","Los Angeles", "1663"};

	int sizes[] = {4,4,3,2,5,4,2,5,3,3,5,6};
	int k = 0;
	MyGraph myGr;
	for(int i = 0; i < 12 ; i++){
		string key = edges[k++];
		vector<E> temp;
		map <string, vector <E> > myMap;
		for(int p = 0 ; p < sizes[i]; p++){
			edge.city = edges[k++];
			edge.miles = atof(edges[k++].c_str());
			temp.push_back(edge);
		}
		myMap[key] = temp;
		vector < map <string, vector <E> > > myVec;
		myVec.push_back(myMap);
		myGr.addObject(myMap);
	}

	myGr.DFS("Seattle");
	myGr.BFS("Seattle");

	return 0;
}




