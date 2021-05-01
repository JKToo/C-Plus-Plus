#include "Customer.h"
#include <iostream>
#include <cstdio>
using namespace std;

Customer::Customer(string n, string i, string s)
{
    name = n;
    insurance = i;
    state = s;
}

void Customer::setName(string n)
{
    name = n;
}

void Customer::setInsurance(string i)
{
    insurance = i;
}

void Customer::setState(string s)
{
    state = s;
}
