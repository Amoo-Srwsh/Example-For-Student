#include <iostream>
using namespace std;

int StrLen (char *a)
{
	char *b = a;
	while (*b++);
	
	return b - a - 1;
}

int check_valid (char *a, char *target, int stun, int len)
{
	for (int c = 0, k = stun; c < len; c++, k++)
		if (target[c] != a[k])
			return 0;
	return 1;
}

int main()
{
	int n, m, sum = 0;
	cin >> n >> m;
	
	char ch[n][m + 1];
	for (int i = 0; i < n; i++)
		cin >> ch[i];
	
	char target[100]; cin >> target;
	
	int len = StrLen(target);
	
	if (len > n && len > m)
	{
		cout << 0;
		return 1;
	}
	
	if (len <= m)
	{
		for (int i = 0; i < n; i++)
		{
			int stun = m;
			for (int j = 0; j < m; j++)
			{
				if (len <= stun)
				{
					sum += check_valid(ch[i], target, j, len);
					stun--;
				}
				else 
					break;
			}
		}
	}
	
	int nTmp = n, mTmp = m, k = 0;
	if (len <= n)
	{
		while (mTmp--)
		{
			int satr = n;
			for (int i = 0; i < n; i++)
			{
				bool check = true;
				if (len <= satr)
				{
					satr--;
					for (int c = 0, j = i; c < len; c++, j++)
						if (target[c] != ch[j][k])
						{
							check = false;
							break;
						}

					if (check)
						sum += 1;
				}
				else
					break;
			}
			
			k++;
		}
	}
	
	cout << sum;
}
