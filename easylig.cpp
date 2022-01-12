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
int counter_a = 1,
    counter_b = 1;

void cin_player_info () {
	cin >> a[counter_a].name >> a[counter_a].prace >> a[counter_a].speed >> 
	       a[counter_a].finishing >> a[counter_a].defence;

	a[counter_a].player_id = counter_a++;
}

void cin_team_info () {
	string input; cin >> input;
	int m; cin >> m;

	for ( int i = 0; i < counter_b; i++ )
		if ( b[i].name == input )
			return;

	b[ counter_b ].mony = m;
	b[ counter_b ].name = input;
	
	b[counter_b].team_id = counter_b++;
}

int main() {

	while ( 1 ) {
		string input;
		cin >> input;

		if ( input == "buy" ) {
			int id_player,
			    id_team;
			
			cin >> id_player >> id_team;
			if ( id_player > counter_a || id_player <= 0 ) {
				cout << "player with the id " << id_player << " doesnt exist" << endl;
				goto HELL;
			}
			if ( id_team > counter_b || id_team <= 0 ) {
				cout << "team with the id " << id_team << " doesnt exist" << endl;
				goto HELL;
			}
			if ( b[id_team].mony < a[id_player].prace ) {
				cout << "the team cant afford to buy this player" << endl;
				goto HELL;
			}
			if ( a[id_player].player_work == 1 ) {
				cout << "player already has a team" << endl;
				goto HELL;
			}

			b[id_team].mony -= a[id_player].prace;
			a[id_player].player_work = 1;
			cout << "player added to the team succesfully" << endl;
			
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
}
