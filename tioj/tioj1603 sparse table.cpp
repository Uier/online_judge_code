#include <iostream>
#include <algorithm>
#define maxn 100005
using namespace std;
int n, q, dp[20], h[20][maxn], l[20][maxn], L, R;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	dp[0] = 1;
	for ( int i=1; i<20; ++i )	dp[i] = (dp[i-1]<<1);
	cin >> n >> q;
	long long x;
	for ( int i=0; i<n; ++i ) {
		cin >> x;
		h[0][i] = l[0][i] = x-1;
	}
	for ( int i=1; dp[i]<=n; ++i )
		for ( int j=0; j+dp[i]<=n; ++j ) {
			l[i][j] = min(l[i-1][j],l[i-1][j+dp[i-1]]);
			h[i][j] = max(h[i-1][j],h[i-1][j+dp[i-1]]);
		}
	while ( q-- ) {
		cin >> L >> R;
		L -= 1;	R -= 1;
		int k = upper_bound(dp,dp+20,(R-L+1))-dp-1;
		R = R-dp[k]+1;
		cout << max(h[k][L],h[k][R])-min(l[k][L],l[k][R]) << '\n';
	}
	return 0;
}

