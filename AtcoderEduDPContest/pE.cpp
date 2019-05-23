#include <iostream>
#include <string.h>
#define maxn 101
#define maxv 100005
#define int long long
using namespace std;
int w[maxn], v[maxn], dp[maxv];
main() {
	ios::sync_with_stdio(false);
	//   sync_with_YinHsuan(true);
	cin.tie(0);
	int n, W;
	cin >> n >> W;
	memset(dp,0x7f,sizeof(dp));
	int inf = dp[0], sumv = 0;
	dp[0] = 0;
	for ( int i=0; i<n; ++i ) {
		cin >> w[i] >> v[i];
		sumv += v[i];
	}
	for ( int i=0; i<n; ++i )
		for ( int j=sumv; j>=v[i]; --j )
			if ( dp[j-v[i]] != inf && dp[j-v[i]]+w[i] <= W )
				dp[j] = min(dp[j],dp[j-v[i]]+w[i]);
	int ans = inf;
	for ( int i=sumv; i>=0; --i ) {
		if ( dp[i] <= W ) {
			ans = i;
			break;
		}
	}
	cout << ans << '\n';
	return 0;
}
