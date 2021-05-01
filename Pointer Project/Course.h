#include <iostream>
#include "Student.h"
using namespace std;

class Course
{
private:
	string CourseNo;
	int credits;
	Student* roster;
	int studentCount;

public:
	string getCourseNo();
	void setCourseNo(string);
	int getcredits();
	void setcredits(int);

	Student* getroster();
	void setroster(Student*);
	int getstudentCount();
	void setstudentCount(int);
	Course();
};
