#include <iostream>
#include "arrayset.cpp"
#include "nodeset.cpp"
using namespace std;

int main() {
//------------------------------------------------------------------------------
//Array
	cout << "Array ADT: \n";
  arrList<int> arrlist, arrlist2, arrSetunion, arrIntersection, arrDifference;

	for(int i = 0; i<10; i++)
	{  
  		arrlist.add(i+10);
		arrlist2.add(i+20);
	}

  cout << arrlist.getCurrentSize();


	arrlist.display();
	arrlist.remove(15);
	arrlist.display();
	arrlist.remove();
	arrlist.display();
	cout << "Is it empty? " << arrlist.isEmpty() << endl;
	arrlist.clear();
	cout << "Is it empty? " << arrlist.isEmpty() << endl;

	cout << "List after clear: "; arrlist.display();
	cout << "List contains? " << arrlist.contains(5);

	arrlist2.display();
	cout << endl;
	arrSetunion = arrlist.setunion(arrlist, arrlist2);
	cout << "Union of both sets: "; arrSetunion.display();
	arrIntersection = arrlist.intersection(arrlist, arrlist2);
	cout << "Intersection of both sets: "; arrIntersection.display();
	arrDifference = arrlist.difference(arrlist, arrlist2);
	cout << "difference of both sets: "; arrDifference.display();
	arrlist.createSpellcheck();



//------------------------------------------------------------------------------
//Node 
	cout << "\n------------------------------------------------------------------------------\n" << " Node ADTs: \n" << endl;
	Nodelist<int> list, list2;

	for(int i = 0; i<10; i++)
	{  
  		list.add(i);
		list2.add(i+10);
	}

	list.display();
	list2.display();
	/*
	cout << "list size: " << list.getCurrentSize();
	list.remove(2);
	cout << endl;
	list.display();
	cout << "contains T/F: " << list.contains(3) << endl;
	cout << "Is it empty?: " << list.isEmpty() << endl;
	list.display();

	list.clear();
	cout << endl;
	cout << "New list: "; list.display();
	cout << endl;
	cout << "contains T/F: " << list.contains(3) << endl;
	list.remove();
	cout << "List after random removal: "; list.display();
	cout << endl;
	*/

	Nodelist<int> unionset = list.setunion(list, list2);
	cout << "Union: "; unionset.display();

	list.add(3); list.add(4); list.add(5); list.add(6); 
	list2.add(3); list2.add(4); list2.add(5); list2.add(6); 

	Nodelist<int> intersection = list.intersection(list, list2);
	cout << "Intersection: "; intersection.display();
	
	Nodelist<int> difference = list.difference(list, list2);
	cout << "Difference: "; difference.display();	
}
