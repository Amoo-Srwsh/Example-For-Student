#include<iostream>
#include<sstream>
#include<string>
#include<iomanip>
using namespace std;

 struct item{
          int id;
          string iname;
          int price;
          };

 struct Order{
           int day;
           int month;
           int year;
           int quantity;
           item warmss;
           };

 struct Name{
           string last;
           string first;
           };
    
 struct Customer{
           struct Name cool;
           string contact;
           struct Order hot;
           };

int main ()
{  
    Customer C;
    Order O;
    cin >> C.hot.day;
    cout << C.hot.month;
    system("pause");
    return 0;
}
