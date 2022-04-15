// Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    char c;
    int i;
    char* cp;
    int* ip;

    c = *cp;
    cp = &c; 

    cp = cp + 1;
    std::cout << cp;
}
