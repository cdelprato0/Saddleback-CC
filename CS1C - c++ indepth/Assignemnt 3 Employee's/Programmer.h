/**************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #3:CS1C Corporation
 * CLASS	    :CS1C
 * SECTION	    :M/W 2:00 PM
 *************************************************************************/
#ifndef PROGRAMMER_H_
#define PROGRAMMER_H_

#include "Employee.h"

class Programmer: public Employee
{
public:

	/***************************
	 * CONSTRUCTOR * DESTRUCTOR*
	 ***************************/
	Programmer(); //DEFAULT CONSTRUCTOR
	Programmer(string eName, long eID, long long ePhoneNum, short eAge,
			char eGender, string eJob, float eSalary, long proDepartNum,
			string proSuperName, float proPercentInc, string proCPlusPlus,
			string proJava);  //NON-DEFAULT CONSTRUCTOR
	virtual ~Programmer();  //DEFAULT DE-CONSTRUCTOR

	/************
	 * MUTATORS *
	 ************/
	void SetDepartNum(long proDepartNum);   //Sets the Programmer's Department
	void SetSuperName(string proSuperName); //Sets the Supervisor's name
	void SetPercentInc(float proPercentInc);//Sets the raise percent increase
	void SetcPlusPlus(string proCPlusPlus); //Sets the C++ knowledge
	void SetJava(string proJava); 			//Sets the Java Knowledge

	/*************
	 * ACCESSORS *
	 *************/
	void DisplayProgrammer()const;  //outputs the saved programmer information

private:

	long departNum;
	string superName;
	float percentInc;
	string cPlusPlus;
	string java;
};

#endif /* PROGRAMMER_H_ */
