#include <iostream>
#include "LinkedList.cpp"
using namespace std;

void writeLine(int n)
{
	if(n > 0)
	{
		cout << "* ";
		writeLine(n-1);
	}
}

void writeBlock(int x, int y)
{
	if(y >= 1)
	{
		writeLine(x);
		cout << endl;
		writeBlock(x, y-1);
	}
}

void writeTriangle(int x)
{
	if(x > 0)
	{
		writeTriangle(x-1);
		writeLine(x);
		cout << endl;
	}
}

int numOfDigits(int x)
{
	if(x == 0 ) return 0;
	return 1 + numOfDigits(x/10);
}

int main() {
  //Question 1
  cout << "\nQuestion 1: \nWrite a recursive C++ function writeLine that writes an asterisk (* ) with a space repeatedly to form a line of n asterisks. For example, writeLine(5) produces the line * * * * *\n"; 
  
	cout << "\nOutput: \n"; writeLine(5);


  //Question 2
cout<<"\n--------------------------------------------------------------------------------\n";
cout << "\nQuestion 2: \nWrite a recursive function writeBlock that uses writeLine to write m lines of n characters each. For example, writeBlock(5, 4) produces the output " <<
	"\n* * * * *\n* * * * *\n* * * * *\n* * * * *" << endl;
  
	cout << "\nOutput: \n"; writeBlock(5,4);


  //---------------------------------------------------------------------------------------
cout<<"--------------------------------------------------------------------------------\n";
	cout << "\nQuestion 3: \nWrite a recursive function writeTriangle that uses writeLine to write n lines of asterisks. The asterisks of each line range from 1 to n . For example, writeTriangle (5) produces the output \n*\n* *\n* * *\n* * * *\n* * * * *" << endl;
  
	cout << "\nOutput: \n"; writeTriangle(5);


  //Question 4
cout<<"--------------------------------------------------------------------------------\n";

	cout << "\nQuestion 4: \nWe can determine how many digits a positive integer has by repeatedly dividing by 10 (without keeping the remainder) until the number is less than 10, consisting of only 1 digit. We add 1 to this value for each time we divided by 10. Write a recursive function numOfDigits(int n) to return the number of digits of an integer n \n\nOutput: " << numOfDigits(1379) << endl << endl;


  //Question 5
cout<<"--------------------------------------------------------------------------------\n";

	cout << "\nQuestion 5:\nWrite insertLast(const ItemType&  anEntry), which calls a recursive method insertLast(const ItemType&  anEntry, Node< ItemType>* node), to insert anEntry to the end of the Linked List.\n\nOutput: ";
	Nodelist<int> test;
	test.insertLast(5);
	test.insertLast(6);
	test.insertLast(7);
	test.insertLast(3);
	test.display();
}	
