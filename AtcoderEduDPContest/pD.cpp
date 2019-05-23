#include <iostream>
#define int long long
#define maxn 101
#define maxw 100005
using namespace std;
int w[maxn], v[maxn], dp[maxw];
main() {
	ios::sync_with_stdio(false);
	//   sync_with_YinHsuan(true);
	cin.tie(0);
	int n, W;
	cin >> n >> W;
	for ( int i=0; i<n; ++i )	cin >> w[i] >> v[i];
	for ( int i=0; i<n; ++i )
		for ( int j=W; j>=w[i]; --j )
			dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
	cout << dp[W] << '\n';
	return 0;
}

