/************************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #7:Double Hashing
 * CLASS	    :CS1D
 * SECTION	    :M/W 3:00 PM
 ************************************************************************************/
#include "Hashing.h"

Hashing::Hashing() {
	size = 0;

}

Hashing::~Hashing() {

}

//non-default constructor
Hashing::Hashing(Node newCity){
	size = 31;
	for(int index = 0; index < size; index++){
		cityHashTable[index].setKey(newCity.getKey());
		cityHashTable[index].setValue(newCity.getValue());
	}
}

//calculates the first hash function
int Hashing::HashFunctionOne(Node newCity){
	int hash = 0;

	hash = ( newCity.getKey() % 31 );

	return hash;
}

//calculates the second hash function
int Hashing::HashFunctionTwo(Node newCity){
	int hash = 0;

	hash = ( 17 - ( newCity.getKey() % 17 ) );

	return hash;
}

//adds to the hash table
void Hashing::AddToHash(Node newCity){
	int hash;
	int hash2;
	bool exists = false;

	//checks to see if the key value is already in the hash table and if it is then
	//the value of the key will be changed
	for(int index = 0; index < size; index++){
		if(cityHashTable[index].getKey() == newCity.getKey()){
			cityHashTable[index].setValue(newCity.getValue());
			exists = true;
		}
	}

	//if the key does not exisit in the hash table
	if(!exists){
		//gets the first hash value
		hash = HashFunctionOne(newCity);

		//if the first hash value is over 30 then it will add the hash to the
		//Beginning of the table
		if( hash > 30 ){

			hash = (hash - 1) - 30;
		}

		//Checks to see if the space is empty or has been deleted
		if( cityHashTable[hash].getValue() == "{}" ){
			cityHashTable[hash].setKey(newCity.getKey());
			cityHashTable[hash].setValue(newCity.getValue());
		}
		else if(cityHashTable[hash].getValue() == "{Deleted}"){
			cityHashTable[hash].setKey(newCity.getKey());
			cityHashTable[hash].setValue(newCity.getValue());
		}
		else{
			//Calls the second hash function and saves the value
			hash2 = hash + HashFunctionTwo(newCity);

			//checks to see if the second has is over 30
			if( hash2 > 30 ){

				//if its over, it will check to see if the hash spot is taken
				if(cityHashTable[(hash2 - 1) - 30].getValue() != "{}"){
					//if its taken it will rehash to a different spot
					hash2 = hash + 2*(HashFunctionTwo(newCity));

					cityHashTable[hash2].setKey(newCity.getKey());
					cityHashTable[hash2].setValue(newCity.getValue());
				}
				//if it has an empty spot
				hash2 = (hash2 - 1) - 30;
			}

			//Checks if the second has fits in an empty spot or deleted spot
			if( cityHashTable[hash2].getValue() == "{}"){
				cityHashTable[hash2].setKey(newCity.getKey());
				cityHashTable[hash2].setValue(newCity.getValue());
			}
			else if(cityHashTable[hash2].getValue() == "{Deleted}"){
				cityHashTable[hash2].setKey(newCity.getKey());
				cityHashTable[hash2].setValue(newCity.getValue());
			}
			else if(cityHashTable[hash2].getValue() != "{}" &&
					cityHashTable[hash2].getValue() != "{Deleted}"){
				//if the hash does not fit then it will rehash
				hash2 = hash + 2*(HashFunctionTwo(newCity));

				//if it doesnt fit again it will rehash and save to the table
				if(cityHashTable[hash2].getValue() != "{}" &&
				   cityHashTable[hash2].getValue() != "{Deleted}"){

					hash2 = hash + 3*(HashFunctionTwo(newCity));

					if(hash2 > 30){
						hash2 = (hash2 - 1) - 30;
					}
					cityHashTable[hash2].setKey(newCity.getKey());
					cityHashTable[hash2].setValue(newCity.getValue());
				}
				else{
					cityHashTable[hash2].setKey(newCity.getKey());
					cityHashTable[hash2].setValue(newCity.getValue());
				}
			}
		}
	}
}

//deletes a memeber from the hash table
void Hashing::DeleteFromHash(int key){

	for(int index = 0; index < size; index++){
		if( cityHashTable[index].getKey() == key ){
			cityHashTable[index].setKey(0);
			cityHashTable[index].setValue("{Deleted}");
		}
	}
}

//prints the hash table
void Hashing::Print()const{

	for(int index = 0; index < size; index++){
		cout << "At spot #"<< index << ": " << cityHashTable[index].getKey() << " "
			 << cityHashTable[index].getValue() << endl;
	}
}
