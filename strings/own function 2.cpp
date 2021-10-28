/* write your own strcpy() */
#include <iostream>
using namespace std;

void * StrCpy(char *a,const char *b)
{
	while (((*a++) = (*b++)) != '\0');
}
int main()
{
	char a[80];
	char b[80] = "Hello This Is sroush"; 
	
	StrCpy(a,b);
	cout << a << endl;
}
