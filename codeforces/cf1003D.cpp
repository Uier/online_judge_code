#include <iostream>
#include <algorithm>
#define maxn 200005
using namespace std;
int a[35];
long long dp[35];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n, q, x;
	cin >> n >> q;
	dp[0] = 1;
	for ( int i=1; i<35; ++i )	dp[i] = dp[i-1]<<1;
	for ( int i=0; i<n; ++i ) {
		cin >> x;
		int expp = lower_bound(dp,dp+35,x)-dp;
		a[expp]++;
	}
	while ( q-- && cin >> x ) {
		int cnt = 0;
		for ( int i=34; i>=0; --i ) {
			if ( a[i] == 0 || dp[i] > x )	continue;
			int used = x/dp[i];
			int actu = min(used,a[i]);
			cnt += actu;
			x -= dp[i]*actu;
		}
		if ( x > 0 )	cout << -1 << '\n';
		else	cout << cnt << '\n';
	}
	return 0;
}

