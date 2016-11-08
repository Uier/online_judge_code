#include <iostream>
#include <string.h>
using namespace std;
int t, n, m, a[205], dp[205][205];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while ( t-- ) {
		cin >> n >> m;
		memset(dp,0x3f,sizeof dp);
		for ( int i=0; i<n; i++ )	dp[i][i] = 1;
		for ( int i=0; i<n; i++ )	cin >> a[i];
		for ( int i=n-1; i>=0; i-- )
			for ( int j=i+1; j<n; j++ ) {
				if ( a[i] == a[j] )
					dp[i][j] = min(dp[i+1][j],dp[i][j-1]);
				else
					for ( int k=i; k<j; k++ )
						dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]);
			}
		cout << dp[0][n-1] << '\n';
	} 
	return 0;
}

