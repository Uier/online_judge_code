#include <iostream>
#include <string.h>
using namespace std;
int dp[11][10][10];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	for ( int i=1; i<=9; ++i )	dp[1][i][i] = 1;
	for ( int i=2; i<=10; ++i )
		for ( int j=0; j<=9; ++j ) {
			if ( i == 2 & j == 0 )	continue;
			for ( int k=0; k<=9; ++k )
				dp[i][k][k] += dp[i-1][j][k]+1;
		}
	while ( cin >> n >> k ) {
		int ans = 0, dig = 0, m = n;
		while ( m-- ) {
			m /= 10;
			dig++;
		}
		for ( int i=1; i<dig; ++i )
			for ( int j=0; j<=9; ++j )
				ans += dp[i][j][k];
		
		cout << ans << '\n';
	}
	return 0;
}

