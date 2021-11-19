#include <iostream>
#include <string.h>
#include <iomanip>
#include <cstdlib>
using namespace std;

/* https://quera.ir/problemset/3031/ */

bool check (long long *b,long long value, long long size)
{
	if (size == 0)
		return true;
	for (long long  i = 0; i < size; i++)
		if (b[i] == value)
			return false;
	return true;
}

void after_num (long long after_number[][2], long long *value, long long size)
{
	if (size == 1)
	{
		long long sum = *value - after_number[0][0];
		sum += after_number[0][1];
		if (*value >= after_number[0][0] && sum > *value)
		{
			*value -= after_number[0][0];
			*value += after_number[0][1]; 
		}
	
		return;
	}
	
	long long blocked_number[size], c = 0;
	for (long long i = 0; i < size; i++)
	{	
		for (long long j = 0; j < size; j++)
		{
			long long sum = *value - after_number[j][0];
			sum += after_number[j][1]; 
			if (sum > *value && *value >= after_number[j][0] && check(blocked_number, j + 1, c))
			{
				*value -= after_number[j][0];
				*value += after_number[j][1];
				
				blocked_number[c++] = j + 1;
			}
		}
		
		if (c == 0)
			return;
	}
	
	return;
}

int main()
{
	long long  n, k; 
	cin >> n >> k;
	
	long long  a[n][2];
	
	for (long long  i = 0; i < n; i++)
		cin >> a[i][0] >> a[i][1];
	
	
	long long  blocked_number[n], c = 0, energy = k;
	long long  after_number[n][2], c1 = 0;

	for (long long  j = 1; j <= n; j++)
	{
		long long  sum = energy - a[j - 1][0];
		sum += a[j - 1][1];

		if (sum >= energy && energy >= a[j - 1][0] && check(blocked_number, j, c))
		{
			energy -= a[j - 1][0];
			energy += a[j - 1][1];
			blocked_number[c++] = j;
			
			continue;
		}
		
		after_number[c1][0] = a[j - 1][0], after_number[c1++][1] = a[j - 1][1];
	}
		
	if (c1 == 0)
	{
		cout << energy;
		return 1;
	}
	
	after_num(after_number, &energy, c1);
	
	cout << energy;
}
