//https://codeforces.com/gym/103496/problem/A
#include <bits/stdc++.h>
using namespace std;

char names[4][6] = {"Alice",
                    "Bob",
                    "Cindy",
                    "Dani"};
int StrCmp(char *a)
{
	for (int i=0; i<4; i++) {
		bool find=true;
		for (int j=0; a[j]!='\0'; j++)
			if (a[j]!=names[i][j])
				find=false;
		if (find==true)
			return i+1;
	}
	return -1;
}
int main()
{
	int s=0;
	for (int i=0; i<3; i++) {
		char name[6]; cin >> name;
		int val=StrCmp(name);
		if (val!=-1)
			s+=val;
	}
	cout << names[(10-s)-1];
}
