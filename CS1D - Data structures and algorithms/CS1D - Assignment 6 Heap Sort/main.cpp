/************************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #6:Heap Sort
 * CLASS	    :CS1D
 * SECTION	    :M/W 3:00 PM
 ************************************************************************************/

/************************************************************************************
 * Assignment #6 - Heap Sort
 * -------------------------
 *	This program will be able to to take in data that has the a key integer and a
 *	string value and will be able to perform a heap sort. The keys and values will
 *	be stored into a data members of a struct, fitted into an array for each team
 *	The program will output all the items that have been added and will output so.
 *	Then it will perform the HEap sort which will sort the array so the first index
 *	of the array is the lowest. After it performs the Heap sort it will then output
 *	the sorted array.
 ************************************************************************************/
#include <iostream>
#include <string>
using namespace std;

//Uses a struct to hold the key and the value
struct Teams{
	string value;
	int key;
};

//Declared methods above main so the whole program can see
void heapify(Teams teamArray[], int size, int index);
void heapSort(Teams teamArray[], int size);
void printArray(Teams teamArray[], int size);

int main(){

//OUTPUT - Will output the header and a description of the output
cout << "**************************************************************************\n"
		"* PROGRAMMED BY : Chaz Del Prato                                         *\n"
		"* ASSIGNMENT #6 : Heap Sort                                              *\n"
		"* CLASS         : CS1D                                                   *\n"
		"* SECTION       : MW 3:00p                                               *\n"
		"--------------------------------------------------------------------------\n"
		"* Description   :                                                        *\n"
		"*  This program will be able to output an array that has performed a Heap*\n"
		"*  sort. The Program will take in a key integer and a string value and   *\n"
		"*  will output the items that are being added. The program will perform  *\n"
		"*  the heap sort and the output will run through the steps the heap sort *\n"
		"*  takes in order to complete the sort. The sort will find the highest   *\n"
		"*  key and will output what it is. Then it will output the lower value it*\n"
		"*  is going to swap with. After the keys swap, the program will remove   *\n"
		"*  the highest key and store it in the last index of the array. Then the *\n"
		"*  program will output what low value is saved at the root and will      *\n"
		"*  repeat until there is the lowest key left. The program will output the*\n"
		"*  sorted array at the end of the program.                               *\n"
		"**************************************************************************\n\n";

	//Creates an array to the struct of Teams
	Teams teamArray[10];

	//Intilializes all the contents to the array
	teamArray[0].value = "Rams";
	teamArray[0].key = 33;
	teamArray[1].value = "Vikings";
	teamArray[1].key = 22;
	teamArray[2].value = "Lions";
	teamArray[2].key = 88;
	teamArray[3].value = "Dolphins";
	teamArray[3].key = 44;
	teamArray[4].value = "Pariots";
	teamArray[4].key = 123;
	teamArray[5].value = "Bengals";
	teamArray[5].key = 44;
	teamArray[6].value = "Packers";
	teamArray[6].key = 69;
	teamArray[7].value = "Broncos";
	teamArray[7].key = 24;
	teamArray[8].value = "Bears";
	teamArray[8].key = 13;
	teamArray[9].value = "Chargers";
	teamArray[9].key = 49;

	//Keeps count of the size
    int size = sizeof(teamArray)/sizeof(teamArray[0]);

    //Prints out the array before it is sorted
    cout << "Adding to the Heap\n"
    	 << "------------------\n";
    printArray(teamArray, size);

    //Performs the Heap sort
    heapSort(teamArray, size);

    //Prints out the results of the Heap sort
    cout << "\nThe RESULT of the HEAP SORT is:\n"
    		"-------------------------------\n";
    printArray(teamArray, size);

	return 0;
}

//This function is used to create the heap and determine if the left child is larger
//than the root or if the right child is the largest so far and if the largest is
//not the root
void heapify(Teams teamArray[], int size, int index)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;


    //checks to see if the left is larger than the root
    if (left < size && teamArray[left].key > teamArray[largest].key){

        largest = left;
    }

    //checks to see if the right child is the largest so far
    if (right < size && teamArray[right].key > teamArray[largest].key){

        largest = right;
    }

    //checks to see if the largest is not root
    if (largest != index)
    {
    	//Swaps
        swap(teamArray[index], teamArray[largest]);

        // Recursively heapify the affected sub-tree
        heapify(teamArray, size, largest);
    }
}

//This function performs the Heap sort which will take in a key value and determine
//if it the largest and if so it will be replaced with a lower key and the larger key
//will be deleted
void heapSort(Teams teamArray[], int size)
{
    //Rearranges the array into a heap
    for(int index = (size / 2 - 1); index >= 0; index--){

        heapify(teamArray, size, index);

    }

    //Outputs the largest key we have
    cout << "We are at the MAX --> ";
    cout << teamArray[0].key << " " << teamArray[0].value << endl;

    // One by one extract an element from heap
    for (int index = (size - 1); index >= 0; index--)
    {

    	if(index != 0){
			// Move current root to end
			swap(teamArray[0], teamArray[index]);

			cout << "\nWe are SWAPPING --> ";

			cout << teamArray[0].key << " " << teamArray[0].value << " and --> ";
			cout << teamArray[index].key << " " << teamArray[index].value << endl;

			cout << "\nThe NEW root is --> ";
			cout << teamArray[0].key << " " << teamArray[0].value << endl;

			// call max heapify on the reduced heap
			heapify(teamArray, index, 0);

			cout << "\nWe are DELETING --> ";
			cout << teamArray[index].key << " " << teamArray[index].value << endl;
			cout << "\n\nWe are at the MAX VALUE --> ";
			cout << teamArray[0].key << " " << teamArray[0].value << endl;
    	}
    }
}

//Prints out the array
void printArray(Teams teamArray[], int size)
{
    for(int index = 0; index < size; ++index){

        cout << teamArray[index].key << " " << teamArray[index].value << endl;
    }
    cout << endl;
}
