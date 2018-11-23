#include <iostream>
#define maxn 5005
using namespace std;
int f[maxn][maxn], dp[maxn][maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n;
	for ( int i=1; i<=n; ++i )	cin >> f[i][1], dp[i][1] = f[i][1];
	for ( int i=2; i<=n; ++i )
		for ( int j=1; j+i-1<=n; ++j )
			dp[j][i] = max(f[j][i]=f[j][i-1]^f[j+1][i-1],max(dp[j][i-1],dp[j+1][i-1]));
	cin >> q;
	int l, r;
	while ( q-- && cin >> l >> r )	cout << dp[l][r-l+1] << '\n';
	return 0;
}

