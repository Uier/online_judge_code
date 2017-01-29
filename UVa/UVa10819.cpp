#include <iostream>
#include <string.h>
using namespace std;
int w[1050], v[1050], dp[102050];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m, n, ans;
	while ( cin >> m >> n ) {
		memset(dp,0,sizeof dp);
		for ( int i=1; i<=n; i++ )
			cin >> w[i] >> v[i];
		for ( int i=1; i<=n; i++ )
			for ( int j=10200; j>=w[i]; j-- )
   				if ( j == w[i] )
					dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
    			else if ( dp[j-w[i]] )
					dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
		ans = 0;
		for ( int i=0; i<10201; i++ )
			if ( ( i > 2000 && i <= m+200 ) || ( i <= m ) )
				ans = max(ans,dp[i]);
		cout << ans << '\n';
	}
	return 0;
}

