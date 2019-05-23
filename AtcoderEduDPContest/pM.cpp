#include <iostream>
#define maxn 101
#define maxk 100001
#define int long long
using namespace std;
const int mod = 1000000007;
int arr[maxn], dp[maxn][maxk], pre[maxn][maxk];
main() {
	ios::sync_with_stdio(false);
	//   sync_with_YinHsuan(true);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for ( int i=1; i<=n; ++i )	cin >> arr[i];
	dp[0][0] = pre[0][0] = 1;
	for ( int i=1; i<=k; ++i )	pre[0][i] = 1; // dp[0][i] = 0
	for ( int i=1; i<=n; ++i ) {
		dp[i][0] = pre[i][0] = pre[i-1][0];
		for ( int j=1; j<=arr[i]; ++j ) {
			dp[i][j] = pre[i-1][j];
			pre[i][j] = (pre[i][j-1] + dp[i][j])%mod;
		}
		for ( int j=arr[i]+1; j<=k; ++j ) {
			dp[i][j] = (pre[i-1][j] - pre[i-1][j-arr[i]-1] + mod)%mod;
			pre[i][j] = (pre[i][j-1] + dp[i][j])%mod;
		}
	}
	cout << dp[n][k] << '\n';
	return 0;
}
