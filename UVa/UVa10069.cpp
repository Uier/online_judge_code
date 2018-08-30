#include <iostream>
#include <string.h>
#define dig 101
using namespace std;
long long dp[2][10005][dig];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	string x, z;
	cin >> t;
	while ( t-- && cin >> x >> z ) {
		int cur = 0, pre = 1;
		memset(dp,0,sizeof(dp));
		for ( int i=0; i<=x.size(); ++i )	dp[pre][i][0] = 1;
		for ( int i=1; i<=z.size(); ++i, cur^=1, pre^=1 ) {
			for ( int j=0; j<dig; ++j ) dp[cur][0][j] = 0;
			for ( int j=1; j<=x.size(); ++j ) {
				if ( z[i-1] == x[j-1] ) {
					for ( int k=0; k<dig; ++k )
						dp[cur][j][k] = dp[pre][j-1][k];
					int tmp = 0, carry = 0;
					for ( int k=0; k<dig; ++k ) {
						tmp = dp[cur][j][k]+dp[cur][j-1][k]+carry;
						carry = tmp/10;
						dp[cur][j][k] = tmp%10;
					}
				} else {
					for ( int k=0; k<dig; ++k )
						dp[cur][j][k] = dp[cur][j-1][k];
				}
			}
		}
		int pt = dig-1;
		while ( dp[pre][x.size()][pt] == 0 )	pt--;
		for ( int i=pt; i>=0; --i )	cout << dp[pre][x.size()][i];
		cout << '\n';
	}
	return 0;
}
