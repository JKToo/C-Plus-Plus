#include <iostream>
#include "Course.h"
using namespace std;

void inputCourseData(Course* tooC)
{
	cout << "Enter course number: ";
	string tooNumber;
	cin >> tooNumber;
	tooC->setCourseNo(tooNumber);

	cout << "Enter number of credits: ";
	int tooCr;
	cin >> tooCr;
	tooC->setcredits(tooCr);

	cout << "Enter number of students: ";
	int tooStudents;
	cin >> tooStudents;
	tooC->setstudentCount(tooStudents);

	cout << endl << "Course number: " << tooC->getCourseNo() << endl << "Number of credits: " <<
		tooC->getcredits() << endl << "Number of students in course: " << tooC->getstudentCount() << endl;
}

void inputStudentData(Course* tooC)
{
	cout << endl << "_____________________________________";
	Student* roster = new Student[tooC->getstudentCount()];
	for (int tooi = 0; tooi < tooC->getstudentCount(); tooi++) {
		cout << endl << "Student " << tooi + 1 << endl;

		Student* tooStudent = new Student();

		// input name credits and GPA
		cout << "Enter name: ";
		string tooName;
		cin >> tooName;
		tooStudent->setname(tooName);

		cout << "Enter number of credits: ";
		int tooCredits;
		cin >> tooCredits;
		tooStudent->setcredits(tooCredits);

		cout << "Enter GPA: ";
		double tooGPA;
		cin >> tooGPA;
		tooStudent->setGPA(tooGPA);

		roster[tooi] = *tooStudent;

		tooC->setroster(roster);
	}
}

void GPAStats(double& maxGPA, double& minGPA, double& aveGPA, Course* tooC)
{
	Student* tooArr = tooC->getroster();
	maxGPA = tooArr[0].Student::getGPA();
	minGPA = tooArr[0].Student::getGPA();
	aveGPA = 0;
	double tooSum = 0;
	cout << endl << "_____________________________________\nRoster Stats:";
	for (int i = 0; i < tooC->getstudentCount(); i++)
	{
		tooSum += tooArr[i].Student::getGPA();
		if (maxGPA < tooArr[i].Student::getGPA())
		{
			maxGPA = tooArr[i].Student::getGPA();
		}

		if (minGPA > tooArr[i].Student::getGPA())
		{
			minGPA = tooArr[i].Student::getGPA();
		}
	}
	aveGPA = tooSum / tooC->getstudentCount();
}

void creditsStats(int& maxcredits, int& mincredits, double& avecredits, Course* tooC)
{
	Student* tooArr = tooC->getroster();
	maxcredits = tooArr[1].Student::getcredits();
	mincredits = tooArr[1].Student::getcredits();
	avecredits = 0;
	int tooSumcredits = 0;

	for (int i = 0; i < tooC->getstudentCount(); i++)
	{
		tooSumcredits += tooArr[i].Student::getcredits();
		if (maxcredits < tooArr[i].Student::getcredits())
		{
			maxcredits = tooArr[i].Student::getcredits();
		}

		if (mincredits > tooArr[i].Student::getcredits())
		{
			mincredits = tooArr[i].Student::getcredits();
		}
	}
	avecredits = tooSumcredits / tooC->getstudentCount();
	cout << endl;
}

int main()
{
	Course* course;
	course = new Course();
	double maxGPA; double minGPA; double aveGPA;
	int maxcredits; int mincredits; double avecredits;
	inputCourseData(course);
	inputStudentData(course);
	GPAStats(maxGPA, minGPA, aveGPA, course);
	creditsStats(maxcredits, mincredits, avecredits, course);
	cout << "MAX GPA: " << maxGPA << ", MIN GPA: " << minGPA << ", AVE GPA: " << aveGPA << endl;
	cout << "MAX Credits: " << maxcredits << ", MIN Credits: " << mincredits << ", AVE Credits: " << avecredits << endl;
}
