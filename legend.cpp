// in the name of God
#include <iostream>
#include <complex>
using namespace std;

int satr,
    stun;

int record[2][2];

int check_valid ()
{
	if ( record[1][0] == record[1][1] && abs( record[0][0] - record[0][1] ) == 1 )
		return 1;
	if ( record[0][0] == record[0][1] && abs( record[1][0] - record[1][1] ) == 1 )
		return 1;
	
	return 0;
}

int main()
{
	int n,
	    m,
	    sum = 0;
	cin >> n >> m;
	
	char map[n][m];
	for ( int i = 0; i < n; i++ )
		cin >> map[i];
	
	if ( n < 3 || m < 3)
	{
		cout << 0;
		return 1;
	}
	
	do
	{
	        stun = 0;

		while ( m - stun >= 3 ) 
		{
			int dot = 0;
			for ( int sa = satr, counter = 0, i = 0; i < 3; i++, sa++ )  // 3 * 3
			{
				for ( int st = stun, j = 0; j < 3; j++, st++ )
				{
					if ( i == 1 && j == 1 )
						continue;
					if ( map[sa][st] == '.' )
					{
						if ( counter <= 1 )
							record[0][counter] = j, record[1][counter++] = i;
						dot++;
					}
				}
			}

			if ( dot == 2 ) {
				if ( check_valid() == 1 )
					sum += 1;
			}
                	else if ( dot == 1 )
                        	sum += 2;
                	else if ( dot == 0 )
                        	sum += 8;
			
			stun++;
		}

		satr++;
	} while ( n - satr >= 3 );
	
	cout << sum;
}
