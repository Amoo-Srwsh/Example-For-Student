#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main()
{
	int n,m,k;
	cin >> n >> m >> k;
	
	int a[k][2],tekrar[(n * m) - k];
	char b[n][m];

	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> a[i][j];
			a[i][j] -= 1;
		}
	}
	
	///////////////////////////////////////////////
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++ )
			b[i][j] = '0';
	
			
	for (int i = 0; i < k; i++)
		b[a[i][0]][a[i][1]] = '*';
	//////////////////////////////////////////////
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (b[i][j] != '*')
			{
				//////////////////////////////////////////////
				int up,down;
				
				up = (i - 1 < 0) ? 0 : (i - 1);
				down = (i + 1 > (n - 1)) ? (n - 1) : (i + 1); 
				//////////////////////////////////////////////
		
				//////////////////////////////////////////////
				int left,right;
				
				left = (j - 1 < 0) ? 0 : (j - 1);
				right = (j + 1 >= (m - 1)) ? (m - 1) : (j + 1);
				//////////////////////////////////////////////
	
				int all = 0;
				for (int u = up; u <= down; u++)
				{
					for (int l = left; l <= right; l++)
					{
						if (b[u][l] == '*')
							all += 1;
					}
				}
					
				cout << all << " ";
				continue;
			}
			
			cout << "* ";
		}
		
		cout << endl;
	}
}
