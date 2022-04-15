#include "Customer.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string customerName, customerInsurance, customerState;

    cout << "What is your name? \n";
    cin >> customerName;

    cout << "What is the name of your insurance? \n";
    cin >> customerInsurance;

    cout << "What state do you live in? \n";
    cin >> customerState;


    Customer custom(customerName, customerInsurance, customerState);
    cout << endl << "Customer info: " << endl << custom.getName() << endl << custom.getInsurance() << endl << custom.getState();
    return 0;
}
