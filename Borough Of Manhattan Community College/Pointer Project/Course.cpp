#include "Course.h"
using namespace std;

Course::Course()
{
	CourseNo = " ";
	credits = 0;
	studentCount = 0;
}

void Course::setCourseNo(string tooCourse)
{
	CourseNo = tooCourse;
}

string Course::getCourseNo()
{
	return CourseNo;
}

void Course::setcredits(int tooCredit)
{
	if (tooCredit >= 0 && tooCredit <= 6) // change to between 0 and 6, default 3
	{
		credits = tooCredit;
	}

	else {
		cout << "Invalid; The credits was set to 3" << endl;
		credits = 3;
	}
}

int Course::getcredits()
{
	return credits;
}

void Course::setroster(Student* tooRoster)
{
	roster = tooRoster;
}


Student* Course::getroster()
{
	return roster;
}

void Course::setstudentCount(int tooStudent)
{
	if (tooStudent >= 0 && tooStudent <= 25) {
		studentCount = tooStudent;
	}
	else {
		cout << "Invalid; the number was set to 12.";
		studentCount = 12;
	}

	Student* roster = new Student[getstudentCount()]; //Allocates array based on size of studentcount
}

int Course::getstudentCount()
{
	return studentCount;
}
