#include <iostream>
#include <string.h>
using namespace std;
int dp[105][105], x = 1;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a, b;
	while ( getline(cin,a) && a != "#" ) {
		getline(cin,b);
		memset(dp,0,sizeof dp);
		for ( int i=1; i<=a.size(); i++ )
			for ( int j=1; j<=b.size(); j++ ) {
				if ( a[i-1] == b[j-1] )
					dp[i][j] = dp[i-1][j-1] + 1;
				else
					dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
			}
		printf("Case #%d: you can visit at most %d cities.\n",x++,dp[a.size()][b.size()]);
	}
	return 0;
}

