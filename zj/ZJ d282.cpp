#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string.h>
#include <cmath>
#define maxn 25
#define int long long
using namespace std;
typedef pair<int,int> pii;
string M[maxn];
int dp[maxn][maxn];
main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, cs = 1;
	while ( cin >> n >> m && (n||m) ) {
		for ( int i=1; i<=n; ++i )	cin >> M[i];
		const int inf = 2e9;
		for ( int i=1; i<=n; ++i )
			for ( int j=1; j<=n; ++j )
				dp[i][j] = inf;
		for ( int i=1; i<=n; ++i )	dp[i][i] = 0;
		for ( int i=0, u, v, w; i<m; ++i ) {
			cin >> u >> v >> w;
			dp[u][v] = dp[v][u] = min(dp[u][v],w);
		}
		for ( int k=1; k<=n; ++k )
			for ( int i=1; i<=n; ++i )
				for ( int j=1; j<=n; ++j )
					dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
		long long ans = inf;
		int ansid = 0;
		for ( int i=1; i<=n; ++i ) {
			long long sum = 0;
			for ( int j=1; j<=n; ++j ) {
				sum += dp[j][i];
			}
			if ( sum < ans ) {
				ans = sum;
				ansid = i;
			}
//			cout << "i,sum: " << i << ' ' << sum << '\n';
		}
		cout << "Case #" << cs++ << " : " << M[ansid] << '\n';
	}
	return 0;
}

