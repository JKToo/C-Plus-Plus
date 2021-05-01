#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
using namespace std;

class Customer
{
private:
    string name;
    string insurance;
    string state;

public:
    Customer(string, string, string);
    void setName(string);
    void setInsurance(string);
    void setState(string);

    string getName() const
    {
        return name;
    }

    string getInsurance() const
    {
        return insurance;
    }

    string getState() const
    {
        return state;
    }
};
#endif
