#include <iostream>
#include <algorithm>
#define maxn 10000005
#define logn 25
using namespace std;
int dp[logn]={1};
long long sp[logn][maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, q, l, r;
	cin >> n >> q;
	for ( int i=1; i<=n; ++i )	cin >> sp[0][i];
	for ( int i=1; i<logn; ++i )	dp[i] = dp[i-1]<<1;
	for ( int i=1; dp[i]<=n; ++i )
		for ( int j=1; j+dp[i-1]<=n; ++j )
			sp[i][j] = max(sp[i-1][j],sp[i-1][j+dp[i-1]]);
	while ( q-- && cin >> l >> r ) {
		if ( l > r )	swap(l,r);
		int k = upper_bound(dp,dp+logn,(r-l+1))-dp-1; // floor
		cout << max(sp[k][l],sp[k][r-dp[k]+1]) << '\n';;
	}
	return 0;
}

