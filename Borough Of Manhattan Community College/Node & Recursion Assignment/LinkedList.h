/**
Header file for Linkedlist
@file: LinkedList.h
@author: Justin Too
Date created: 4/09/2021
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "node.h"
using namespace std;

template <class T>
class Nodelist{

private:
	Node<T>* head;

	/**
	Retrieves anEntry and inserts it to last spot
	@param an Item to add
	@param the Node being passed
	@return the entry in the last slot
	*/
	Node<T>* insertLast(const T& anEntry, Node<T>* head){
		 if (head == nullptr)
	 	head = new Node(anEntry);
	
	 else
        head->next = insertLast(anEntry, head->next);
		return head;
	}
	
public:
	Nodelist();

	/**
	Inserts anEntry into last spot
	@post If successful, function will check for head and call recursive method
	@param an Item to add
	@return last slot entry
	*/
	void insertLast(const T& anEntry);

	/**
	Displays the Linked Linked
	@return the whole list
	*/
	void display();
};
#endif
