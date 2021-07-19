//dynamic array
#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

int main()
{
    int x;
    int *a = NULL;
    int *p;
    int size = 0 , c = 0 , i;

    cout << "\nEnter : " << endl;

    while (cin >> x)
    {
        if (c >= size)
        {
            p = new int[size + 3];

            for (i = 0; i < size; ++i)
                p[i] = a[i];

            delete []a;
            
            a = p;
            size += 3;
        }
        a[c++] = x;
    }

 
    if (c == 0)
        cout << "No invalid input!" << endl;
    else
    {
        int sum = 0;
        for (i = 0; i < c; i++)
            sum += a[i];
        cout << "\nThe average: " << (float)sum/c << endl;
    }

    delete [] a;
}