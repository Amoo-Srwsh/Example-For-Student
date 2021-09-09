  // This program demonstrates the searchList function,
 // which performs a linear search on an integer array.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

// Function prototype
int searchList(string [], int, string);

const int SIZE = 10;

int main()
 {
 int tests[SIZE] = {87, 75, 98, 100, 82}; //online example
 
 struct player
{
              char name[20];
                int game1;//mmddyyyy
                int game2;
                int game3;
                int game4;
                int game5;
                
}person;


int results; // Holds the search results
int num;
string scorer;
string srchPlayer;
float average=0;
ifstream infile;
    infile.open("stats.dat");
    while(infile>>person.name>>person.game1>>person.game2>>person.game3>>person.game4>>person.game5)
                 infile.close();


cout<<"enter player name: "<<endl;
//cin>>num;
cin>>scorer;
 // Search the array for the value 100
 //results = searchList(tests, SIZE, num);
results = searchList(person, SIZE, scorer);
 // If searchList returned -1, 100 was not found
 if (results == -1)
 //cout << "You did not earn 100 points on any test.\n"; //online example
    cout<<"Player doesn't exist";
 else
 { // Otherwise results contains the subscript of
 // the first 100 found in the array
 //cout << "You earned "<<num<<" points on test "; //online example
 cout << (results + 1) << ".\n";
 average = (person.game1+person.game2+person.game3+person.game4+person.game5)/num;
 cout<<"Player "<<results<<" is averaging "<<average<<" points per game";
 }
 return 0;
 }

 /*****************************************************************
* searchList *
 * This function performs a linear search on an integer array. *
 * The list array, which has size elements, is searched for *
 * the number stored in value. If the number is found, its array *
 * subscript is returned. Otherwise, -1 is returned. *
 *****************************************************************/
 int searchList(string list[], int size, string value)
{
 int index = 0; // Used as a subscript to search array
 int position = -1; // Used to record position of search value
 bool found = false; // Flag to indicate if the value was found

while (index < size && !found)
 {
 if (list[index] == value) // If the value is found
{
 found = true; // Set the flag
 position = index; // Record the value's subscript
 }
index++; // Go to the next element
}
return position; // Return the position, or -1
}