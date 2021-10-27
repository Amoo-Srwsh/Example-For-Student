/* write your own strcpy() */
#include <iostream>
using namespace std;

void * StrCat(char *a,char *b)
{
	while (*b)
		b++;
	while ((*b++ = *a++) != '\0');
}
int main()
{
	char a[80] = "Sroush";
	char b[80] = "Hello This Is "; 
	
	StrCat(a,b);
	cout << b << endl;
}
