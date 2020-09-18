/**************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #3:CS1C Corporation
 * CLASS	    :CS1C
 * SECTION	    :M/W 2:00 PM
 *************************************************************************/
#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include "Date.h"
#include <iomanip>

class Employee
{
public:

	/***************************
	 * CONSTRUCTOR * DESTRUCTOR*
	 ***************************/
	Employee(); //DEFAULT CONSTRUCTOR
	Employee(string eName, long eID, long long ePhoneNum, short eAge, char eGender,
			string eJob, float eSalary); //NON-DEFAULT CONSTRUCTOR
	virtual ~Employee(); //DEFAULT DE-CONSTRUCTOR

	/************
	 * MUTATORS *
	 ************/
	void SetName(string eName);  //Sets the Name of the Employee
	void SetId(long eID);  //Sets the ID Number of the Employee
	void SetPhone(long long ePhoneNum);  //Sets the Phone Number of the Employee
	void SetAge(short eAge);  //Sets the Age of the Employee
	void SetGender(char eGender);  //Sets the Gender of the Employee
	void SetJob(string eJob);  //Sets the Job Title of the Employee
	void SetSalary(float eSalary);  //Sets the Salary of the Employee
	void SetDate(int eHireMonth, int eHireDay, int eHireYear);  //Sets the Date
																//of the Employee

	/*************
	 * ACCESSORS *
	 *************/
	string GetName()const;  //Gets the name of the employee
	virtual void DisplayInfo()const; //Outputs all the given information

private:

	string name;
	long idNumber;
	long long phoneNum;
	short age;
	char gender;
	string jobTitle;
	float salary;
	Date date;  //Used to set and call data for the hire date

};

#endif /* EMPLOYEE_H_ */
