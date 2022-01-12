#include <bits/stdc++.h>
using namespace std;

struct player {
	char name[ 200 ];
	int prace;
	int speed;
	int finishing;
	int defence;
	bool player_work = 0; 
	int player_id;
};

struct team {
	char name[ 200 ];
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

	counter_a++;
	a[counter_a - 1].player_id = counter_a;
}

void cin_team_info () {
	cin >> b[counter_b].name >> b[counter_b].mony;
	
	counter_b++;
	b[counter_b - 1].team_id = counter_b;
}

int main()
{
	int id_palyer,
	    id_team;
	
	while ( 1 ) {
		string input;
		cin >> input;

		if ( input == "buy" ) {
			cin >> id_player >> id_team;


			continue;
		}

		if ( input == "end" )
			break;
		cin >> input;

		switch ( input ) {
			case "player":
				cin_palyer_info();
			break;
			case "team":
				cin_team_info();
			break;
		}
	}
}
