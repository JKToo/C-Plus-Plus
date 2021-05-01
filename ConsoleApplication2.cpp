#include <iostream>
using namespace std;

int doSomething(int& x, int& y)
{
	int temp = x;
	x = y * 10;
	y = temp * 10;
	return x + y;
}


int doSomething2(int* x, int* y)
{
	int temp = *x;
	*x = *y * 10;
	*y = temp * 10;
	return *x + *y;
}

int main()
{
	int a = 3;
	int b = 4;
	int a1 = 3;
	int b1 = 4;

	int *aa = &a1;
	int *bb = &b1;
	doSomething(a, b);
	cout << "a: " << a << endl << "b: " << b << endl;
	cout << "-------------------" << endl;
	doSomething2(aa, bb);
	cout << "a: " << a << endl << "b: " << b << endl;
}

