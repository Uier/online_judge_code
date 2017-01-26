#include <iostream>
#include <string.h>
using namespace std;
int a[105], p[105], dp[105][105];	// ans = dp[1][N]
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n;
	while ( cin >> n && n ) {
		memset(dp,0,sizeof dp);
		for ( int i=1; i<=n; i++ ) {
			cin >> a[i];
			dp[i][i] = a[i];
			p[i] = p[i-1] + a[i];
		}
		for ( int l=2; l<=n; l++ )
			for ( int i=1; i+l-1<=n; i++ ) {
				int j = i+l-1;
				int opt = p[j]-p[i-1];
				dp[i][j] = opt;
				for ( int k=i+1; k<=j; k++ )
					dp[i][j] = max(dp[i][j],opt-dp[k][j]);
				for ( int k=j-1; k>=i; k-- )
					dp[i][j] = max(dp[i][j],opt-dp[i][k]);
			}
		cout << dp[1][n]*2-p[n] << '\n';
	}	
	return 0;
}

