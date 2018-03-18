#include <iostream>
#include <string.h>
using namespace std;
int dp[1003][5003], a[5003];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n, k;
	cin >> t;
	while ( t-- && cin >> k >> n ) {
		k += 8;
		for ( int i=1; i<=n; ++i )
			cin >> a[n+1-i];
		memset(dp,0x3f,sizeof(dp));
		for ( int i=0; i<=n; ++i )	dp[0][i] = 0;
		for ( int i=1; i<=k; ++i )
			for ( int j=1; j<=n; ++j )
				if ( (j-2)-3*(i-1) <= 0 )
					dp[i][j] = dp[i][j-1];
				else
					dp[i][j] = min(dp[i][j-1]
								  ,dp[i-1][j-2]+(a[j-1]-a[j])*(a[j-1]-a[j]));
		cout << dp[k][n] << '\n';
	}
	return 0;
}

