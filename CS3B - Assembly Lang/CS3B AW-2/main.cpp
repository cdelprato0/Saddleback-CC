/************************************************************************************
 * AUTHOR	      :Chaz Del Prato
 * STUDENT ID     :382108
 * Assignment #2  :AW-2
 * CLASS	      :CS3B
 * SECTION	      :T/TH 3:30
 ************************************************************************************/
#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;

int main(){

	//Holds the array of string for each set of 32-bit hex numbers
	string strArray[] = {"44444444", "00FF00FF", "12345678",
			"ABCD0000", "00000000", "11111111",
			"99990ABC", "ABCDEF00", "ABB10000",
			"FFFFFFFF"
	};

	//Main for loop that will run each case of the stringArray and output the decimal
	//value of the hexadecimal number
	for( int i = 0; i < 10; i++ ){

		string signedHex = strArray[i];	//Loads the current hex number into a string
		long bitCount = 0;				//Used to go through each hex number
		long sum = 0;					//Accumulates a running sum for the hex number
		int carry;						//Holds the value of the carry
		int count = 0;					//Another counter
		string hexToBinary;				//Used to hold the binary value after hex
		char onesComp[32];				//Used to get Ones complement
		char twosComp[32];				//Used for twos complement

		// Checks to see if the input string is a valid 32-bit hex integer, and will
		//output an error if it is not
		if(signedHex.size() != 8){
			cout << "ERROR, not a 32-bit signed hexadecimal integer!" << endl;
			return -1;
		}

		char hexTemp = signedHex[0]; //Temp variable to determine what the first hex value is

		//Will determine if the hexadecimal value is representing a positive or negative number
		if( hexTemp == '8' || hexTemp == '9' || ( hexTemp >= 'A' && hexTemp <= 'F' ) ){

			bitCount = 0;

			//Will convert the hex value to binary
			for( unsigned int i = 0; i < signedHex.size(); i++ ){

				char hexSignedNum = signedHex[bitCount]; //Used to convert hex to dec

				//Will go through each case and convert hex to decimal
				switch(hexSignedNum){
					case '0' : hexToBinary.append("0000");
					break;
					case '1' : hexToBinary.append("0001");
					break;
					case '2' : hexToBinary.append("0010");
					break;
					case '3' : hexToBinary.append("0011");
					break;
					case '4' : hexToBinary.append("0100");
					break;
					case '5' : hexToBinary.append("0101");
					break;
					case '6' : hexToBinary.append("0110");
					break;
					case '7' : hexToBinary.append("0111");
					break;
					case '8' : hexToBinary.append("1000");
					break;
					case '9' : hexToBinary.append("1001");
					break;
					case 'A' : hexToBinary.append("1010");
					break;
					case 'B' : hexToBinary.append("1011");
					break;
					case 'C' : hexToBinary.append("1100");
					break;
					case 'D' : hexToBinary.append("1101");
					break;
					case 'E' : hexToBinary.append("1110");
					break;
					case 'F' : hexToBinary.append("1111");
					break;
				}

				count = 0;

				//Will take in the input string and convert the binary word to its ones complement
				for( unsigned int i = 0; i < 32; i++ ){

					//Temp variables used in order to convert the ASCII char given from
					//signedBinary[bitCount], into an the appropriate integer in the string
					char temp = hexToBinary[count];
					int tempInt = temp - '0';

					//Determines when to reverse the binary digits
					if(tempInt == 1){
						onesComp[i] = '0';
					}else if(tempInt == 0){
						onesComp[i] = '1';
					}
					count++;
				}
				//Determines the twos complement of the ones complement character string
				carry = 1;
				for( int i = 31; i >= 0; i-- ){

					if( onesComp[i] == '1' && carry == 1){

						twosComp[i] = '0';
					}else if( onesComp[i] == '0' && carry == 1){

						twosComp[i] = '1';
						carry = 0;
					}else{

						twosComp[i] = onesComp[i];
					}
				}

				bitCount++;
			}
			int exponent = 0; //Initializes the exponent to zero
			bitCount = 31;   //Initializes the bitCount to the Least Significant Bit
			sum = 0;		 //Initializes the sum to zero

			//Will run through the entire string input
			while( exponent != 32 ){

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
			cout << signedHex + "h" + " = -" << sum << endl;

		}
		else{ //for a positive hex value

			//Will use the ASCII table to determine what the value of the hex number is
			for ( unsigned int i = 0;  i < signedHex.size(); i++ ) {

				char hexNum = signedHex[bitCount];

				//If the hex number is between 0-9
				if ( hexNum >= 48 && hexNum <= 57 ) {

				  sum += ( ( (long)(hexNum) ) - 48 ) * pow( 16, 8 - i - 1 );
				}
				//If the hex number is A-F
				else if ((hexNum >= 65 && hexNum <= 70))  {

				  sum += ( ( (long)(hexNum) ) - 55 ) * pow( 16, 8 - i - 1 );
				}
				//If the hex number is a-f
				else if (hexNum >= 97 && hexNum <= 102) {

				  sum += ( ( (long)(hexNum) ) - 87 ) * pow( 16, 8 - i - 1 );
				}

				bitCount++;
			}

			//console output
			cout << signedHex << "h" << " = " << sum << endl;
		}
	}//End Main FOR
	//System pause
	system("PAUSE");
	return 0;
}//End Main
