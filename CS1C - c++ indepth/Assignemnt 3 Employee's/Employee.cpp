/**************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #3:CS1C Corporation
 * CLASS	    :CS1C
 * SECTION	    :M/W 2:00 PM
 *************************************************************************/
#include "Employee.h"

//DEFAULT CONSTRUCTOR
Employee::Employee()
{
	//Initializes all variables to zero
	idNumber = 0;
	phoneNum = 0;
	age = 0;
	gender = '?';
	salary = 0.0;
}//END OF METHOD

/******************************************************************************
 * METHOD Employee - NON-DEFALUT Constructor
 * ____________________________________________________________________________
 * This method uses overloading to set in variables that have been entered
 * into the parameters and assigns them to the attributes
 *
 ******************************************************************************/
Employee::Employee(string eName, long eID, long long ePhoneNum, short eAge,
					char eGender, string eJob, float eSalary)
{
	name = eName;
	idNumber = eID;
	phoneNum = ePhoneNum;
	age = eAge;
	gender = eGender;
	jobTitle = eJob;
	salary = eSalary;
}//END OF METHOD

//DEFAULT DE-CONSTRUCTOR
Employee::~Employee()
{

}

/******************************************************************************
 * METHOD SetName
 * ____________________________________________________________________________
 * This method will set the name of the employee to the name in the private
 * data
 *
 * returns -> nothing
 ******************************************************************************/
void Employee::SetName(string eName)
{
	name = eName;
}//END OF METHOD

/******************************************************************************
 * METHOD SetId
 * ____________________________________________________________________________
 * This method will set the ID number for the employee to the ID number
 * in the private data.
 *
 * returns -> nothing
 ******************************************************************************/
void Employee::SetId(long eID)
{
	idNumber = eID;
}//END OF METHOD

/******************************************************************************
 * METHOD SetPhone
 * ____________________________________________________________________________
 * This method will set the phone number of the employee to the phone number
 * in the private data
 *
 * returns -> nothing
 ******************************************************************************/
void Employee::SetPhone(long long ePhoneNum)
{
	phoneNum = ePhoneNum;
}//END OF METHOD

/******************************************************************************
 * METHOD SetAge
 * ____________________________________________________________________________
 * This method will set the age of the employee to the age in the private
 * data
 *
 * returns -> nothing
 ******************************************************************************/
void Employee::SetAge(short eAge)
{
	age = eAge;
}//END OF METHOD

/******************************************************************************
 * METHOD SetGender
 * ____________________________________________________________________________
 * This method will set the gender of the employee to the gender in the private
 * data
 *
 * returns -> nothing
 ******************************************************************************/
void Employee::SetGender(char eGender)
{
	gender = eGender;
}//END OF METHOD

/******************************************************************************
 * METHOD SetJob
 * ____________________________________________________________________________
 * This method will set the Job Title of the employee to the Job Title in the
 * private data
 *
 * returns -> nothing
 ******************************************************************************/
void Employee::SetJob(string eJob)
{
	jobTitle = eJob;
}//END OF METHOD

/******************************************************************************
 * METHOD SetSalary
 * ____________________________________________________________________________
 * This method will set the Salary of the employee to the Salary in the private
 * data
 *
 * returns -> nothing
 ******************************************************************************/
void Employee::SetSalary(float eSalary)
{
	salary = eSalary;
}//END OF METHOD

/******************************************************************************
 * METHOD SetDate
 * ____________________________________________________________________________
 * This method will set the date that the employee was hired. It calls Date
 * class in order to correctly save the date entered
 *
 * returns -> nothing
 ******************************************************************************/
void Employee::SetDate(int eHireMonth, int eHireDay, int eHireYear)
{
	date.SetMonth(eHireMonth);
	date.SetDay(eHireDay);
	date.SetYear(eHireYear);
}//END OF METHOD

/******************************************************************************
 * METHOD GetName
 * ____________________________________________________________________________
 * This method retrieves the name of the employ that is saved in the private
 * data
 *
 * returns -> name of employee
 ******************************************************************************/
string Employee::GetName()const
{
	return name;
}//END OF METHOD

/******************************************************************************
 * METHOD DisplayInfo
 * ____________________________________________________________________________
 * This method outputs to the console a custom made table that has all the
 * Appropriate information that has been given from the user. Such as name,
 * ID number, phone number, age, gender, Job Title, salary, and hire date.
 *
 * returns -> output
 ******************************************************************************/
void Employee::DisplayInfo()const
{
	//OUTPUT - Uses output manipulators to set a chart looking table of all the
	//			information entered
	cout << left
		 << "| " << setw(15) << name << "| " << setw(14) << idNumber << "| "
		 << setw(12) << phoneNum << "| " << setw(4) << age << "| " << setw(7)
		 << gender << "| " << setw(16) << jobTitle << "| $" << setw(11)
		 << fixed << setprecision(2) << salary << "| " << date.OutputDate()
		 << endl;

	cout << left
		 << setfill('-') << setw(107) << '-' << endl
		 << setfill(' ');
}//END OF METHOD
