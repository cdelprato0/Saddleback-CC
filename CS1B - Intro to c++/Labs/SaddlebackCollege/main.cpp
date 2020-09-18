/*
 * main.cpp
 *
 *  Created on: Apr 22, 2015
 *      Author: cdelprato0
 */


//#include "Person.h"
#include "Student.h"
#include "International.h"
#include "Continuing.h"
#include "Stack.h"
#include "NonResident.h"

int main()
{

	Person p1; //DEFAULT CONSTRUCTOR
	Person p2("Chaz", 11, 'M'); //NON-DEFAULT CONSTRUCTOR

	Student *s1 = new Student(); //DEFAULT CONSTRUCTOR
	Student *s2 = new Student("Diego", 5, 'M', 7); //NON-DEFAULT CONSTRUCTOR

	International *i1 = new International();
	International *i2 = new International("Sep", 21, 'M', 10, "Germany");

	Continuing *c1 = new Continuing();
	Continuing *c2 = new Continuing("Anahita", 26, 'F', 20, 250.00);

	NonResident *n1 = new NonResident();
	NonResident *n2 = new NonResident("Mariah", 19, 'F', 15, 5);

	Stack studentStack;

	studentStack.Push(s1);
	studentStack.Push(s2);
	studentStack.Push(i1);
	studentStack.Push(i2);
	studentStack.Push(c1);
	studentStack.Push(c2);
	studentStack.Push(n1);
	studentStack.Push(n2);

	cout << n2->Display() << endl; //Calling Nonresident::Display()

	studentStack.Display();	//Calling Student::Display

	studentStack.VDisplay();	//Calling Student::VDisplay

	while(studentStack.Size() != 0)
	{
		cout << (studentStack.Pop())->CalcTuition() << endl;
	}








//	International i1;
//	International i2("Sep", 21, 'M', 10, "Germany");
//
//	Continuing c1;
//	Continuing c2("Anahita", 26, 'F', 20, 250.00);
//
//	NonResident n1;
//	NonResident n2("Mariah", 19, 'F', 15, 5);
//
//	cout << "P1: " << p1.Display() << endl; //              0          ?
//	cout << "P2: " << p2.Display() << endl; //name         11          m
//
//	cout << endl << endl;
//	p1.InitializeMembers("Jason", 15, 'M');
//	cout << "P1: " << p1.Display() << endl;
//	cout << "P2: " << p2.Display() << endl;

//
//	cout << endl << endl;
//	cout << "S1: " << s1.Display() << endl;
//	cout << "S2: " << s2.Display() << endl;
//	//Example of Scope Resolution Operator <class name> :: <method>
//	//Allows access to Base Class Data Members & Methods that have been OVERRIDDEN
//	cout << endl << endl;
//	cout << "S1:Person " << s1.Person::Display() << endl;
//	cout << "S2:Person " << s2.Person::Display() << endl;
//
//	cout << endl << endl;
//	cout << "S1:Tuition " << s1.CalcTuition() << endl;
//	cout << "S2:Tuition " << s2.CalcTuition() << endl;

//	cout << "NAME                      AGE   GENDER   UNITS   TUITION   COUNTRY\n";
//	cout << "----------------------   ----- -------- ------- --------- ---------------\n";
//	cout << "I1: " << i1.Display() << endl;
//	cout << "I2: " << i2.Display() << endl << endl;
//
//	cout << "NAME                      AGE   GENDER   UNITS   TUITION   FINANCIAL AID\n";
//	cout << "----------------------   ----- -------- ------- --------- ---------------\n";
//	cout << "C1: " << c1.Display() << endl;
//	cout << "C2: " << c2.Display() << endl << endl;
//
//	cout << "NAME                      AGE   GENDER   UNITS   TUITION   MONTHS\n";
//	cout << "----------------------   ----- -------- ------- --------- ---------------\n";
//	cout << "N1: " << n1.Display() << endl;
//	cout << "N2: " << n2.Display() << endl << endl;

	return 0;
}

