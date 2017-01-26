#include <iostream>
#include <math.h>
using namespace std;
int dp[5005][5005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, c;	// in, del, re
	string s, t;
	cin >> a >> b >> c >> s >> t;
	dp[0][0] = 0;
	for ( int i=1; i<=s.size(); i++ )	dp[i][0] = b*i;
	for ( int i=1; i<=t.size(); i++ )	dp[0][i] = a*i;
	for ( int i=1; i<=s.size(); i++ )
		for ( int j=1; j<=t.size(); j++ )
			if ( s[i-1] == t[j-1] )
				dp[i][j] = dp[i-1][j-1];
			else {
				dp[i][j] = 2147483647;
				dp[i][j] = min(dp[i-1][j]+b,dp[i][j-1]+a);
				int dist = abs(s[i-1]-t[j-1]);
				dist = min(dist,26-dist);	// reserve
				dp[i][j] = min(dp[i][j],dp[i-1][j-1]+dist*c);
			}
//	for ( int i=0; i<=s.size(); i++ ) {
//		for ( int j=0; j<=t.size(); j++ )
//			cout << dp[i][j] << ' ';
//		cout << '\n';
//	}
	cout << dp[s.size()][t.size()] << '\n';
	return 0;
}

