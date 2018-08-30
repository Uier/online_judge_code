#include <iostream>
#define maxn 51
using namespace std;
int n, ans;
bool G[maxn][maxn], vis[maxn];
/*

TLE TLE TLE
TLE TLE TLE
TLE TLE TLE
TLE TLE TLE
TLE TLE TLE
TLE TLE TLE
TLE TLE TLE
TLE TLE TLE

*/
void dfs(int x, int sel) {
	if ( x == n ) {
		ans = max(ans,sel);
		return;
	}
	for ( int i=0; i<n; ++i )
		if ( G[x][i] && vis[i] ) {
			dfs(x+1,sel);
			return;
		}
	vis[x] = true;
	dfs(x+1,sel+1);
	vis[x] = false;
	dfs(x+1,sel);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while ( cin >> n && n ) {
		for ( int i=0; i<n; ++i )
			for ( int j=0; j<n; ++j ) {
				cin >> G[i][j];
				G[i][j] ^= 1;
				G[j][i] = G[i][j];
			}
		for ( int i=0; i<n; ++i )	G[i][i] = vis[i] = false;
		ans = 0;
		dfs(0,0);
		cout << ans << '\n';
	}
	return 0;
}

