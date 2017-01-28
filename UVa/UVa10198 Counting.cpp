#include <iostream>
using namespace std;
long long dp[1001][1001];
int main()
{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	for ( int i=0; i<1001; i++ )
		for (int j=0; j<1001; j++ )
			dp[i][j] = 0;
	dp[1][0] = 2;
	dp[2][0] = 5;
	dp[3][0] = 3;	dp[3][1] = 1;
	dp[4][0] = 3;	dp[4][1] = 3;
	for ( int i=5; i<1001; i++ ) {
		for ( int j=0; j<1001; j++ )
			dp[i][j] = dp[i-1][j]+dp[i-2][j]+dp[i-3][j]+dp[i-1][j];
		for ( int j=0; j<1000; j++ ) {
			dp[i][j+1] += dp[i][j]/10;
			dp[i][j] %= 10;
		}
	}
	int n;
	while ( cin >> n ) {
		int i=1000;
		while ( dp[n][i]==0 )	i--;
		for ( ; i>=0; i-- )
			cout << dp[n][i];
		cout << '\n';
	}
	return 0;
}

