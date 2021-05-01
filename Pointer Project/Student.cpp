#include "Student.h"
#include <iostream>
using namespace std;

Student::Student()
{
	name = " ";
	GPA = 0;
	credits = 0;
}
void Student::setname(string tooName)
{
	name = tooName;
}

void Student::setGPA(double tooGPA)
{

	if (tooGPA >= 0 && tooGPA <= 4)
	{
		GPA = tooGPA;
	}

	else
	{
		cout << "Invalid; GPA was set to 0." << endl;
		tooGPA = 0;
	}
}

void Student::setcredits(int tooCredits)
{
	if (tooCredits >= 0)
	{
		credits = tooCredits;
	}

	else
	{
		cout << "Invalid; Credits was set to 0." << endl;
		tooCredits = 0;
	}
}

string Student::getname()
{
	return name;
}

double Student::getGPA()
{
	return GPA;
}

int Student::getcredits()
{
	return credits;
}
