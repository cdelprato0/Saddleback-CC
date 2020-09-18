/************************************************************************************
 * AUTHOR	     :Chaz Del Prato
 * STUDENT ID    :382108
 * Assignment #11: BFS and DFS Graphs
 * CLASS	     :CS1D
 * SECTION	     :M/W 3:00 PM
 ************************************************************************************/
#ifndef MYGRAPH_H_
#define MYGRAPH_H_

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <queue>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

struct E{
	string city;
	int miles;
	bool visited;

	void SetVisitedTrue() {
		visited = true;
	}
}edge;

string cities[] ={"Los Angeles", "Dallas", "Houston","Atlanta", "New York",
		          "Chicago", "Seattle", "San Francisco", "Denver", "Kansas City", "Boston", "Miami"};

class MyGraph {
	private:
		vector<map <string, vector <E> > > myVector;
		vector <string> compareTo;
		vector <string> visited;
		vector <string> compChild;
		vector <E> secondLevel;
		vector <E> thirdLevel;
		vector <E> firstLevel;
		vector <E> fourthLevel;
		vector <E> fifthLevel;
		vector <E> sixthLevel;
		string city;
		int totalMiles;
		int bfsMiles;
		int count;
		bool flag;
		int flagTwo;
		int q;
	public:

		MyGraph(){
			totalMiles = 0;
			bfsMiles = 0;
			count = 0;
			flag = false;
			flagTwo = 0;
			q =0 ;
		}
		virtual ~MyGraph(){

		}
		void print(){

			for(int i = 0; i < 13; i++){
				typedef map<string, vector <E> >::const_iterator MapIterator;
				for (MapIterator iter = myVector[i].begin(); iter != myVector[i].end(); iter++)
				{
					cout << "From: " << iter->first << endl;//key of the map
					for(unsigned int k = 0; k < iter->second.size(); k++){//value of the map
						cout << "To: " <<iter->second[k].city << ", " << iter->second[k].miles <<endl;
					}
				}
			}
		}
		void addObject(map<string, vector <E> > to){
		    myVector.push_back(to);
		}
		void DFS(string start)
		{
			if(compareTo.size() == 13){
				return;
			}
			DFS(findShortestPath(start));

		}

		string findShortestPath(string root){
			map< string, string> backTrack;
			flag = false;
			compareTo.push_back(root);
			typedef map<string, vector <E> >::const_iterator MapIterator;
			for(int i = 0; i < 12; i++){
				for (MapIterator iter = myVector[i].begin(); iter != myVector[i].end(); iter++){
					int smallest = 10000;
					int index = 0;
					unsigned int counter = 0;


					if(root == iter->first){
						for(unsigned int k = 0; k < iter->second.size(); k++){//value of the map
							for(unsigned int x = 0; x < compareTo.size(); x++){
								if(iter->second[k].city == compareTo[x]){
									flag = true;
									counter++;
								}
								else if(counter == iter->second.size() && flagTwo == 0){
									flagTwo++;
									backTrack[iter->second[index].city]= root;
									cout << "Backtracking from " << root << " to " << iter->second[index].city << endl;
									cout << "--------------------------------------------------------------------\n";
									return iter->second[index].city;
								}
							}
							if(iter->second[k].miles <  smallest && !flag){
								smallest = iter->second[k].miles;
								index = k;
							}
							flag = false;
						}

						if(compareTo.size() == 1){
							cout << "Start at " << root << endl;
							cout << "Discovery Edge from " << root << " to " << iter->second[index].city;
							cout << "  Miles: [" << iter->second[index].miles << "]" << endl;
							totalMiles += iter->second[index].miles;
						}else if(compareTo.size() < 13){
							cout << "Next visit: " << iter->first << endl;
							cout << "Discovery Edge from " << iter->first << " to " << iter->second[index].city;
							cout << "  Miles: [" << iter->second[index].miles << "]" << endl;
							totalMiles += iter->second[index].miles;
						}else{
							cout << "Trip ends at " << root << endl;
							cout << "Total Distance Travelled: " << totalMiles << endl;
						}
						cout << "--------------------------------------------------------------------\n";
						return iter->second[index].city;
					}
				}
			}
			return "";
		}

		string BFS(string root){
			//DECLARE AND INITIALIZE
			map< string, string> backTrack; //backtrack cities
			string useful;
			flag = false;
			typedef map<string, vector <E> >::const_iterator MapIterator;

			cout << "Root: " << root << endl << endl;
			visited.push_back(root);

			for(int i = 0; i < 12; i++){
				for (MapIterator ite = myVector[i].begin(); ite != myVector[i].end(); ite++){
					int counter  = 0;

					if(root == ite->first){
						for(unsigned int k = 0; k < ite->second.size(); k++){//value of the map

							firstLevel.push_back(ite->second[k]);
						}

						cout << "First Level: \n";
						firstLevel = sort(firstLevel);
						print(firstLevel);

						for(unsigned int h = 0; h < firstLevel.size(); h++){
							visited.push_back(firstLevel[h].city);
						}

						for(unsigned int a = 0; a < firstLevel.size(); a++){
							typedef map<string, vector <E> >::const_iterator MapIt;
							for(int i = 0; i < 12; i++){
								for (MapIt it = myVector[i].begin(); it != myVector[i].end(); it++){
									flag = false;
									if(firstLevel[a].city == it->first){
										for(unsigned int u = 0; u < it->second.size(); u++){
											for(unsigned int w = 0; w < visited.size(); w++){
												if(it->second[u].city == visited[w]){

													flag = true;
													counter++;
												}
											}
											if(!flag){
												secondLevel.push_back(it->second[u]);

												visited.push_back(it->second[u].city);
											}
											flag = false;
										}
									}
								}
							}
						}
						cout << "\nSecond Level: \n";
						secondLevel = sort(secondLevel);
						print(secondLevel);


						for(unsigned int a = 0; a < secondLevel.size(); a++){
							typedef map<string, vector <E> >::const_iterator MapIt;
							for(int i = 0; i < 12; i++){
								for (MapIt it = myVector[i].begin(); it != myVector[i].end(); it++){
									flag = false;
									if(secondLevel[a].city == it->first){
										for(unsigned int u = 0; u < it->second.size(); u++){
											for(unsigned int w = 0; w < visited.size(); w++){
												if(it->second[u].city == visited[w]){

													flag = true;
													counter++;
												}
											}
											if(!flag){
												thirdLevel.push_back(it->second[u]);

												visited.push_back(it->second[u].city);
											}
											flag = false;
										}
									}
								}
							}
						}
						cout << "\nThird Level: \n";
						thirdLevel = sort(thirdLevel);
						print(thirdLevel);

						for(unsigned int a = 0; a < thirdLevel.size(); a++){
							typedef map<string, vector <E> >::const_iterator MapIt;
							for(int i = 0; i < 12; i++){
								for (MapIt it = myVector[i].begin(); it != myVector[i].end(); it++){
									flag = false;
									if(thirdLevel[a].city == it->first){
										for(unsigned int u = 0; u < it->second.size(); u++){
											for(unsigned int w = 0; w < visited.size(); w++){
												if(it->second[u].city == visited[w]){

													flag = true;
													counter++;
												}
											}
											if(!flag){
												fourthLevel.push_back(it->second[u]);

												visited.push_back(it->second[u].city);
											}
											flag = false;
										}
									}
								}
							}
						}
						cout << "\nFourth Level: \n";
						fourthLevel = sort(fourthLevel);
						print(fourthLevel);

						for(unsigned int a = 0; a < fourthLevel.size(); a++){
							typedef map<string, vector <E> >::const_iterator MapIt;
							for(int i = 0; i < 12; i++){
								for (MapIt it = myVector[i].begin(); it != myVector[i].end(); it++){
									flag = false;
									if(fourthLevel[a].city == it->first){
										for(unsigned int u = 0; u < it->second.size(); u++){
											for(unsigned int w = 0; w < visited.size(); w++){
												if(it->second[u].city == visited[w]){

													flag = true;
													counter++;
												}
											}
											if(!flag){
												fifthLevel.push_back(it->second[u]);

												visited.push_back(it->second[u].city);
											}
											flag = false;
										}
									}
								}
							}
						}
					cout << "\nFifth Level: \n";
					fifthLevel = sort(fifthLevel);
					print(fifthLevel);

					for(unsigned int a = 0; a < fifthLevel.size(); a++){
						typedef map<string, vector <E> >::const_iterator MapIt;
						for(int i = 0; i < 12; i++){
							for (MapIt it = myVector[i].begin(); it != myVector[i].end(); it++){
								flag = false;
								if(fifthLevel[a].city == it->first){
									for(unsigned int u = 0; u < it->second.size(); u++){
										for(unsigned int w = 0; w < visited.size(); w++){
											if(it->second[u].city == visited[w]){

												flag = true;
												counter++;
											}
										}
										if(!flag){
											sixthLevel.push_back(it->second[u]);

											visited.push_back(it->second[u].city);
										}
										flag = false;
									}
								}
							}
						}
					}
					cout << "\nSixth Level: \n";
					sixthLevel = sort(sixthLevel);
					print(sixthLevel);

					cout << "\nTotal Miles: " << bfsMiles << endl;
					}
				}
			}

			return "";
		}

		vector<E> sort(vector<E> toSort){
		int i, j, first;
		E temp;
			  int numLength = toSort.size( );
			  for (i= numLength - 1; i > 0; i--)
			 {
				   first = 0;                 // initialize to subscript of first element
				   for (j=1; j<=i; j++)   // locate smallest between positions 1 and i.
				  {
						 if (toSort[j].miles > toSort[first].miles)
						 first = j;
				  }
				 temp = toSort[first];   // Swap smallest found with element in position i.
				 toSort[first] = toSort[i];
				 toSort[i] = temp;
			 }
		return toSort;
		}

		void print(vector<E> payload){
			for(unsigned int k = 0; k < payload.size(); k++){
				cout<< payload[k].city;
				cout<< "[" << payload[k].miles << "]" << endl;
				bfsMiles = bfsMiles + payload[k].miles;
			}
		}

	};


#endif /* MYGRAPH_H_ */
