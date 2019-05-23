#include <iostream>
#include <string.h>
#define maxn 15
#define int long long
using namespace std;
int dp[2][1<<maxn], G[maxn][maxn];
main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n, m, cs = 1;
	cin >> t;
	while ( t-- && cin >> n >> m ) {
		if ( n < m )	swap(n,m);
		memset(G,0,sizeof(G));
		memset(dp,0,sizeof(dp));
		for ( int i=1; i<=n; ++i )	for ( int j=1; j<=m; ++j )	cin >> G[i][j];
		int p = (1<<m+1), pre = 0, cur = 1;
		dp[pre][0] = 1;
		for ( int i=1; i<=n; ++i ) {
			for ( int j=0; j<=m; ++j, pre^=1, cur^=1 ) {
				memset(dp[cur],0,sizeof(dp[cur]));
				if ( j == 0 ) {
					for ( int k=0; k<p; ++k )
						dp[cur][k>>1] = (dp[cur][k>>1]+dp[pre][k]);
				} else if ( !G[i][j] ) {
					// 00 -> 00
					for ( int k=0; k<p; ++k )
						if ( !(k&(1<<m-j+1)) && !(k&(1<<m-j)) )
							dp[cur][k] = (dp[cur][k]+dp[pre][k]);
				} else {
					for ( int k=0; k<p; ++k ) {
						// -- 10 -> 01
						if ( G[i][j-1] && G[i][j+1] && (k&(1<<m-j+1)) && !(k&(1<<m-j)) )
							dp[cur][k^(1<<m-j+1)^(1<<m-j)] = (dp[cur][k^(1<<m-j+1)^(1<<m-j)]+dp[pre][k]);
						// _| 11 -> 00
						if ( G[i-1][j] && G[i][j-1] && (k&(1<<m-j+1)) && (k&(1<<m-j)) )
							dp[cur][k^(1<<m-j+1)^(1<<m-j)] = (dp[cur][k^(1<<m-j+1)^(1<<m-j)]+dp[pre][k]);
						// ¡Â|10 -> 10
						if ( G[i+1][j] && G[i][j-1] && (k&(1<<m-j+1)) && !(k&(1<<m-j)) )
							dp[cur][k] = (dp[cur][k]+dp[pre][k]);
						// |_ 01 -> 01
						if ( G[i-1][j] && G[i][j+1] && !(k&(1<<m-j+1)) && (k&(1<<m-j)) )
							dp[cur][k] = (dp[cur][k]+dp[pre][k]);
						// |¡Â00 -> 11
						if ( G[i+1][j] && G[i][j+1] && !(k&(1<<m-j+1)) && !(k&(1<<m-j)) )
							dp[cur][k|(1<<m-j+1)|(1<<m-j)] = (dp[cur][k|(1<<m-j+1)|(1<<m-j)]+dp[pre][k]);
						// |  01 -> 10
						if ( G[i-1][j] && G[i+1][j] && !(k&(1<<m-j+1)) && (k&(1<<m-j)) )
							dp[cur][k^(1<<m-j+1)^(1<<m-j)] = (dp[cur][k^(1<<m-j+1)^(1<<m-j)]+dp[pre][k]);
					}
				}
			}
		}
		cout << "Case " << cs++ << ": There are " << dp[pre][0] << " ways to eat the trees.\n";
	}
	return 0;
}

