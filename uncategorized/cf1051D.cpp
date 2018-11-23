#include <iostream>
#define int long long
using namespace std;
int dp[2][2005][2];
const long long mod = 998244353;
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	dp[1][1][1] = 2;
	dp[1][1][2] = 0;
	dp[1][2][1] = 0;
	dp[1][2][2] = 2;
	int cur = 0, pre = 1;
	for ( int i=2; i<=n; ++i, cur^=1, pre^=1 ) {
		dp[cur][1][1] = dp[pre][1][1];
		dp[cur][1][2] = dp[pre][1][2];
		for ( int j=2; j<=i*2; ++j ) {
			dp[cur][j][1] = (dp[pre][j][1]+dp[pre][j][2]*2+dp[pre][j-1][1])%mod;
			dp[cur][j][2] = (dp[pre][j][2]+dp[pre][j-1][1]*2+dp[pre][j-2][2])%mod;
		}
	}
	cout << (dp[pre][k][1]+dp[pre][k][2])%mod << '\n';
	return 0;
}

