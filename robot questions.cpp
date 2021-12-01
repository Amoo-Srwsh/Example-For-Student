#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int n,
	    m,
            l;
	cin >> n >> m >> l;
	
	int x,
	    y;
	cin >> x >> y;	
	x--, y--;
	
	char map[n][m + 1];
	char cont[l + 1];
	
	cin >> cont;
	
	for (int i = 0; i < n; i++)
		cin >> map[i];
	
	int c,
	    i,
	    j;
	c = 0;
	i = x;    // satr
	j = y;    // stun

	while ( cont[c] != '\0' )
	{
		if ( cont[c] == 'L' )
		{
			if ( map[i][j - 1] != '#' )
                        {
                                map[i][j] = '.';
                                c++;
                                continue;
                        }

                        if ( map[i][j] == '#' || map[i][j] == '.' )
                                map[i][j--] = '.';

                        continue;
		}
	
		if ( cont[c] == 'R' )
		{
			if ( map[i][j + 1] != '#' )
			{
				map[i][j] = '.';
				c++;
				continue;	
			}
			
			if ( map[i][j] == '#' || map[i][j] == '.' )
				map[i][j++] = '.';
	
			continue;
		}
	
		if ( cont[c] == 'U' )
		{
			if ( map[i - 1][j] != '#' )
                        {
                                map[i][j] = '.';
                                c++;
                                continue;
                        }

                        if ( map[i][j] == '#' || map[i][j] == '.' )
                                map[i--][j] = '.';
                 
                        continue;
		}
		
		if ( cont[c] == 'D' )
		{
			if ( map[i + 1][j] != '#' )
                        {
                                map[i][j] = '.';
                                c++;
                                continue;
                        }

                        if ( map[i][j] == '#' || map[i][j] == '.' )
                                map[i++][j] = '.';
                 
                        continue;
		}
	}
	
	cout << "\n\n\n\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << map[i][j];
		cout << endl;
	}
}
