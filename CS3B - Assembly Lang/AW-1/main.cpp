/************************************************************************************
 * AUTHOR	      :Chaz Del Prato
 * STUDENT ID     :382108
 * Assignment #1  :AW-1
 * CLASS	      :CS3B
 * SECTION	      :T/TH 3:30
 ************************************************************************************/
#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;

int main(){

	//Holds the array of string for each set of 16-bit binary words
	string strArry[] = {"1010101111001010", "0011111111000011", "1111111111111111",
			"0000000000000000", "1000000000000000", "1000000000000001",
			"0000000000000001", "0000111100001111", "0101010101010101",
			"1010101010101010"
	};

	//Will run through each of the elements in the string array
	for( int i = 0; i < 10 ; i++ ){

		string signedBinary = strArry[i]; //Will take the current binary word
		long exponent;	//Will keep count of the exponents needed
		long sum;		//Running accumulation
		long bitCount;  //Will be used to separate the string input
		int carry = 1;	//Keep track of the carry for twos complement
		char onesComp[16];	//Used to get Ones complement
		char twosComp[16];	//Used for twos complement

		// Checks to see if the input string is a 16-bit binary word, will return an error
		//if not
		if( signedBinary.size() != 16){
			cout << "ERROR, not a 16-bit word!" << endl;
			return -1;
		}

		//If the binary number is representing a negative decimal number
		if( ( signedBinary.at(0) - '0' ) == 1){

			bitCount = 0;		//Sets the bitCount to zero

			//Will take in the input string and convert the binary word to its ones complement
			for( unsigned int i = 0; i < 16; i++ ){

				//Temp variables used in order to convert the ASCII char given from
				//signedBinary[bitCount], into an the appropriate integer in the string
				char temp = signedBinary[bitCount];
				int tempInt = temp - '0';

				//Determines when to reverse the binary digits
				if(tempInt == 1){
					onesComp[i] = '0';
				}else if(tempInt == 0){
					onesComp[i] = '1';
				}

				bitCount++;	//Increments
			}

			//Determines the twos complement of the ones complement character string
			for( int i = 15; i >= 0; i-- ){

				if( onesComp[i] == '1' && carry == 1){
					twosComp[i] = '0';
				}else if( onesComp[i] == '0' && carry == 1){
					twosComp[i] = '1';
					carry = 0;
				}else{
					twosComp[i] = onesComp[i];
				}

			}

			exponent = 0; 	//Initializes the exponent to zero
			bitCount = 15;  //Initializes the bitCount to the Least Significant Bit
			sum = 0;		//Initializes the summ to zero

			//Will run through the entire string input
			while( exponent != 16 ){

				//Temp variables used in order to convert the ASCII char given from
				//signedBinary[bitCount], into an the appropriate integer in the string
				char temp = twosComp[bitCount];
				int tempInt = temp - '0';

				//Adds the sum to the sum and multiplies the 0 or 1 times the 2 to the
				//power of the exponent
				sum += ( tempInt * pow( 2, exponent ) );

				exponent++;	//Increments the exponent
				bitCount--;	//Decrements the bitCount
			}

			cout << signedBinary + "b" + " = -" << sum << endl;

		}else{ // If the binary number is representing a positive decimal value

			exponent = 0; 	//Initializes the exponent to zero
			bitCount = 15;  //Initializes the bitCount to the Least Significant Bit
			sum = 0;		//Initializes the summ to zero

			//Will run through the entire string input
			while( exponent != 16 ){

				//Temp variables used in order to convert the ASCII char given from
				//signedBinary[bitCount], into an the appropriate integer in the string
				char temp = signedBinary[bitCount];
				int tempInt = temp - '0';

				//Adds the sum to the sum and multiplies the 0 or 1 times the 2 to the
				//power of the exponent
				sum += ( tempInt * pow( 2, exponent ) );

				exponent++;	//Increments the exponent
				bitCount--;	//Decrements the bitCount
			}
			cout << signedBinary + "b" + " = " << sum << endl;
		}
	}//End Main FOR
	//System pause
	system("PAUSE");
	return 0;
}//End Main
