#include <iostream>
#include <algorithm>
#define maxn 101
#define int long long
using namespace std;
int n, m, b, inf = 9e18, dp[1<<20];
struct fri {
	int cost, moni, mask;
} arr[maxn];
main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> b;
	m = 1<<m;
	fill(dp+1,dp+m,inf);
	for ( int i=0, x; i<n; ++i ) {
		cin >> arr[i].cost >> arr[i].moni >> x;
		int mask = 0;
		for ( int j=0, y; j<x; ++j ) {
			cin >> y;
			mask += 1<<y-1;
		}
		arr[i].mask = mask;
	}
	sort(arr,arr+n,[](fri x, fri y){return x.moni < y.moni;});
	int ans = -1;
	for ( int i=0; i<n; ++i ) {
		for ( int j=0; j<m; ++j )
			if ( (~j)&arr[i].mask ) {
				int mask = ((~j)&arr[i].mask)|j;
				if ( dp[j] + arr[i].cost < dp[mask] )
					dp[mask] = dp[j] + arr[i].cost;
			}
		if ( dp[m-1] < inf && (dp[m-1] + arr[i].moni*b < ans || ans == -1) ) 
			ans = dp[m-1] + arr[i].moni*b;
	}
	if ( ans >= inf )	cout << -1 << '\n';
	else	cout << ans << '\n';
	return 0;
}
