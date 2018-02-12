#include <iostream>
#include <string.h>
using namespace std;
int dp[10205], w[105], val[105];
int main() { // dp[j] = the biggest value 
	ios::sync_with_stdio(0); // when sum of price equal to j
	cin.tie(0);
	int V, n;
	while ( cin >> V >> n ) {
		for ( int i=1; i<=n; ++i )
			cin >> w[i] >> val[i];
		memset(dp,0,sizeof(dp));
		for ( int i=1; i<=n; ++i ) {
			for ( int j=V+200; j>w[i]; --j )
				if ( dp[j-w[i]] )
					dp[j] = max(dp[j],dp[j-w[i]]+val[i]);
			dp[w[i]] = max(dp[w[i]],dp[0]+val[i]);
		}
		int ans = 0;
		for ( int j=0; j<=V+200; ++j )
			if ( j <= V || j > 2000 )
				ans = max(ans,dp[j]);
		cout << ans << '\n';
	}
	return 0;
}

