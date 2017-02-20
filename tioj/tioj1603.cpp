#include <iostream>
#include <string.h>
using namespace std;
bool G[203][203];
int dp[203][203];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for ( int i=1; i<=n; i++ )
		for ( int j=1; j<=m; j++ )
			cin >> G[i][j];
	memset(dp,0,sizeof dp);
	for ( int i=1; i<=n; i++ )
		for ( int j=1; j<=m; j++ )
			dp[i][j] = (!G[i][j] ? 0 : dp[i][j-1]+1);
	int ans = 0;
	for ( int i=1; i<=n; i++ )
		for ( int j=1; j<=m; j++ ) {
			int wid = 210;
			for ( int h=0; i-h>=1; h++ ) {
				if ( !dp[i-h][j] )	break;
				wid = min(wid,dp[i-h][j]);
				ans = max(ans,(h+1)*wid);
			}
		}
	cout << ans << '\n';
	return 0;
}

