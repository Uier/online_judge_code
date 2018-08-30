#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int x[41], y[41], dp[301][301];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, s;
	cin >> n;
	while ( n-- && cin >> m >> s ) {
		memset(dp,0x3f,sizeof(dp));
		int inf = dp[0][0];
		dp[0][0] = 0;
		for ( int i=1; i<=m; ++i )	cin >> x[i] >> y[i];
		for ( int i=1; i<=m; ++i )
			for ( int j=0; j+x[i]<=s; ++j )
				for ( int k=0; (j+x[i])*(j+x[i])+(k+y[i])*(k+y[i])<=s*s; ++k )
					if ( dp[j][k] != inf || dp[j+x[i]][k+y[i]] != inf )
						dp[j+x[i]][k+y[i]] = min(dp[j][k]+1,dp[j+x[i]][k+y[i]]);
		int ans = 1e9;
		for ( int i=0; i<=s; ++i ) {
			double de = sqrt(s*s-i*i);
			if ( (int)de == de )	ans = min(ans,dp[i][(int)de]);
		}
		if ( ans == 1e9 )	cout << "not possible\n";
		else	cout << ans << '\n';
	} 
	return 0;
}

