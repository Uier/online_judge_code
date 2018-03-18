#include <iostream>
using namespace std;
bool G[205][205];
int dp[205][205];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, ans;
	while ( cin >> n >> m ) {
		int ans = 0;
		for ( int i=1; i<=n; ++i )
			for ( int j=1; j<=m; ++j )
				cin >> G[i][j];
		for ( int i=1; i<=n; ++i )
			for ( int j=1; j<=m; ++j )
				dp[i][j] = (G[i][j] ? dp[i][j-1]+1 : 0);
		for ( int i=1; i<=n; ++i )
			for ( int j=1; j<=m; ++j ) {
				for ( int k=i, h=1, w=1e5; k>=1; --k, ++h ) {
					w = min(w,dp[k][j]);
					ans = max(ans,w*h);
				}
			}
		cout << ans << '\n';
	}
	return 0;
}

