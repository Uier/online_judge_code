#include <iostream>
#include <string.h>
using namespace std;
typedef long long ll;
long long dp[205][205];
string s;
ll sum(int x, int y) {
	if ( dp[x][y] != -1 )	return dp[x][y];
	if ( s[x] == 0 && y-x > 0 )	return -1e15;
	ll tmp = 0;
	for ( int i=x; i<=y; ++i ) {
		tmp = tmp*10 + s[i]-'0';
		dp[x][i] = tmp;
	}
	if ( tmp > 2147483647 )	return -1e15;
	return tmp;
}
ll sol(int x, int y) {
	if ( x >= s.size() )	return 0;
	if ( dp[x][y] != -1 )	return dp[x][y];
	ll tmp = -1;
	for ( int i=x; i<x+10&&i<s.size(); ++i )
		tmp = max(tmp,sum(x,i)+sol(i+1,s.size()-1));
	return dp[x][y] = tmp;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while ( n-- ) {
		memset(dp,-1,sizeof dp);
		cin >> s;
		cout << sol(0,s.size()-1) << '\n';
	}
	return 0;
}

