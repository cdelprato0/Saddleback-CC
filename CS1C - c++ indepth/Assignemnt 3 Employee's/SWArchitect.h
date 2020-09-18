/**************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #3:CS1C Corporation
 * CLASS	    :CS1C
 * SECTION	    :M/W 2:00 PM
 *************************************************************************/
#ifndef SWARCHITECT_H_
#define SWARCHITECT_H_

#include "Employee.h"

class SWArchitect: public Employee
{
public:

	/***************************
	 * CONSTRUCTOR * DESTRUCTOR*
	 ***************************/
	SWArchitect();  //DEFAULT CONSTRUCTOR
	//NON-DEFAULT CONSTRUCTOR
	SWArchitect(string eName, long eID, long long ePhoneNum, short eAge,
			char eGender, string eJob, float eSalary, long swDepartNum,
			string swSuperName, float swPercentInc, int swYearExp);
	virtual ~SWArchitect();//DEFAULT DE-CONSTRUCTOR

	/************
	 * MUTATORS *
	 ************/
	void SetDepartNum(long swDepartNum);    //Sets the Architect's Department #
	void SetSuperName(string swSuperName);  //Sets the Supervisor's Name
	void SetpercentInc(float swPercentInc); //Sets the Raise Percent Increase
	void SetYearsExp(int swYearExp); 		//Sets the Years of Experience

	/*************
	 * ACCESSORS *
	 *************/
	void DisplaySWArchitect()const;  //Outputs all the saved information

private:

	long departNum;
	string superName;
	float percentInc;
	int yearsExp;

};

#endif /* SWARCHITECT_H_ */
