#include <iostream>
using namespace std;
int w[100005], p[100005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int v, n;
	while ( cin >> v >> n ) {
		for ( int i=0; i<n; i++ )	cin >> w[i] >> p[i];
		int dp[v+1];
		for ( int i=0; i<v+1; i++ )	dp[i] = 0;
		for ( int i=0; i<n; i++ )
			for ( int j=w[i]; j<=v; j++ )
				dp[j] = max(dp[j],dp[j-w[i]]+p[i]);
		cout << dp[v] << '\n';
	}
	return 0;
}

