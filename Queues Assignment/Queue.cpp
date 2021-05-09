#include "Queue.h"
#include <iostream>
#include <cassert>
using namespace std;

template <class T>
RandomizedQueue<T>::RandomizedQueue()
{
	maxSize = 7;
	items = new T[maxSize];
	back = -1;
}

template <class T>
bool RandomizedQueue<T>::enqueue(T& item)
{
	if(back < maxSize-1){
		back++;
		items[back] = item;
		return true;
	}
	return false;
}

template <class T>
bool RandomizedQueue<T>::dequeue()
{
	if(!isEmpty())
	{
		//remove the first one
		for(int i = 0; i < back; i++)
		{
			items[i] = items[i+1];
		}
		back--;
		return true;
	}
	return false;
}

template <class T>
bool RandomizedQueue<T>::isEmpty(){
	return back < 0;
}

template <class T>
T RandomizedQueue<T>::get()
{
	assert(!isEmpty());
	return items[0];
}

template <class T>
bool RandomizedQueue<T>::randomized()
{
	srand(time(NULL));
	int random = (rand() % maxSize-1);
	if(!isEmpty())
	{
		for(int i = 0; i < back; i++)
		{
			if(i < random)
			{
				continue;
			}
			else if(i >= random) items[i] = items [i + 1];
		}
		back--;
		return true;
	}
	return false;
}
