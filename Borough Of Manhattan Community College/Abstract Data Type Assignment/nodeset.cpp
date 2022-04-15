#include "nodeset.h"
#include <iostream>
#include <vector>
using namespace std;

template <class T>
Nodelist<T>::Nodelist(){
	head = nullptr;
}

template <class T>
int Nodelist<T>::getCurrentSize(){
	int count = 0;
	Node<T>* temp = head;

	while(temp != nullptr){
		count++;
		temp = temp->next;
	}
	return count;
}

template <class T>
int Nodelist<T>::isEmpty(){	
	Node<T>* temp = head;

	if(temp != nullptr){
		return false;
	}
	return true;
}

template <class T>
void Nodelist<T>::add(const T& newEntry){
	Node<T>* temp = head;
	Node<T>* newNode = new Node(newEntry);
	newNode->next = head;
	head = newNode;
}

template <class T>
void Nodelist<T>::remove(const T& anEntry){	

	if(head != nullptr){
		Node<T>* curNode = head;
		Node<T>* prevNode = nullptr;

		while(curNode != nullptr)
		{
			if(curNode->data == anEntry)
			{
				break;
			}
			prevNode = curNode;		
			curNode = curNode->next;
		}

		if(curNode != nullptr)
		{
			if(curNode == head){
				head = head->next;
			}
			else{
				prevNode->next = curNode->next;
			}
			delete curNode;
			curNode = nullptr;
		}
	}
}

template <class T>
void Nodelist<T>::remove()	
{
	if(head != nullptr){
		Node<T>* temp = head;
		head = head -> next;
		delete temp;
	}
}

template <class T>
void Nodelist<T>::clear(){		
	while(head!=nullptr){


  Node<T>* temp = head;
   
      head = head->next;  
    
    delete temp;
    temp = nullptr;
	}
}

template <class T>
bool Nodelist<T>::contains(const T& anEntry)	
{
	Node<T>* temp = head;
	while(temp != nullptr)
	{
		if(temp->data == anEntry){
			return true;
		}
		else temp = temp->next;
	}
	return false;
}

template <class T>
void Nodelist<T>::display(){

	Node<T>* temp = head;

   while(temp!= nullptr)
   {
		cout<<temp->data<<"->"; 
		temp = temp->next;  
   }
 	cout<<endl;
}

template <class T>
vector<T> Nodelist<T>::toVector(){
		vector<T> copy;

	Node<T>* temp = head;

  while(temp!= nullptr)
  {
		copy.push_back(temp->data);
		temp = temp->next;   
  }

	return copy;
}

template <class T>
Nodelist<T> Nodelist<T>::setunion( Nodelist<T>& setA,  Nodelist<T>& setB)
{
	Nodelist<T> temp;

	vector<T> vect1 = setA.toVector();
	vector<T> vect2 = setB.toVector();

	for(int i =0 ; i<vect1.size(); i++){
		temp.add(vect1[i]);
	}

	for(int i =0 ; i<vect2.size(); i++){
		temp.add(vect2[i]);
	}

	return temp;
}

template <class T>
Nodelist<T> Nodelist<T>::intersection(Nodelist<T>& setA, Nodelist<T>& setB)
{
	Nodelist<T> temp;
	vector<T> vect1 = setA.toVector();
	vector<T> vect2 = setB.toVector();

	for(int i = 0 ; i < vect1.size(); i++)
	{
		for(int j = 0; j < vect2.size(); j++)
		{
			if(vect1[i] == vect2[j])
			{
				temp.add(vect1[i]);
			}
		}
	}
	return temp;
}

template <class T>
Nodelist<T> Nodelist<T>::difference(Nodelist<T>& setA, Nodelist<T>& setB)
{
	Nodelist<T> temp;
	int check = 0;
	vector<T> vect1 = setA.toVector();
	vector<T> vect2 = setB.toVector();

	for(int i = 0; i < vect1.size(); i++)
	{
		for(int j = 0; j < vect2.size(); j++)
		{
			if(vect1[i] == vect2[j])
			{
				check = 0;
				break;
			}
			else check = 1;
		}
		if(check == 1)
		{
			temp.add(vect1[i]);
		}
	}
	return temp;	
}
