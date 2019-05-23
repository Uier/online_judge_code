#include <iostream>
#define int long long
#define maxn 15
#define maxm 100
using namespace std;
int dp[maxm][1<<maxn];
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	dp[0][0] = dp[0][1] = 1;
	for ( int i=1; i<n; ++i ) {
		for ( int j=0; j<(1<<i); ++j ) {
			dp[i][j<<1] += dp[i-1][j];
			dp[i][j<<1|1] += dp[i-1][j];
		}
	}
	for ( int i=n; i<m; ++i ) {
		for ( int j=0; j<(1<<n); ++j ) {
			if ( (j&(1<<n-1)) ) {
				dp[i][(j<<1)^(1<<n)] += dp[i-1][j];
				if ( j < (1<<n)-1 )	dp[i][(j<<1)^(1<<n)|1] += dp[i-1][j];
			} else {
				dp[i][j<<1] += dp[i-1][j];
				dp[i][j<<1|1] += dp[i-1][j];
			}
		}
	}
	int ans = 0;
	for ( int i=0; i<(1<<n); ++i )	ans += dp[m-1][i];
	cout << ans << '\n';
	return 0;
}

