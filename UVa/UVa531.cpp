#include <iostream>
#include <string.h>
using namespace std;
string a[105], b[105], ans[105];
int dp[105][105];
int st[105][105];
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	string s;
	while ( true ) {
		int x = 1, y = 1, z = 0;
		while ( cin >> s && s != "#" )	a[x++] = s;
		while ( cin >> s && s != "#" )	b[y++] = s;
		if ( x == 1 || y == 1 )	break;
		memset(dp,0,sizeof dp);
		for ( int i=1; i<x; i++ )
			for ( int j=1; j<y; j++ )
				if ( a[i] == b[j] ) {
					dp[i][j] = dp[i-1][j-1] + 1;
					st[i][j] = 0;
				}
				else if ( dp[i-1][j] > dp[i][j-1] ) {
					dp[i][j] = dp[i-1][j];
					st[i][j] = 1;	// 1 == up;
				}
				else {
					dp[i][j] = dp[i][j-1];
					st[i][j] = -1;	// -1 == left;
				}
		x--;	y--;
		while ( x && y ) {
			if ( !st[x][y] ) {
				ans[z++] = a[x];
				x--;	y--;
			}
			else if ( st[x][y] > 0 )
				x--;
			else
				y--;
		}
		for ( int i=z-1; i>=0; i-- )
			cout << ans[i] << ((i==0) ? '\n' : ' ');
	}
	return 0;
}

