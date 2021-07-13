#include <iostream>
using namespace std;

main()
{
    int *a;
    int *b;
    int s;

    a = new int;
    if(!a) exit(1);  //If (not) a = false exit

    b = new int;
    if(!b) exit(1); //If (not) b = flase exit

    cin >> *a;
    cin >> *b;

    s = *a + *b;

    cout << s;

    delete a;   //Free Memory
    delete b;   //Free Memory
}
//end progarm