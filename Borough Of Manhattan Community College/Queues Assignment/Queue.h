/**
Header file for an Array Queue
@file: Queue.h
@author: Justin Too
Date created: 3/20/2021
*/

#ifndef RANDOMIZED_QUEUE_H
#define RANDOMIZED_QUEUE_H

template <class T>
class RandomizedQueue{
	private:
		T* items;
		int maxSize;
		int back;
		int front;
	public:
		RandomizedQueue();

		/**
		Displays the value at the front of the queue
		@return the first value
		*/
		T get();

		/**
		Pushes a new item onto the end of the queue
		@post If successful, Entry is added and back count increases by 1
		@param Item to be added
		@return True if item was added, otherwise false
		*/
		bool enqueue(T& item);

		/**
		Removes top item from the front of the queue
		@post If successful, Entry is removed and back count decreases by 1
		@return True if item was removed, otherwise false
		*/	
		bool dequeue();

		/**
		Randomly chooses a position in the Queue
		@post If successful, the item in the random position gets removed
		@return Queue array minus without the item in the chosen position
		*/
		bool randomized();

		/**
		Reports whether the queue is empty or not
		@return true if empty, otherwise false
		*/
		bool isEmpty();

};

#endif
