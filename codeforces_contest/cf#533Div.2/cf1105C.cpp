#include <iostream>
#define maxn 200005
using namespace std;
long long dp[maxn][3];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n, l, r, mod = 1000000007;
	cin >> n >> l >> r;
	long long sz = r-l+1;
	long long m[3] = {sz/3,sz/3,sz/3};
	if ( sz%3 == 1 )	m[l%3]++;
	else if ( sz%3 == 2 ) {
		m[l%3]++;
		m[(l+1)%3]++;
	}
	dp[0][0] = 1;
	dp[0][1] = 0;
	dp[0][2] = 0;
	dp[1][0] = m[0];
	dp[1][1] = m[1];
	dp[1][2] = m[2];
	for ( int i=2; i<=n; ++i ) {
		dp[i][0] = (dp[i-1][0]*m[0]%mod + dp[i-1][1]*m[2]%mod + dp[i-1][2]*m[1]%mod)%mod;
		dp[i][1] = (dp[i-1][1]*m[0]%mod + dp[i-1][2]*m[2]%mod + dp[i-1][0]*m[1]%mod)%mod;
		dp[i][2] = (dp[i-1][2]*m[0]%mod + dp[i-1][0]*m[2]%mod + dp[i-1][1]*m[1]%mod)%mod;
	}
	cout << dp[n][0]%mod << '\n';
	return 0;
}

