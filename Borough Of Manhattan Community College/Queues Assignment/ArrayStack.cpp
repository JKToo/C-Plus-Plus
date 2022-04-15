#include "ArrayStack.h"
#include <cassert>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

template <class T>
ArrayStack<T>::ArrayStack()
{
	maxSize=21;
	items = new T[maxSize];
	top = -1;

}

template <class T>
bool ArrayStack<T>::isEmpty()
{
	if (top == -1) return true;
	else return false;

	return top == -1;
}

template <class T>
bool ArrayStack<T>::push(const T& newItem)
{
	if(top < maxSize-1)
	{
		top++;
		items[top] = newItem;
		return true;
	}
	return false;	
}

template <class T>
bool ArrayStack<T>::pop()
{
	//assert(top >= 0);
	top -=1;
	return true;
}

template <class T>
T ArrayStack<T>::peek()
{
	//assert(top >= 0);
	return items[top];
}

template <class T>
void ArrayStack<T>::palindrome(const T& word)
{
	bool flag = true;
	ArrayStack<char> stackTemp;
	ArrayStack<char> order2;
	ArrayStack<char> original;
	int length = word.length();


	for(int i = 0; i < length; i++)	
	 {		 
		 if ((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z'))
		{ 		
			stackTemp.push(tolower(word[i]));
			order2.push(tolower(word[i])); 
		}  
	}
	
	for(int i = 0; i < length; i++)
	{
		original.push(stackTemp.peek());
		stackTemp.pop();
	}

	/*	Checks the display of both stacks
	for(int i = 0; i < length; i++)
	{
		cout << order2.peek()<<",";
		order2.pop();
	}
	cout << endl;
	
	for(int i = 0; i < length; i++)
	{
		cout << original.peek()<<",";
		original.pop();
	}
	*/

	for(int i = 0; i < length; i++)
	{
		if(order2.peek()=='\0') order2.pop();
		if(original.peek()=='\0') original.pop();

		if(order2.peek() == original.peek())
		{

			order2.pop();
			original.pop();

		}
		else 
		{
			flag = false;
			break;
		}	
	}
		if(flag == true)
		{
			cout << word << ", is a Palindrome.";
		}

	else
	{
		cout << word << ", is not a Palindrome.";
	}
}
	

template <class T>
void ArrayStack<T>::checkBinary(const T& word)
{
	ArrayStack<char> wordStack;
	int length = word.length();
	int zeros = 0;
	int ones = 0;

	for(int i = 0; i < length; i++)
	{
		wordStack.push(word[i]);
	}

	while(!wordStack.isEmpty())
	{
		if(wordStack.peek() == '0')
		{
			zeros++;
			wordStack.pop();
		}
		else if (wordStack.peek() == '1')
		{ 
			ones++;
			wordStack.pop();
		}

	}

	int difference;
	if(zeros > ones)
	{	
		difference = zeros - ones;
		cout << "There are more zeros than ones by " << difference;;
	}
	
	else if(ones > zeros)
	{
		difference = ones - zeros;
		cout << "There are more ones than zeros by " << difference;
	}

	else if(!(ones > zeros) && !(ones < zeros))
	{
		cout << "There are the same amount of ones and zeros. ";
	}
}

