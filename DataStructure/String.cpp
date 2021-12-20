#include <iostream>
using namespace std;

void find_value ( char *m, int *All, int &counter) 
{
	while ( *m != '\0' ) {

		if ( *m == '=' ) {

			All[ counter++ ] = 0;
			m++;
			continue;
		}

		if ( *m != '=' ) {

			All [ counter++ ] = 1;
			m++;
			continue;
		}
	}
}

int main()
{
	int All[ 100000 ],
	    counter = 0;

	char m[ 100000 ];
	cin >> m;

	find_value ( m, All, counter );

	for ( int i = counter - 1; i >= 0; i-- ) {

		if ( All[ i ] == 0 ) {

			for ( int j = i; j >= 0; j-- )
				if ( All[ j ] == 1 ) {
					All[ j ] = 2;
					break;
				}
			All[ i ] = 2;
		}
	}

	for ( int i = 0; i < counter; i++ )
		if ( All[ i ] == 1 )
			cout << m[ i ];
}
