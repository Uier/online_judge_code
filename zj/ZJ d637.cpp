#include <iostream>
using namespace std;
int w[10005], p[10005], dp[105];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, v = 100;
	cin >> n;
	for ( int i=1; i<=n; ++i )
		cin >> w[i] >> p[i];
	for ( int i=1; i<=n; ++i )
		for ( int j=v; j>=w[i]; --j )
			dp[j] = max(dp[j],dp[j-w[i]]+p[i]);
	cout << dp[v] << '\n';
	return 0;
}

