#include <iostream>
#include <string.h>
using namespace std;
int t, n, m, x, p[1005], w[1005], dp[1005], ans;
int solve(int M) {
	for ( int i=0; i<n; i++ ) {
		for ( int j=M; j>=w[i]; j-- )
			dp[j] = max(dp[j],dp[j-w[i]]+p[i]);
	}
	return dp[M];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while ( t-- ) {
		ans = 0;
		memset(p,0,sizeof p);
		memset(w,0,sizeof w);
		cin >> n;
		for ( int i=0; i<n; i++	)
			cin >> p[i] >> w[i];
		cin >> m;
		while ( m-- ) {
			cin >> x;
			memset(dp,0,sizeof dp);
			ans += solve(x);
		}
		cout << ans << '\n';
	}
	return 0;
}

