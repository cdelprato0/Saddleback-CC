/**************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #3:CS1C Corporation
 * CLASS	    :CS1C
 * SECTION	    :M/W 2:00 PM
 *************************************************************************/
#include "Programmer.h"

//DEFAULT CONSTRUCTOR
Programmer::Programmer()
{
	//Initializes all variables to zero
	departNum = 0;
	percentInc = 0.0;
}//END OF METHOD

/******************************************************************************
 * METHOD Programmer - NON-DEFALUT Constructor
 * ____________________________________________________________________________
 * This method uses overloading to set in variables that have been entered
 * into the parameters and assigns them to the attributes. Calls the NON-Default
 * Constructor of employee.
 *
 ******************************************************************************/
Programmer::Programmer(string eName, long eID, long long ePhoneNum, short eAge,
					char eGender, string eJob, float eSalary, long proDepartNum,
					string proSuperName, float proPercentInc, string proCPlusPlus,
					string proJava)
				:Employee(eName, eID, ePhoneNum, eAge, eGender, eJob, eSalary)
{
	departNum = proDepartNum;
	superName = proSuperName;
	percentInc = proPercentInc;
	cPlusPlus = proCPlusPlus;
	java = proJava;
}//END OF METHOD

//DEFAULT DE-CONSTRUCTOR
Programmer::~Programmer()
{

}//END OF METHOD

/******************************************************************************
 * METHOD SetDepartNum
 * ____________________________________________________________________________
 * This method will set the Programmer's Department Number
 *
 * returns -> nothing
 ******************************************************************************/
void Programmer::SetDepartNum(long proDepartNum)
{
	departNum = proDepartNum;
}//END OF METHOD

/******************************************************************************
 * METHOD SetSuperName
 * ____________________________________________________________________________
 * This method will set the Programmer's Supervisor's Name
 *
 * returns -> nothing
 ******************************************************************************/
void Programmer::SetSuperName(string proSuperName)
{
	superName = proSuperName;
}//END OF METHOD

/******************************************************************************
 * METHOD SetPercentInc
 * ____________________________________________________________________________
 * This method will set the Programmer's Percent Raise Increase
 *
 * returns -> nothing
 ******************************************************************************/
void Programmer::SetPercentInc(float proPercentInc)
{
	percentInc = proPercentInc;
}//END OF METHOD

/******************************************************************************
 * METHOD proCPlusPlus
 * ____________________________________________________________________________
 * This method will set the Programmer's C++ Knowledge
 *
 * returns -> nothing
 ******************************************************************************/
void Programmer::SetcPlusPlus(string proCPlusPlus)
{
	cPlusPlus = proCPlusPlus;
}//END OF METHOD

/******************************************************************************
 * METHOD proJava
 * ____________________________________________________________________________
 * This method will set the Programmer's Java Knowledge
 *
 * returns -> nothing
 ******************************************************************************/
void Programmer::SetJava(string proJava)
{
	java = proJava;
}//END OF METHOD

/******************************************************************************
 * METHOD DisplayProgrammer
 * ____________________________________________________________________________
 * This method will display to the console the programmer's name, department
 * number, their supervisor's name, their percent raise increase, if they know
 * c++ and if they know Java
 *
 * returns -> output
 ******************************************************************************/
void Programmer::DisplayProgrammer()const
{
	//OUTPUT - Outputs the information given into a chart format
	cout << left
		 << "| " << setw(13) << GetName() << "| " << setw(11) << departNum
		 << "| " << setw(18) << superName << "| " << setw(8) << percentInc
		 << "| " << setw(14) << cPlusPlus << "| " << setw(11) << java
		 << endl;

	cout << left
		 << setfill('-') << setw(92) << '-' << endl
		 << setfill(' ');
}//END OF METHOD
