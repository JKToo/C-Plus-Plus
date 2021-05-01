#include <iostream>
using namespace std;

class Student
{
private:
	string name;
	double GPA;
	int credits;
public:
	string getname();
	void setname(string);
	double getGPA();
	void setGPA(double);
	int getcredits();
	void setcredits(int);
	Student();
};
