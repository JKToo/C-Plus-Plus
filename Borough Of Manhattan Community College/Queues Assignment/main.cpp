#include <iostream>
#include "ArrayStack.cpp"
#include "Queue.cpp"
#include <string>

int main()
{
	cout << "Question 1, Palindrome:" << endl;
	cout << "-----------------------" << endl;
	ArrayStack<string> stack;
	stack.palindrome("race car");
	cout << endl;
	stack.palindrome("Repaper");
	cout << endl;
	stack.palindrome("a MaN. a PLaN a Canal, PaNAMA");
	cout << endl;
	stack.palindrome("racingcar");
	cout << endl;
	stack.palindrome("civiC");
	cout << endl;
	stack.palindrome("Hello World");
	
cout << "\n\n_____________________________________________________________________\n\n";
	cout << "Question 2, Binary String:" << endl;
	cout << "--------------------------" << endl;
	ArrayStack<string> stack2;
	stack2.checkBinary("1011010110");
	
cout << "\n\n_____________________________________________________________________\n\n";
	cout << "Question 3, Radomized:" << endl;
	cout << "----------------------" << endl;
	RandomizedQueue<int> queue;
	cout << "Original: ";
	for(int i = 0; i < 7; i++)
	{	
		queue.enqueue(i);
		cout << i << " ";
	}

	queue.randomized();

	cout << "\nAfter:    ";
	for(int i = 0; i < 6; i++)
	{	
		cout << queue.get() << " ";
		queue.dequeue();
	}
}
