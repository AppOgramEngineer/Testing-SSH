//******************************************************************************************************
//
//          File:                   Calculate_GPA.cpp
//
//          Student:                 Marion Echols
//
//          Assignment:              Assignment 12
//
//          Course Name:             Programming I
//
//          Course Number:           COCS 1550  - 11
//
//          Due:                     April 27, 2017
//
// 
//          This program gets the program gets the GPA of a student buy passing two arrays 
//          of values from user input to functions.
//******************************************************************************************************

#include <iostream>
#include <iomanip>
using namespace std;

//******************************************************************************************************

void get_Data(double array_Credit_hours[], int creditHours,                // function prototype
	double array_Grades[], int grades);
double compute_GPA(double array1_Credit_hours[], int creditHours1,         // function prototype
	double array1_Grades[], int grade1);
void display_GPA(double credit_Hours[], int  CREDIT_HOURS, double grades[],// function prototype
	int GRADE);

//******************************************************************************************************

int main()
{
	const int GRADE = 4;
	const int CREDIT_HOURS = 4;
	double grades[GRADE];
	double credit_Hours[CREDIT_HOURS];

	get_Data(credit_Hours, CREDIT_HOURS, grades, GRADE);   // function gets user array of input
	compute_GPA(credit_Hours, CREDIT_HOURS, grades, GRADE);// function computes both arrays 
	display_GPA(credit_Hours, CREDIT_HOURS, grades, GRADE);// function displays data results
}

//******************************************************************************************************

void get_Data(double array_Credit_hours[], int creditHours, // function gets user input into array
	double array_Grades[], int grade)
{
		for (int index = 0; index < creditHours && index < grade; index++) // loops through input
		{

			cout << "Please enter the credit hours and the grade of Course #" <<
				index + 1 << ":" << endl;
			cin >> array_Credit_hours[index] >> array_Grades[index];
			if (array_Credit_hours[index] <= 0)             // test condition for negative numbers
			{
				cout << "Please use Positive Numbers only for credit hours." <<
					endl;
				cin >> array_Credit_hours[index];
			}
			if (array_Grades[index] <= 0)
			{
				cout << "Please use positive numbers only for grades." << endl;
				cin >> array_Grades[index];
			}
		}
}

//******************************************************************************************************

double compute_GPA(double array1_Credit_hours[], int creditHours1, // function computes GPA
	double array1_Grades[], int grade1)
{
	double credit_X_grade = 0,
		grades_P_grades = 0,
		gpa;

	for (int index = 0; index < creditHours1 && index < grade1; index++) // loops through array
	{
		credit_X_grade += array1_Credit_hours[index] * array1_Grades[index];
		grades_P_grades += array1_Credit_hours[index];
	}
	    gpa = credit_X_grade / grades_P_grades;
		return gpa;
}

//******************************************************************************************************

void display_GPA(double credit_Hours[], int  CREDIT_HOURS, double grades[], // function displays GPA
	int GRADE)
{
	double gpa;
	cout << setprecision(2) << showpoint << fixed << endl;
	gpa = compute_GPA(credit_Hours, CREDIT_HOURS, grades, GRADE);
    cout << "Your GPA is: " << gpa << endl;
}
	
//******************************************************************************************************
//Please enter the credit hours and the grade of Course #1:
//1 4
//Please enter the credit hours and the grade of Course #2:
//3 3.75
//Please enter the credit hours and the grade of Course #3:
//1.5 2.5
//Please enter the credit hours and the grade of Course #4:
//2.5 3.5
//
//Your GPA is : 3.47
