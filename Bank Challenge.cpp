// in the name of God
#include <iostream>
#include <complex>
using namespace std;

#define size 10000

int dc = 0,
    wc = 0,
    sum = 0;

int sort [ size ];
bool ext = false;

int find_time ( char *time )
{
	int all = 0;
	all += ((( int )time[ 0 ] - 48) * 10) + ( int )time[ 1 ] - 48;
	all *= 59;

	all += (( int )time[ 3 ] - 48) * 10, (all += ( int )time[ 4 ] - 48);

	return all;
}

void sort_all_time ( int d[][ 3 ], int w[][ 4 ], int small_result[])
{
	int dummy_value = 0;

	for ( int i = 0; i < dc; i++ )
		sort[ d[ i ][ 2 ] ] = d[ i ][ 2 ] + 1;
	for ( int i = 0; i < wc; i++ )
		sort[ w[ i ][ 2 ] ] = w[ i ][ 2 ] + 1;

	for ( int i = 0; i < size; i++ ) {

		if ( sort[ i ] != 0 )
			small_result[ dummy_value++ ] = sort[ i ];

		if ( dummy_value > ( dc + wc ))
			break;
	}
}

void main_process ( int d[][ 3 ], int w[][ 4 ], int small_result[] )
{
	int shell = 0;

	for ( int i = 0; i < (dc + wc); i++ ) {

		bool check = false;
		for ( int j = 0; j < dc; j++ ) {

			if ( small_result[ i ] == d[ j ][ 2 ] + 1 ) {

				shell += d[ j ][ 1 ];
				check = true;
				break;
			}
		}

		if ( check )
			continue;

		for ( int k = 0; k < wc; k++ ) {

			if ( small_result[ i ] == w[ k ][ 2 ] + 1 ) {

				if ( w[ k ][ 3 ] == 1 ) {
					
					shell -= w[ k ][ 1 ];
					if ( shell < 0 ) {

						sum += abs( shell );
						shell = 0;
					}
				}
				else if ( shell >= w[ k ][ 1 ] && w[ k ][ 3 ] == 0 ) {

					cout << "DOROGHE";
					ext = true;
					return;
				}
			}
		}
	}
}
int main()
{
	int n;
	cin >> n;
	
	int dep[n][3];
	int wit[n][4];

	char dORw[4];

	for ( int i = 0; i < n; i++ ) {

		cin >> dORw;
		if ( dORw[ 0 ] == 'D' ) {

			dep[ dc ][ 0 ] = 1;
			cin >> dep[ dc ][ 1 ];

			// Find Time project
			char time[ 6 ];
			cin >> time;
			
			dep[ dc ][ 2 ] = find_time ( time );

			dc++;
		}
		else if ( dORw[ 0 ] == 'W' ) {

			wit[ wc ][ 0 ] = 2;
			cin >> wit[ wc ][ 1 ];

			// Fint Time project
			char time[ 6 ];
			cin >> time;

			wit[ wc ][ 2 ] = find_time ( time );
			
			char tORf[ 5 ];
			cin >> tORf;

			if ( tORf[ 0 ] == 'O' )
				wit[ wc ][ 3 ] = 1;
			else if ( tORf[ 0 ] == 'F' )
				wit[ wc ][ 3 ] = 0;
			wc++;
		}
	}

	int small_result[ dc + wc ];
	sort_all_time ( dep, wit, small_result );
	main_process ( dep, wit, small_result );

	if ( ext )
		return 1;
	cout << sum;
}
