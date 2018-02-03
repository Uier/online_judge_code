#include <iostream>
#include <string.h>
using namespace std;
long long dp[105][105];
long long f(int n, int m) {
	if ( n < m )	return 0;
	if ( m == 0 )	return 1;
	if ( dp[n][m] != -1 )	return dp[n][m];
	return dp[n][m] = f(n-1,m) + f(n-1,m-1);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	memset(dp,-1,sizeof dp);
	while ( cin >> n >> m && n ) {
		if ( !n )	break;
		cout << n << " things taken " << m << " at a time is " << 
			f(n,m) << " exactly.\n";
	}
	return 0;
}

