#include <iostream>
#define maxn 700001
using namespace std;
bool dp[2][maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	dp[0][0] = 1;
	for ( int i=0, x; i<n; ++i ) {
		cin >> x;
		for ( int j=0; j<maxn; ++j ) {
			if ( dp[0][j] ) {
				if ( j+x >= maxn )	dp[1][j+x-maxn+1] = 1;
				else	dp[1][j+x] = 1;
			}
		}
		for ( int j=0; j<maxn; ++j )	dp[0][j] |= dp[1][j];
	}
	for ( int i=maxn-1; i>=0; --i )
		if ( dp[0][i] ) {
			cout << i << '\n';
			return 0;
		}
}

