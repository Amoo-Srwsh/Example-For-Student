#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e8

long long dp[INF];
long long fibunaci(int tt)
{
	if (tt==0||tt==1)
		return tt;
	dp[tt]=fibunaci(tt-1)+dp[tt-2];
	return dp[tt];
}
int main()
{
	int tt; cin >> tt;
        cout << fibunaci(tt+1) << endl; 
}
