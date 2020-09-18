/*******************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #7:CS1C Overloading
 * CLASS	    :CS1C
 * SECTION	    :M/W 2:00 PM
 *******************************************************************************/
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

string Employee::GetName()const
{
	return name;
}//END OF METHOD

long Employee::GetId()const
{
	return idNumber;
}//END OF METHOD

long long Employee::GetPhoneNumber()const
{
	return phoneNum;
}//END OF METHOD

short Employee::GetAge()const
{
	return age;
}//END OF METHOD

string Employee::GetJobTitle()const
{
	return jobTitle;
}//END OF METHOD

float Employee::GetSalary()const
{
	return salary;
}//END OF METHOD

char Employee::GetGender()const
{
	return gender;
}//END OF METHOD

void Employee::GetDate(int& month, int& day, int& year)const
{
	month = date.GetMonth();
	day = date.GetDay();
	year = date.GetYear();

}//END OF METHOD

void Employee::AddAge(int addedAge)
{
	cout << "The number of years you are adding to " << name <<  "\'s is: "
		 << addedAge << endl << endl;

	age += addedAge;
}//END OF METHOD

bool Employee::operator == (Employee& emp)
{
	bool equal = false;

	if( phoneNum == emp.GetPhoneNumber())
	{
		equal = true;
	}

	return equal;
}//END OF METHOD

Employee Employee::operator + (int newAge)
{
	Employee overload;

	overload.SetAge(newAge + age);

	return overload;
}//END OF METHOD

std::ostream& operator << (std::ostream& output, Employee& emp)
{
	int day, month, year;

	emp.GetDate(month, day ,year);

	output << "Name:         " << emp.GetName()        << endl
		   << "Id Number:    " << emp.GetId()          << endl
		   << "Phone Number: " << emp.GetPhoneNumber() << endl
		   << "Age:          " << emp.GetAge()         << endl
		   << "Job Title:    " << emp.GetJobTitle()    << endl
		   << "Salary:       " << emp.GetSalary()      << endl
		   << "Gender:       " << emp.GetGender()      << endl
		   << "Hired:        " << month << '/' << day << '/' << year
		   << endl;

	return output;
}//END OF METHOD

