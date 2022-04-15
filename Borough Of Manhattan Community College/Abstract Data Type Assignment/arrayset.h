/**
Header file for data structure arrList
@file: arrayset.h
@author: Justin Too
Date created: 2/28/2021
*/

#ifndef ARRAYSET_H
#define ARRAYSET_H
#include <vector>
#include <fstream>
using namespace std;
const int arrSize = 10;

template <class T>
class arrList{

private:
		int maxSize = 20;
		int numOfItems;
		T* items;

public:
	 arrList(){
		maxSize = 20;	
		items = new T[maxSize];
		numOfItems = 0;

	}

	/**
	 Tells the number of objects in the array list
	 @return the current number / size 
	*/
	int getCurrentSize();

	/**
	 Reports whether the bag is empty or not
	 @return true if empty, otherwise false
	*/
	bool isEmpty();

	/**
	 Adds a new item to the array list
	 @post If successful, Entry is added and item count increases by 1
	 @param newEntry item to be added
	 @return True if item was added, otherwise false
	*/
	bool add(const T& newEntry);

	/**
	 Removes an item from array list
	 @post If successful, Entry is removed and item count decreases by 1
	 @param anEntry item to be removed
	 @return True if item was removed, otherwise false
	*/
	bool remove(const T& anEntry);

	/**
	 Removes the first item in the array list
	 @post If successful, First entry is removed and item count decreases by 1
	 @return one less item count
	*/
	void remove();

	/**
	 Clears the whole array list
	 @post If successful, the bag is cleared and item count is 0
	 @return item count equals to zero
	*/
	void clear();

	/**
	 Checks if a specific entry is in the array list
	 @param anEntry to check for
	 @return True if removed, otherwise false
	*/
	bool contains(const T& anEntry);

	/**
	 Retrieves all entries that are in this array list
	 @return a vector containing all the entries in the array list
	*/
	vector<T> toVector() const;

	/**
	 Checks for the union of 2 given sets
	 @param setA array list 1
	 @param setB array list 2
	 @return The union of both array sets (combined entries)
	*/
	arrList setunion(arrList<T> setA, arrList<T> setB);

	/**
	 Checks for the intersection of 2 given sets
	 @param setA array list 1
	 @param setB array list 2
	 @return The intersection of both array sets (common entries)
	*/
	arrList intersection(arrList<T> setA, arrList<T> setB);	

	/**
	 Checks for the difference of 2 given sets
	 @param setA array list 1
	 @param setB array list 2
	 @return The difference of both array sets (Where entry is in one but not other)
	*/
	arrList difference(arrList<T> setA, arrList<T> setB);

	/**
	 Displays the array list
	 @return the contents in the array list
	*/
	void display();

	/**
	 Creates a dictionary.txt file and spell checks words typed
	 @return Whether the words were spelled correctly or not
	*/
	bool createSpellcheck();

};
#endif
