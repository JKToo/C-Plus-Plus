/**
Header file for data structure Nodelist
@file: nodeset.h
@author: Justin Too
Date created: 2/28/2021
*/

#ifndef NODESET_H
#define NODESET_H
#include <iostream>
#include "node.h"
#include <vector>
using namespace std;

template <class T>
class Nodelist{

private:
	Node<T>* head;
		
public:
	Nodelist();

	/**
	 Tells the number of objects in the Nodelist
	 @return the current number / size 
	*/
	int getCurrentSize();

	/**
	 Reports whether the Nodelist is empty or not
	 @return true if empty, otherwise false
	*/
	int isEmpty();

	/**
	 Adds a new item to the Nodelist
	 @post If successful, Item is added and item count increases by 1
	 @param newEntry item to be added
	 @return True if item was added, otherwise false
	*/
	void add(const T& newEntry);

	/**
	 Removes an item from Nodelist
	 @post If successful, Item is removed and item count decreases by 1
	 @param anEntry item to be removed
	 @return True if item was removed, otherwise false
	*/
	void remove(const T& anEntry);

	/**
	 Removes the first item in the Nodelist
	 @post If successful, First item is removed and item count decreases by 1
	 @return one less item count
	*/
	void remove();

	/**
	 Clears the whole Nodelist
	 @post If successful, the bag is cleared and item count is 0
	 @return item count equals to zero
	*/
	void clear();

	/**
	 Checks if a specific entry is in the Nodelist
	 @param anEntry to check for
	 @return True if removed, otherwise false
	*/
	bool contains(const T& anEntry);

	/**
	 Retrieves all entries that are in this Nodelist
	 @return a vector containing all the entries in the array list
	*/
	vector<T> toVector();

	/**
	 Displays the Nodelist
	 @return the contents in the Nodelist
	*/
	void display();

	/**
	 Checks for the union of 2 given Node sets
	 @param setA array list 1
	 @param setB array list 2
	 @return The union of both Node sets (combined entries)
	*/
	Nodelist<T> setunion(Nodelist<T>& setA,  Nodelist<T>& setB);

	/**
	 Checks for the intersection of 2 Node sets
	 @param setA array list 1
	 @param setB array list 2
	 @return The intersection of both Node sets (common entries)
	*/
	Nodelist<T> intersection(Nodelist<T>& setA, Nodelist<T>& setB);

	/**
	 Checks for the difference of 2 Node sets
	 @param setA array list 1
	 @param setB array list 2
	 @return The difference of both Node sets (Where entry is in one but not other)
	*/
	Nodelist<T> difference(Nodelist<T>& setA, Nodelist<T>& setB);
};
#endif
