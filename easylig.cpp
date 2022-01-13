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
	int power_team;
	int players_number;
	int win, loos, equal;
	int team_id;
};

player a[10000];
team b[10000];
int counter_a = 1,
    counter_b = 1;
int playerid_teamN[10000][10000];

/////////////////////////////////////////////////////////////////////////////

void cin_player_info ( void ) {
	cin >> a[counter_a].name >> a[counter_a].prace >> a[counter_a].speed >> 
	       a[counter_a].finishing >> a[counter_a].defence;

	a[counter_a].player_id = counter_a++;
}

void cin_team_info ( void ) {
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

		if ( input == "buy" ) {  // buy players by teams
			int id_player,
			    id_team;
			
			cin >> id_player >> id_team;
			if ( id_player > counter_a || id_player <= 0 ) {
				cout << "player with the id " << id_player << " doesnt exist" << endl;
				goto HELL0;
			}
			if ( id_team > counter_b || id_team <= 0 ) {
				cout << "team with the id " << id_team << " doesnt exist" << endl;
				goto HELL0;
			}
			if ( b[id_team].mony < a[id_player].prace ) {
				cout << "the team cant afford to buy this player" << endl;
				goto HELL0;
			}
			if ( a[id_player].player_work == 1 ) {
				cout << "player already has a team" << endl;
				goto HELL0;
			}

			b[id_team].mony -= a[id_player].prace;
			a[id_player].player_work = 1;
			playerid_teamN[ id_team ][ id_player ] = id_player;
			b[id_team].power_team += a[id_team].speed + a[id_team].finishing;
			b[id_team].players_number++;
			cout << "player added to the team succesfully" << endl;
			
			HELL0:
			continue;
		}
		
		if ( input == "sell" ) {  // sell player by teams
			int id_player,
                            id_team;

			cin >> id_player >> id_team;
			if ( id_team > counter_b || id_team <= 0 ) {
				cout << "team doesnt exist" << endl;
				goto HELL1;
			}
			if ( playerid_teamN[id_team][id_player] == 0 ) {
				cout << "team doesnt have this player" << endl;
				goto HELL1;
			}

			b[id_team].mony += a[id_player].prace;
			playerid_teamN[id_team][id_player] = 0;
			a[id_player].player_work = 0;
			b[id_team].power_team -= a[id_team].speed + a[id_team].finishing;
		        b[id_team].players_number--;
			cout << "player sold succesfully" << endl;

		        HELL1:
			continue;
		}

		if ( input == "match" ) {
			int teamID1,
			    teamID2;
			
			cin >> teamID1 >> teamID2;
			if ( teamID1 > counter_b || teamID2 > counter_b ) {
				cout << "team doesnt exist" << endl;
				goto HELL2;
			}
			if ( b[teamID1].players_number < 11 || b[teamID2].players_number < 11 ) {
				cout << "the game can not be held due to loss of the players" << endl;
				goto HELL2;
			}
			
			// TODO


		if ( input == "end" )
			break;

		cin >> input;

		if ( input == "player" )
			cin_player_info();
		else if ( input == "team" )
			cin_team_info();
	}
}
