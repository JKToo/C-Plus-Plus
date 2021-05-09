#include <iostream>
#include "arrayset.h"
#include <vector>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

template <class T>
int arrList<T>::getCurrentSize()
{
	int count = 0;
	for(int i = 0; i < arrSize; i++)
	{
		count++;
	}
	return count;
}

template <class T>
bool  arrList<T>::isEmpty()
{
	if(numOfItems == 0) return true;
	return false;
}

template <class T>
bool  arrList<T>::add(const T& newEntry)
{
		items[numOfItems] = newEntry;
		numOfItems++;
		return true;

}

template <class T>
bool  arrList<T>::remove(const T& anEntry)
{
	for(int i = 0; i < arrSize; i++)
	{
		if(items[i] == anEntry){
			items[i] = items[numOfItems-1];
			numOfItems--;
			break;
		}
	}
		return false;
}

template <class T>
void  arrList<T>::remove()
{
	for(int i = 0; i < numOfItems; i++){
		items[i-1] = items[i];
	}
	numOfItems--;
}

template <class T>
void  arrList<T>::clear()
{
	numOfItems = 0;
}

template <class T>
bool arrList<T>::contains(const T& anEntry)
{
	for(int i = 0; i < numOfItems; i++)
	{
		if(items[i] == anEntry) return true;
	}
	return false;
}

template <class T>
vector<T> arrList<T>::toVector() const {
	vector<T> copy;
	for(int i = 0; i < numOfItems; i++){
		copy.push_back(items[i]);
	}
	return copy;
}

template <class T>
arrList<T> arrList<T>::setunion(arrList<T> setA, arrList<T> setB)
{
	arrList<T> tempSet;
	int check = 0;
	for(int i = 0; i <= setA.getCurrentSize(); i++)
	{
		tempSet.add(setA.items[i]);
	}
	for(int j = 0; j <= setB.getCurrentSize(); j++)
	{
		check = 0;
		for(int i = 0; i <= setA.getCurrentSize(); i++)
		{
			if(setA.items[i] == setB.items[j])
			{
				check = 1;
				break;
			}
		}
		if(check == 0)
		{
			tempSet.add(setB.items[j]);
		}
	}

	return tempSet;
}

template <class T>
arrList<T> arrList<T>::intersection(arrList<T> setA, arrList<T> setB)
{
	arrList<T> tempSet;

	for(int j = 0; j <= setB.getCurrentSize(); j++)
	{
		for(int i = 0; i <= setA.getCurrentSize(); i++)
		{
			if(setA.items[i]==setB.items[j])
			{
				tempSet.add(setB.items[j]);		
			}
		}
	}
	return tempSet;
}

template <class T>
arrList<T> arrList<T>::difference(arrList<T> setA, arrList<T> setB)
{
	arrList<T> tempSet;
	int check = 0;
	for(int i = 0; i <= setA.getCurrentSize(); i++)
	{
		for(int j = 0; j <= setB.getCurrentSize(); j++)
		{
			if(setA.items[i] == setB.items[j])
			{
				check = 0;
				break;
			}
			else check = 1;
		}
		if(check == 1)
		{
			tempSet.add(setA.items[i]);
		}
	}
	return tempSet;
}

template <class T>	
void arrList<T>::display()
{
	for(int i = 0; i < numOfItems; i++)
	{
		cout << items[i] << " ";
	}
	cout << endl;
}

template <class T>	
bool arrList<T>::createSpellcheck(){ 
		fstream file;
		file.open("dictionary.txt",ios::out);

	if(!file) 
   { 
       cout<<"Error in creating file!!!"; 
       return false; 
   } 
  else{
   cout<<"\nCreating Dictionary file. . .\n"
   << "File created successfully!" << endl; 
   
   cout << "Enter dictionary size: ";
   int num; 
   cin >> num;
   int const arrSize = num;
   string wordList[num];
   for(int i = 0; i < num; i++){
	   cout << "Enter " << num << " words into the dictionary" << endl;
	   string text;
	   cin >> text;
	   wordList[i] = text;
	   file << text;
   }

   fstream check;
   string wordList2[num];
   check.open("spell.txt", ios::out);
   for(int i = 0; i < num; i++)
   {
  	 cout << "Now try to spell the words: " << endl;
	 string text;
	 cin >> text;
	 wordList2[i] = text;
	 check << text;
   }

	int incorrect = 0;
	cout << "\nMispelled words: " << endl;
	for(int i = 0; i < num; i++)
	{
		if(wordList2[i] != wordList[i])
		{
			cout << wordList2[i] << ", ";
			incorrect++;
		}
	}
		cout << "\nYou mispelled " << incorrect << " words.\n";
		return 0;
	}
   
}
