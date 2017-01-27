#include <iostream>
using namespace std;
int m, n, ans;
char G[105][105];
void dfs(int i, int j) {
	G[i][j] = '*';
	if ( i-1 >= 0 && G[i-1][j] == '@' )	dfs(i-1,j);
	if ( j-1 >= 0 && G[i][j-1] == '@' )	dfs(i,j-1);
	if ( i+1 < m && G[i+1][j] == '@' )	dfs(i+1,j);
	if ( j+1 < n && G[i][j+1] == '@' )	dfs(i,j+1);
	if ( i-1 >= 0 && j-1 >= 0 && G[i-1][j-1] == '@' )	dfs(i-1,j-1);
	if ( i-1 >= 0 && j+1 < n && G[i-1][j+1] == '@' )	dfs(i-1,j+1);
	if ( i+1 < m && j-1 >= 0 && G[i+1][j-1] == '@' )	dfs(i+1,j-1);
	if ( i+1 < m && j+1 < n && G[i+1][j+1] == '@' )		dfs(i+1,j+1);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while ( cin >> m >> n && m ) {
		for ( int i=0; i<m; i++ )
			for ( int j=0; j<n; j++ )
				cin >> G[i][j];
		int ans = 0;
		for ( int i=0; i<m; i++ )
			for ( int j=0; j<n; j++ )
				if ( G[i][j] == '@' ) {
					dfs(i,j);
					ans++;
				}
		cout << ans << '\n';
	}
	return 0;
}

