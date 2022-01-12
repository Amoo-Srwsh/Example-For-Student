#include <bits/stdc++.h>
#include <complex>
using namespace std;

struct player {
	string name;
	int prace;
	int speed;
	int finishing;
	int defence;
	int player_id;
	bool player_work = 0; 
};

struct team {
	string name;
	int mony;
	int team_id;
};

player a[100000];
team b[100000];
int counter_a = 0,
    counter_b = 0;

void cin_player_info () {
	cin >> a[counter_a].name >> a[counter_a].prace >> a[counter_a].speed >> 
	       a[counter_a].finishing >> a[counter_a].defence;

	a[counter_a].player_id = ++counter_a;
}

void cin_team_info () {
	string input; cin >> input;
	int m; cin >> m;

	for ( int i = 0; i < counter_b; i++ )
		if ( b[i].name == input )
			return;

	b[ counter_b ].mony = m;
	b[ counter_b ].name = input;
	
	b[counter_b].team_id = ++counter_b;
}

int main() {

	int results[100000], c = 0;

	while ( 1 ) {
		string input;
		cin >> input;

		if ( input == "buy" ) {
			int id_player,
			    id_team;

			cin >> id_player >> id_team;
			if ( id_player > counter_a && id_player < 0 ) {
				results[ c++ ] = id_player;
				goto HELL;
			}

			if ( id_team > counter_b || id_player < 0 ) {
				results[ c++ ] = -id_team;
				goto HELL;
			}

			results[ c++ ] = 0;

			
			HELL:
			continue;
		}

		if ( input == "end" )
			break;

		cin >> input;

		if ( input == "player" )
			cin_player_info();
		else if ( input == "team" )
			cin_team_info();
	}

	for ( int i = 0; i < c; i++ ) {
		if ( results[ i ] == 0 )
			cout << "player added to the team succesfully" << endl;
		else if ( results[ i ] > 0 )
			cout << "player with the id " << results[ i ] << " doesnt exist" << endl;
		else if ( results[ i ] < 0 )
			cout << "team with the id " << abs( results[ i ] ) << " doesnt exist" << endl;
	}
}
