/************************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #3:Queues Deques
 * CLASS	    :CS1D
 * SECTION	    :M/W 3:00 PM
 ************************************************************************************/
#include "ArrayVector.h"

//Default constructor
ArrayVector::ArrayVector() {
	capacity = 0;
	size = 0;
	strArray = NULL;

}

ArrayVector::~ArrayVector() {
	// TODO Auto-generated destructor stub
}

//Returns the size of the array
int ArrayVector::GetSize()
{
	return size;
}

//returns the capacity of the array
int ArrayVector::getCapacity(){
	return capacity;
}

//checks to see if the array is empty
bool ArrayVector::isEmpty()
{
	return (size == 0);
}

//deletes an element from the front of the array
void ArrayVector::erase(int index)
{
	for( int j = index; j < size - 1 ; j++ ){
		strArray[j] = strArray[j+1];
	}

	size--;

}

//inserts an element at the back of the array
void ArrayVector::insert(int index, string newString)
{
	if( size >= capacity ){
		reserve(max(1, 2* capacity));
		cout << "The Capacity of the Extendable Array has reached its MAX...\n"
				"Now the Extendable Array will have DOUBLED the Capacity!";
	}

	for( int j = size - 1; j >= index; j--){
		strArray[j+1] = strArray[j];
	}
	strArray[index] = newString;
	size++;
}

//Sets the capacity of the array and will be called if the capacity gets filled
void ArrayVector::reserve(int newCapacity)
{
	if( capacity >= newCapacity ){
		return;
	}

	string* newString = new string[newCapacity];

	for( int j = 0; j < size; j++ ){
		newString[j] = strArray[j];
	}

	if( strArray == NULL ){
		delete[] strArray;
	}

	strArray = newString;

	capacity = newCapacity;

}

//Outputs the content of the array
void ArrayVector::Display(){

	if(isEmpty()){
		cout << "The Extendable Array is EMPTY!";
	}else{
		cout << "DISPLAYING the Extendable Array...\n";
		for(int index = 0; index < size; index++){
			cout << strArray[index] << endl;
		}
	}
}
