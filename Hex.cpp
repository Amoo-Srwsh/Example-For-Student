#include <bits/stdc++.h>
using namespace std;

int length;
bool recursion(string s, int len)
{
	if (s[len]=='\0') return true;
	if (s[len]!='F') return false;
	if (recursion(s,len+1)) {
		cout << 1;
		for (int i=0; i<length; i++)
			cout << 0;
		exit(1);
	}
	return false;
}
int main()
{
	string s; cin >> s;
	length=s.length()-1;
	recursion(s,0);
	do {
		switch (s[length]) {
			case 'F':
				s[length]='0';
				break;
			case '9':
				s[length]='A';
				break;
			default:
				s[length]++;
		}
	} while (s[length]=='0'&&--length>=0);
	for (int i=0; s[i]!='\0'; i++)
		cout << s[i];
}
