/* write your own strcmp() */
#include <iostream>
using namespace std;

int StrCmp(const char *a, const char *b)
{
	unsigned char c1,c2;

        while (1)
        {
                c1 = *cs++;
                c2 = *ct++;
                if (c1 != c2)
                        return (c1 < c2) ? -1 : 1;
                if (c1 == '\0' || c2 == '\0')
                        break;
        }

        return 0;
}

int main()
{
	char a[] = "abcdefg";
	char b[] = "abcdefg";
	
	cout << StrCmp(a,b);
}
