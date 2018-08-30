#include <iostream>
using namespace std;
long long dp[300005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n, x, y, pt = 1;
	string s;
	cin >> n >> x >> y >> s;
	while ( pt <= n && s[pt-1] == '1' )	pt++;
	dp[pt] = y;
	for ( int i=pt+1; i<=n; ++i ) {
		if ( s[i-1] == '0' && (i >= 2 && s[i-2] == '1') ) {
			dp[i] = min(dp[i-1]+x,dp[i-1]+y);
		} else	dp[i] = dp[i-1];
	}
	cout << dp[n] << '\n';
	return 0;
}

