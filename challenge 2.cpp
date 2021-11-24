#include <iostream>
#include <string.h>
using namespace std;

int a_size = 0;
int b_size = 0;

bool check2 (int *a, int index, int size)
{
	if (size == 0)
		return true;

	for (int i = 0; i < size; i++)
		if (a[i] == index)
			return false;
	return true;
}

bool check1 (char dest, char *src, int *banned, int *size)
{
	for (int i = 0; i < b_size; i++)
		if (dest == src[i] && check2(banned, i, *size))
		{
			banned[*size++] = i;
			return true;
		}

	return false;
}

bool check (char *a, char *b, int loc)
{
	int new_size = b_size, symbol = 0;
	int banned_inedx[b_size], chars = 0, c = 0;
	while (new_size-- != 0)
	{
		if (a[loc] == '?')
			symbol += 1;
		if (check1 (a[loc], b, banned_inedx, &c))
			chars += 1;
		loc++;
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
