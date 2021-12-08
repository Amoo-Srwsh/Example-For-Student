// in the name of God

// https://quera.ir/problemset/123801/

#include <iostream>
#include <complex>
using namespace std;

int x[5], y[5];

int main()
{
	for ( int i = 0; i < 5; i++ )
		cin >> x[i];
	for ( int i = 0; i < 5; i++ )
		cin >> y[i];
	
	for ( int i = 0; i < 5; i++ ) {

		int x_tmp[3];

		switch ( i ) {

			case 3:
			   x_tmp[0] = x[i], x_tmp[1] = x[i + 1], x_tmp[2] = x[0];
			break;
			
			case 4:
			   x_tmp[0] = x[i], x_tmp[1] = x[0], x_tmp[2] = x[1];
			break;
			
			default:
			   x_tmp[0] = x[i], x_tmp[1] = x[i + 1], x_tmp[2] = x[i + 2];
			break;
		}
		
		for ( int j = 0; j < 5; j++ ) {
			
			int y_tmp[3];
			
			switch ( j ) {
				
				case 3:
				   y_tmp[0] = y[j], y_tmp[1] = y[j + 1], y_tmp[2] = y[0];
				break;
	
				case 4:
				   y_tmp[0] = y[j], y_tmp[1] = y[0], y_tmp[2] = y[1];
				break;
				
				default:
				   y_tmp[0] = y[j], y_tmp[1] = y[j + 1], y_tmp[2] = y[j + 2];
				break;
			}
	
			int sum = 0;
			///////////////

			if ( x_tmp[0] + y_tmp[0] >= 10 ) {
				sum = ( x_tmp[0] + y_tmp[0] ) % 10;
				sum *= 10;
			}
			else {
				sum = ( x_tmp[0] + y_tmp[0] );
				sum *= 10;
			}
			if ( x_tmp[1] + y_tmp[1] >= 10 ) {
				sum += ( x_tmp[1] + y_tmp[1] ) % 10;
				sum *= 10;
			}
			else {
				sum += ( x_tmp[1] + y_tmp[1] );
				sum *= 10;
			}
			if ( x_tmp[2] + y_tmp[2] >= 10 )
				sum += ( x_tmp[2] + y_tmp[2] ) % 10;
			else
				sum += ( x_tmp[2] + y_tmp[2] );
			
			///////////////
			if ( sum % 6 == 0 ) {
				cout << "Boro joloo :)";
				return 1;
			}
		}
	}
	
	cout << "Gir oftadi :(";
	
	return 0;
}
