#include "LinkedList.h"
#include <iostream>
using namespace std;

template <class T>
Nodelist<T>::Nodelist(){
	head = nullptr;
}

template <class T>
void Nodelist<T>::insertLast(const T& anEntry)
{
	if(head == nullptr) head = new Node(anEntry);
	else insertLast(anEntry, head);
}

template <class T>
void Nodelist<T>::display(){

  Node<T>* temp = head;

   while(temp != nullptr)
   {
		cout<< temp->data<<"->"; //display the data of node that temp points to
		temp = temp->next;   // advance the temp pointer to next node
   }
 	cout<<endl;

}
