#include <iostream>
#include <string.h>
using namespace std;
int dp[11][101], pt[11][101];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	while ( cin >> n >> m ) {
		for ( int i=0; i<n; i++ )
			for ( int j=0; j<m; j++ )
				cin >> dp[i][j];
		for ( int j=m-2; j>=0; j-- )
			for ( int i=0; i<n; i++ ) {
				int c1 = dp[(i-1+n)%n][j+1], c2 = dp[i][j+1], c3 = dp[(i+1)%n][j+1];
				int d1 = (i-1+n)%n, d2 = i, d3 = (i+1)%n;
				if ( c1 < c2 && c1 < c3 ) {
					dp[i][j] += c1;
					pt[i][j] = -1;
				} else if ( c2 < c1 && c2 < c3 ) {
					dp[i][j] += c2;
					pt[i][j] = 0;
				} else if ( c3 < c2 && c3 < c1 ) {
					dp[i][j] += c3;
					pt[i][j] = 1;
				} else if ( c1 == c2 && c1 < c3 ) {
					if ( d1 < d2 ) {
						dp[i][j] += c1;
						pt[i][j] = -1;
					} else {
						dp[i][j] += c2;
						pt[i][j] = 0;
					}
				} else if ( c2 == c3 && c2 < c1 ) {
					if ( d2 < d3 ) {
						dp[i][j] += c2;
						pt[i][j] = 0;
					} else {
						dp[i][j] += c3;
						pt[i][j] = 1;
					}
				} else if ( c1 == c3 && c1 < c2 ) {
					if ( d1 < d3 ) {
						dp[i][j] += c1;
						pt[i][j] = -1;
					} else {
						dp[i][j] += c3;
						pt[i][j] = 1;
					}
				} else if ( d1 <= d2 && d1 <= d3 ) {
					dp[i][j] += c1;
					pt[i][j] = -1;
				} else if ( d2 < d1 && d2 < d3 ) {
					dp[i][j] += c2;
					pt[i][j] = 0;
				} else if ( d3 < d1 && d3 < d2 ) {
					dp[i][j] += c3;
					pt[i][j] = 1;
				}
			}
		int ans = 1e9, path = -1, index = -1;
		for ( int i=0; i<n; i++ )
			if ( dp[i][0] < ans )
				ans = dp[i][0], path = i+1, index = i;
		for ( int i=0; i<m-1; i++ ) {
			cout << index+1 << ' ';
			index = (index+pt[index][i]+n)%n;
		}
		cout << index+1 << '\n' << ans << '\n';
	}
	return 0;
}

