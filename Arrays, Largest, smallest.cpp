#include <iostream>
using namespace std;

int main()
{
    const int size = 10;
    int arr[size]{ 3, 2, 8, 4, 1, 13, 100, 2, 0, 10 };
    int lowest = arr[0]; 
    int highest = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (lowest > arr[i])
        {
            lowest = arr[i];
        }
        if (highest < arr[i])
        {
            highest = arr[i];
        }
    }
    cout << "Lowest: " << lowest;
    cout << endl << "Highest: " << highest;
}
