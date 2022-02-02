#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n, c;
ll k;
int ar[ 100000 ][ 2 ];

void rec( void )
{
	for ( ll i = 0; i < c; i++ )
		if ( ( k - ar[ i ][ 0 ] ) + ar[ i ][ 1 ] > k && k >= ar[ i ][ 0 ] ) {
			k -= ar[ i ][ 0 ];
			k += ar[ i ][ 1 ];
			ar[ i ][ 0 ] = 0, ar[ i ][ 1 ] = 0;
			rec();
			return;
		}
	return;
}

int main ()
{	
	cin >> n >> k;

	for ( ll i = 0; i < n; i++ ) {

		ll a, b;
		cin >> a >> b;

		if ( ( k - a ) + b > k && k >= a ) {
			k -= a;
			k += b;
		}
		else {
			if ( a >= b )
				continue;
			ar[ c ][ 0 ] = a, ar[ c++ ][ 1 ] = b;
		}
	}

	rec();

	cout << k;
}
