/**************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #3:CS1C Corporation
 * CLASS	    :CS1C
 * SECTION	    :M/W 2:00 PM
 *************************************************************************/
#include "SWArchitect.h"

//DEFAULT CONSTRUCTOR
SWArchitect::SWArchitect()
{
	//Initializes all variables to zero
	departNum = 0;
	percentInc = 0.0;
	yearsExp = 0;
}//END OF METHOD

/******************************************************************************
 * METHOD SWArchitect - NON-DEFALUT Constructor
 * ____________________________________________________________________________
 * This method uses overloading to set in variables that have been entered
 * into the parameters and assigns them to the attributes. Calls the NON-Default
 * Constructor of employee.
 *
 ******************************************************************************/
SWArchitect::SWArchitect(string eName, long eID, long long ePhoneNum, short eAge,
					char eGender, string eJob, float eSalary, long swDepartNum,
					string swSuperName, float swPercentInc, int swYearExp)
				:Employee(eName, eID, ePhoneNum, eAge, eGender, eJob, eSalary)
{
	departNum = swDepartNum;
	superName = swSuperName;
	percentInc = swPercentInc;
	yearsExp = swYearExp;
}//END OF METHOD

//DEFAULT DE-CONSTRUCTOR
SWArchitect::~SWArchitect()
{

}//END OF METHOD

/******************************************************************************
 * METHOD SetDepartNum
 * ____________________________________________________________________________
 * This method will set the Architect's Department Number
 *
 * returns -> nothing
 ******************************************************************************/
void SWArchitect::SetDepartNum(long swDepartNum)
{
	departNum = swDepartNum;
}//END OF METHOD

/******************************************************************************
 * METHOD SetSuperName
 * ____________________________________________________________________________
 * This method will set the Architect's Supervisor's Name
 *
 * returns -> nothing
 ******************************************************************************/
void SWArchitect::SetSuperName(string swSuperName)
{
	superName = swSuperName;
}//END OF METHOD

/******************************************************************************
 * METHOD SetpercentInc
 * ____________________________________________________________________________
 * This method will set the Architect's Raise Percent Increase
 *
 * returns -> nothing
 ******************************************************************************/
void SWArchitect::SetpercentInc(float swPercentInc)
{
	percentInc = swPercentInc;
}//END OF METHOD

/******************************************************************************
 * METHOD SetYearsExp
 * ____________________________________________________________________________
 * This method will set the Architect's Years of Experience
 *
 * returns -> nothing
 ******************************************************************************/
void SWArchitect::SetYearsExp(int swYearExp)
{
	yearsExp = swYearExp;
}//END OF METHOD

/******************************************************************************
 * METHOD DisplaySWArchitect
 * ____________________________________________________________________________
 * This method will output into a chart format the Architect's name, department
 * number, the Supervisor;s name, the raise percent increase, and the years
 * of experience
 *
 * returns -> nothing
 ******************************************************************************/
void SWArchitect::DisplaySWArchitect()const
{
	//OUTPUT - Outputs the given information into a custom chart table
	cout << left
		 << "| " << setw(14) << GetName() << "| " << setw(12) << departNum
		 << "| " << setw(18) << superName << "| " << setw(8) << percentInc
		 << "| " << setw(16) << yearsExp
		 << endl;

	cout << left
		 << setfill('-') << setw(83) << '-' << endl
		 << setfill(' ');
}//END OF METHOD
