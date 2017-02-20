#include <iostream>
#include <string.h>
using namespace std;
char G[105][105];
int dp[105][105];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while ( t-- ) {
		int n, m, q;
		cin >> n >> m >> q;
		memset(G,0,sizeof G);
		for ( int i=1; i<=n; i++ )
			for ( int j=1; j<=m; j++ )
				dp[i][j] = 1;
		for ( int i=1; i<=n; i++ )
			for ( int j=1; j<=m; j++ ) {
				cin >> G[i][j];
				if ( G[i][j] == G[i-1][j] && G[i][j] == G[i][j-1] && G[i][j] == G[i-1][j-1] )
					dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1])) + 1;
			}
		cout << n << ' ' << m << ' ' << q << '\n';
		while ( q-- ) {
			int x, y, z = 1;
			cin >> x >> y;
			x++, y++;
			while ( x+1 <= n && y+1 <= m && dp[x+1][y+1] >= z*2+1 )
				x++, y++, z++;
			cout << z*2-1 << '\n';
		}
	}
	return 0;
}

