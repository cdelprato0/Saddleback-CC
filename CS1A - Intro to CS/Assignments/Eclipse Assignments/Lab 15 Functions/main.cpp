/*/************************************************************************
 * PROGRAMMED BY: BBC, Mamba, gunz, Crepe Hustler
 * CLASS		: CS1A
 * SECTION		: MW 9:30a
 * Lab #15		: Party Planner
 *************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
using namespace std;

void PrintHeader(string asName, char asType, int asNum);

void UserName(string& uName);
void UserAge(int& uAge);
void Chocolate(char& uChocStat);
string Candy(string uCandy, char uChocStat);
string Drink(string uDrink, int uAge);

int main()
{
	//This is the header that will display in the output

	PrintHeader("Party Planner", 'L', 15);

	/**********************************************************************
	 * This program will be able to output a persons preferred type of
	 * candy and there preference of drink depending on their age.
	 *********************************************************************/

	string name;			//INPUT - Name of guest
	int age;				//INPUT - Age of guest
	string candy;			//INPUT - Candy type
	string drink;			//INPUT - Drink type
	char chocStat;			//INPUT - Chocolate preference
	string snack;
	string beverage;


	// INPUTS - Prompts for name, age, and chocolate preference


	cout << left;

	UserName(name);

	UserAge(age);

	Chocolate(chocStat);


	//PROCESSING - Based on chocolate preference it prompts user for nut
	//		       preference and determines what to drink


	snack = Candy(candy, chocStat);

	beverage = Drink(drink, age);

	//OUTPUT - The name and what should be served to that person
	cout << endl;
	cout << "You should serve " << name << " " << snack << " and ";
	cout << beverage << ".";
	cout << right << endl << endl << endl;

	return 0;
}

void PrintHeader(string asName, char asType, int asNum)
{
	cout << left;
	cout << "********************************************************";
	cout << "\n* PROGRAMMED BY : BBC, Mamba, gunz, Crepe Hustler";
	cout << "\n* " << setw(14) << "Student ID" << ": 382108";
	cout << "\n* " << setw(14) << "Class" << ": CS1A --> Mon/Wed 9:30am";
	cout << "\n* ";
	if(toupper(asType) == 'L')
	{
		cout << "LAB #" << setw(9);
	}
	else
	{
		cout << "ASSIGNMENT #" << setw(2);
	}
	cout << asNum << ":" << asName;
	cout << "\n******************************************************\n\n";
	cout << right;
}

void UserName(string& uName)
{
	cout << setw(30) << "What is your friend\'s name?";
	getline(cin,uName);

}

void UserAge(int& uAge)
{
	cout << setw(30) << "How old is your friend?";
	cin >> uAge;
	cin.ignore(1000, '\n');
}

void Chocolate(char& uChocStat)
{
	cout << setw(30) << "Do they like chocolate (Y/N)?";
	cin.get(uChocStat);
	cin.ignore(1000, '\n');
}

string Candy(string uCandy, char uChocStat)
{
	char uNutStat;
	if(uChocStat=='Y'|| uChocStat == 'y')
		{
			cout << setw(30) << "Do they like nuts (Y/N)?";
			cin.get(uNutStat);
			cin.ignore(1000, '\n');

			if(uNutStat=='Y'|| uNutStat == 'y')
			{
				uCandy = "Peanut M & M\'s";
			}
			else
			{
				uCandy = "M & M\'s";
			}
		}
		else
		{
			uCandy = "Skittles";
		}
	return uCandy;
}

string Drink(string uDrink, int uAge)
{
	if(uAge >= 21)
		{
			uDrink = "beer";
		}
		else
		{
			uDrink = "soda";
		}
	return uDrink;
}
