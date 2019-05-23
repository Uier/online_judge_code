#include <iostream>
#include <string.h>
#define maxn 505
using namespace std;
int dp[maxn][maxn];
int main() {
	ios::sync_with_stdio(false);
	//   sync_with_YinHsuan(true);
	cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	memset(dp,0x3f,sizeof(dp));
	for ( int i=0; i<n; ++i )	dp[i][i] = 1;
	for ( int i=n-1; i>=0; --i )
		for ( int j=i+1; j<n; ++j ) {
			if ( s[i] == s[j] )
				dp[i][j] = min(dp[i+1][j],dp[i][j-1]);
			else {
				for ( int k=i; k<j; ++k )
					dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]);
			}
		}
	cout << dp[0][n-1] << '\n';
	return 0;
}

