#include <iostream>
#include <string.h>
using namespace std;
int dp[10005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	int m, n, t;
	while ( cin >> m >> n >> t ) {
		memset(dp,0,sizeof dp);
		dp[m] = dp[n] = 1;
		for ( int i=1; i<=t; i++ )
			if ( dp[i] ) {
				if ( i+m <= t )
					dp[i+m] = max(dp[i+m],dp[i]+1);
				if ( i+n <= t )
					dp[i+n] = max(dp[i+n],dp[i]+1);
			}
		int ans = 0;
		for ( int i=t; i>=0; i-- )
			if ( dp[i] ) {
				ans = i;
				break;
			}
		cout << dp[ans];
		if ( ans != t )
			cout << " " << t-ans;
		cout << '\n';
	}
	return 0;
}

