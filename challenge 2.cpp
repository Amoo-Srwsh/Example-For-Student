#include <iostream>
using namespace std;

int a_size = 0;
int b_size = 0;

bool check1 (char dest, char *src, int *banned)
{
	for (int i = 0; i < b_size; i++)
		if (dest == src[i] && banned[i] != 0)
		{
			banned[i] = 0;
			return true;
		}

	return false;
}

bool check (char *a, char *b, int loc)
{
	int new_size = b_size, symbol = 0;
	int banned_inedx[b_size], chars = 0;

	for (int i = 0; i < b_size; i++)
		banned_inedx[i] = b[i];

	while (new_size--)
	{
		if (a[loc] == '?')
		{
			symbol += 1;
			loc++;
			continue;
		}
		if (check1 (a[loc], b, banned_inedx))
		{
			chars += 1;
			loc++;
			continue;
		}
	}
	
	if ((symbol + chars) == b_size)
		return true;
	return false;
}
		
int find_words (char *a, char *b)
{
	int sum = 0;
	for (int i = 0; i < a_size; i++)
		if (check (a, b, i))
			sum++;

	return sum;
}

int StrLen (char *s)
{
	const char *sc = s;

        for (; *s != '\0'; s++);

        return s - sc;
}

int main ()
{
	char a[1001];
	char b[1001];
	cin >> a >> b;
	
	a_size = StrLen(a), b_size = StrLen(b);
	
	cout << find_words(a, b);
}
