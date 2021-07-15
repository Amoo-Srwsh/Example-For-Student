#include <iostream>
using namespace std;

main()
{
    int *p;

    p = new int(3);   // p = 3

    cout << *p << endl;  //3

    *p = 2;      //2

    cout << *p;   //2

    delete p;
}