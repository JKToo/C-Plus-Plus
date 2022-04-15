/**
Header file for an Array Stack
@file: ArrayStack.h
@author: Justin Too
Date created: 3/20/2021
*/

#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

template <class T>
class ArrayStack{
	private:
		T* items;
		int maxSize;
		int top;

	public:
		ArrayStack();

		/**
		Reports whether the stack is empty or not
		@return true if empty, otherwise false
		*/
		bool isEmpty();

		/**
		Pushes a new item onto the top of the stack
		@post If successful, Entry is added and top count increases by 1
		@param newItem to be added
		@return True if item was added, otherwise false
		*/
		bool push(const T& newItem);

		/**
		Removes top item from the stack
		@post If successful, Entry is removed and top count decreases by 1
		@return True if item was removed, otherwise false
		*/		
		bool pop();

		/**
		Displays the value at the top of the stack
		@return the top value
		*/
		T peek();

		/**
		Checks if the word is a palindrome
		@post If successful, displays whether it is a palindrome or not
		@param String / Word to be checked
		@return If it is a palindrome or not
		*/
		void palindrome(const T& word);

		/**
		Reads a binary string
		@post If successful, displays whether or not the 1's and 0's are equal, if not what the difference is
		@param String binary of 1's and 0's
		@return The difference in number of values occured
		*/
		void checkBinary(const T& word);
};

#endif
