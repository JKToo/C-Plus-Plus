#include <iostream>
using namespace std;

/*
Write a function that accepts an int array as arguments. The function should create a new array that is one element larger
than the argument array. The first element of the new array should be set to 0. Element 0 of the argument array should be copied to element 1 of the new array, 
element 1 of the argument array should be copied to element 1 of the new array, elem
*/

int *arrDouble(int *arr, int size)
{
    int* copy;
    copy = nullptr;
    int newSize = size * 2;
    copy = new int[newSize];
    int j = size - 1;
    for (int i = 0; i < size * 2; i++, j--)
    {   
        if (i < size)
        {
            copy[i] = arr[j];
        }
        else   copy[i] = 0;
    }
    return copy;
}

int main()
{
    const int size = 10;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = i;
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << endl;

     int *x = arrDouble(arr, size);
     for (int i = 0; i < size * 2; i++)
     {
         cout << x[i] << " ";
     }



}
