/* write your own strlen() */
#include <iostream>
using namespace std;

int StrLen(char *a)
{
	char * tmp = a;
	while (*++tmp != '\0');
	return tmp - a;
}

int main()
{
	char a[] = "Hello My Name is Sroush :)";
	cout << StrLen(a);
}
