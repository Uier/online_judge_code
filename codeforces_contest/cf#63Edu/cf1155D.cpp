#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#define int long long
#define maxn 300005
using namespace std;
int arr[maxn], dp[3][maxn];
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, x;
	cin >> n >> x;
	for ( int i=1; i<=n; ++i )	cin >> arr[i];
	int ans = 0;
	for ( int i=1; i<=n; ++i ) {
		dp[0][i] = max(dp[0][i-1]+arr[i], arr[i]);
		dp[1][i] = max(dp[0][i-1]+arr[i]*x, max(dp[1][i-1]+arr[i]*x, arr[i]*x)); 
		dp[2][i] = max(dp[1][i-1]+arr[i], max(dp[2][i-1]+arr[i], arr[i]));
		for ( int j=0; j<3; ++j )	ans = max(ans,dp[j][i]);
	}
	cout << ans << '\n';
	return 0;
}

