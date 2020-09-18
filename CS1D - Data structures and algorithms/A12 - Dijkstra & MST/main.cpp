/************************************************************************************
 * AUTHOR	     :Chaz Del Prato
 * STUDENT ID    :382108
 * Assignment #12:Dijkstra's and MST
 * CLASS	     :CS1D
 * SECTION	     :M/W 3:00 PM
 ************************************************************************************/

/************************************************************************************
 * Assignment #12
 * --------------
 * 	This program will be able to demonstrate Dijkstra's Algorithm and MST.
 * 	The program will first demonstrate the DA starting at Kansas City and will show
 * 	the shortest distance to each city. After it will show the Minimum Spanning Tree
 * 	with the total distance and will show the edges between cities.
 ************************************************************************************/
#include "header.h"
#include <stdio.h>
#include <limits.h>

// Number of vertices in the graph
#define V 12

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
   // Initialize min value
   int min = INT_MAX, min_index;

   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;

   return min_index;
}

// A utility function to print the constructed distance array
void printSolution(int dist[], int n)
{
	string temp;
   for (int i = 0; i < V; i++){
	   switch(i) {
	   case LOS_ANGELES:   temp = "Los Angeles";
	   	   	   	   	   	   break;
	   case SAN_FRANCISCO: temp = "San Francisco";
	   	   	   	   	   	   break;
	   case SEATTLE:       temp = "Seattle";
	   	   	   	   	   	   break;
	   case DENVER:        temp = "Denver";
	   	   	   	   	   	   break;
	   case CHICAGO:       temp = "Chicago";
	   	   	   	   	   	   break;
	   case KANSAS_CITY:   temp = "Kansas City";
	   	   	   	   	   	   break;
	   case DALLAS:        temp = "Dallas";
	   	   	   	   	   	   break;
	   case HOUSTON:       temp = "Houston";
	   	   	   	   	   	   break;
	   case MIAMI:         temp = "Miami";
	   	   	   	   	   	   break;
	   case ATLANTA:       temp = "Atlanta";
	   	   	   	   	   	   break;
	   case NEW_YORK:      temp = "New York";
	   	   	   	   	   	   break;
	   case BOSTON:        temp = "Boston";
	   	   	   	   	   	   break;
	   }

	   cout << temp << " (Distance from Kansas City is " << dist[i] << ")\n\n";
   }

}

// Funtion that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
     int dist[V];     // The output array.  dist[i] will hold the shortest
                      // distance from src to i

     bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest
                     // path tree or shortest distance from src to i is finalized

     // Initialize all distances as INFINITE and stpSet[] as false
     for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

     // Distance of source vertex from itself is always 0
     dist[src] = 0;

     // Find shortest path for all vertices
     for (int count = 0; count < V-1; count++)
     {
       // Pick the minimum distance vertex from the set of vertices not
       // yet processed. u is always equal to src in first iteration.
       int u = minDistance(dist, sptSet);

       // Mark the picked vertex as processed
       sptSet[u] = true;

       // Update dist value of the adjacent vertices of the picked vertex.
       for (int v = 0; v < V; v++)

         // Update dist[v] only if is not in sptSet, there is an edge from
         // u to v, and total weight of path from src to  v through u is
         // smaller than current value of dist[v]
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                                       && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
     }

     // print the constructed distance array
     printSolution(dist, V);
}

// A utility function to find the vertex with minimum key value, from
// the set of vertices not yet included in MST
int minKey(int key[], bool mstSet[])
{
   // Initialize min value
   int min = INT_MAX, min_index;

   for (int v = 0; v < V; v++)
     if (mstSet[v] == false && key[v] < min)
         min = key[v], min_index = v;

   return min_index;
}

// A utility function to print the constructed MST stored in parent[]
void printMST(int parent[], int n, int graph[V][V])
{
	string temp;
	string pTemp;
	long sum = 0;

	for (int i = 1; i < V; i++){
	   switch(i) {
	   case LOS_ANGELES:   temp = "Los Angeles";
	   	   	   	   	   	   break;
	   case SAN_FRANCISCO: temp = "San Francisco";
	   	   	   	   	   	   break;
	   case SEATTLE:       temp = "Seattle";
	   	   	   	   	   	   break;
	   case DENVER:        temp = "Denver";
	   	   	   	   	   	   break;
	   case CHICAGO:       temp = "Chicago";
	   	   	   	   	   	   break;
	   case KANSAS_CITY:   temp = "Kansas City";
	   	   	   	   	   	   break;
	   case DALLAS:        temp = "Dallas";
	   	   	   	   	   	   break;
	   case HOUSTON:       temp = "Houston";
	   	   	   	   	   	   break;
	   case MIAMI:         temp = "Miami";
	   	   	   	   	   	   break;
	   case ATLANTA:       temp = "Atlanta";
	   	   	   	   	   	   break;
	   case NEW_YORK:      temp = "New York";
	   	   	   	   	   	   break;
	   case BOSTON:        temp = "Boston";
	   	   	   	   	   	   break;
	   }

	   switch(parent[i]) {
	   case LOS_ANGELES:   pTemp = "Los Angeles";
	   	   	   	   	   	   break;
	   case SAN_FRANCISCO: pTemp = "San Francisco";
	   	   	   	   	   	   break;
	   case SEATTLE:       pTemp = "Seattle";
	   	   	   	   	   	   break;
	   case DENVER:        pTemp = "Denver";
	   	   	   	   	   	   break;
	   case CHICAGO:       pTemp = "Chicago";
	   	   	   	   	   	   break;
	   case KANSAS_CITY:   pTemp = "Kansas City";
	   	   	   	   	   	   break;
	   case DALLAS:        pTemp = "Dallas";
	   	   	   	   	   	   break;
	   case HOUSTON:       pTemp = "Houston";
	   	   	   	   	   	   break;
	   case MIAMI:         pTemp = "Miami";
	   	   	   	   	   	   break;
	   case ATLANTA:       pTemp = "Atlanta";
	   	   	   	   	   	   break;
	   case NEW_YORK:      pTemp = "New York";
	   	   	   	   	   	   break;
	   case BOSTON:        pTemp = "Boston";
	   	   	   	   	   	   break;
	   }

	   sum = sum + graph[i][parent[i]];
	   cout << pTemp << " - " << temp << "  Weight: " << graph[i][parent[i]] << endl << endl;
   }
   cout << "Total Distance: " << sum;
}

// Function to construct and print MST for a graph represented using adjacency
// matrix representation
void primMST(int graph[V][V])
{
     int parent[V]; // Array to store constructed MST
     int key[V];   // Key values used to pick minimum weight edge in cut
     bool mstSet[V];  // To represent set of vertices not yet included in MST

     // Initialize all keys as INFINITE
     for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

     // Always include first 1st vertex in MST.
     key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
     parent[0] = -1; // First node is always root of MST

     // The MST will have V vertices
     for (int count = 0; count < V-1; count++)
     {
        // Pick the minimum key vertex from the set of vertices
        // not yet included in MST
        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices of
        // the picked vertex. Consider only those vertices which are not yet
        // included in MST
        for (int v = 0; v < V; v++)

           // graph[u][v] is non zero only for adjacent vertices of m
           // mstSet[v] is false for vertices not yet included in MST
           // Update the key only if graph[u][v] is smaller than key[v]
          if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
             parent[v]  = u, key[v] = graph[u][v];
     }

     // print the constructed MST
     printMST(parent, V, graph);
}

int main(){
//OUTPUT - Will output the header and a description of the output
cout << "*************************************************************************\n"
		"* PROGRAMMED BY  : Chaz Del Prato                                       *\n"
		"* ASSIGNMENT #12 : Dijkstra's and MST                                   *\n"
		"* CLASS          : CS1D                                                 *\n"
		"* SECTION        : MW 3:00p                                             *\n"
		"-------------------------------------------------------------------------\n"
		"* Description   :                                                       *\n"
		"*   This prgram will show the use of Dijkstra's Algorithm and the MST   *\n"
		"* of the graph. The fisrt part of the program will show Dijkstra's and  *\n"
		"* will show the the shortest distances to each of the cities starting at*\n"
		"* Kansas City. After it will show the MST Minimum Spanning Tree with the*\n"
		"* identity edges and finally will show the total distance of the MST.   *\n"
		"*************************************************************************\n\n";

    //INITIALIZE/DECLARE
    int graph[V][V] = { {0,    381,  0,    1015, 0,    1663, 1435, 0,    0,    0,   0,    0},
    				    {381,  0,    807,  1267, 0,    0,    0,    0,    0,    0,   0,    0},
					    {0,    807,  0,    1331, 2097, 0,    0,    0,    0,    0,   0,    0},
					    {1015, 1267, 1331, 0,    1003, 599,  0,    0,    0,    0,   0,    0},
					    {0,    0,    2097, 1003, 0,    533,  0,    0,    0,    0,   787,  983},
					    {1663, 0,    0,    599,  533,  0,    496,  0,    0,    864, 1260, 0},
					    {1435, 0,    0,    0,    0,    496,  0,    239,  0,    781, 0,    0},
					    {0,    0,    0,    0,    0,    0,    239,  0,    1187, 810, 0,    0},
					    {0,    0,    0,    0,    0,    0,    0,    1187, 0,    661, 0,    0},
					    {0,    0,    0,    0,    0,    864,  781,  810,  661,  0,   888,  0},
					    {0,    0,    0,    0,    787,  1260, 0,    0,    0,    888, 0,    214},
					    {0,    0,    0,    0,    983,  0,    0,    0,    0,    0,   214,  0}
    			      };

    cout << "**********************\n"
    		"* DIJKSTRA Algorithm *\n"
    		"**********************\n";
    dijkstra(graph, KANSAS_CITY);

    cout << "\n*************************\n"
    		"* Minimum Spanning Tree *\n"
    		"*************************\n";
    primMST(graph);

    return 0;

}
