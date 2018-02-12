#include <iostream>
#define maxn 3405
#define maxv 12885
using namespace std;
int w[maxn], p[maxn], dp[maxv];
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n, v;
	cin >> n >> v;
	for ( int i=1; i<=n; ++i )
		cin >> w[i] >> p[i];
	for ( int i=1; i<=n; ++i )
		for ( int j=v; j>=w[i]; --j )
			dp[j] = max(dp[j],dp[j-w[i]]+p[i]);
	cout << dp[v] << '\n';
	return 0;
}

