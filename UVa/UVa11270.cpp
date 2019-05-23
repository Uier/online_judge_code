#include <iostream>
#include <string.h>
using namespace std;
long long dp[2][1050];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	while ( cin >> n >> m ) {
		if ( !n || !m )	{
			cout << 0 << '\n';
			continue;
		}
		if ( n < m )	swap(n,m);
		int p = 1<<m;
		dp[0][p-1] = 1;
		int pre = 0, cur = 1;
		for ( int i=0; i<n; ++i )
			for ( int j=0; j<m; ++j, pre^=1, cur^=1 ) {
				memset(dp[cur], 0, sizeof(dp[cur]));
				for ( int k=0; k<p; ++k ) {
					if ( (k<<1)&(1<<m) ) // blank
						dp[cur][(k<<1)^(1<<m)] += dp[pre][k];
					if ( i && !((k<<1)&(1<<m)) ) // ver.
						dp[cur][(k<<1)|1] += dp[pre][k];
					if ( j && !(k&1) && ((k<<1)&(1<<m)) ) // hor.
						dp[cur][(k<<1)^(1<<m)^3] += dp[pre][k];
				}
			}
		cout << dp[pre][p-1] << '\n';
	}
	return 0;
}

