#include <iostream>
#include <string.h>
#define maxn 105
#define maxv 100005
using namespace std;
typedef long long ll;
int w[maxn], p[maxn], dp[maxv];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, v;
	while ( cin >> v >> n ) {
		for ( int i=1; i<=n; ++i )
			cin >> w[i] >> p[i];
		memset(dp,0,sizeof dp);
		for ( int i=1; i<=n; ++i )
			for ( int j=w[i]; j<=v; ++j )
				dp[j] = max(dp[j],dp[j-w[i]]+p[i]);
		cout << dp[v] << '\n';
	}
	return 0;
}

