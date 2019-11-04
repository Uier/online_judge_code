#include <iostream>
#define maxn 100005
#define int long long
using namespace std;
int n, arr[2][maxn], dp[2][maxn];
int32_t main() {
	cin >> n;
	for ( int i=0; i<2; ++i )
		for ( int j=1; j<=n; ++j )
			cin >> arr[i][j];
	dp[0][0] = dp[1][0] = 0;
	for ( int i=1; i<=n; ++i )
		for ( int j=0; j<2; ++j )
			dp[j][i] = max(dp[j][i-1],dp[j^1][i-1]+arr[j][i]);
	cout << max(dp[0][n],dp[1][n]) << '\n';
	return 0;
}