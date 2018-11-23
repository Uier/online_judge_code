#include <iostream>
#include <string.h>
using namespace std;
int n, g[10][10], ans;
bool u[105], v[10][10];
void dfs(int i, int j, int dep) {
	u[g[i][j]] = v[i][j] = true;
	ans = max(ans,dep);
	if ( i-1 >= 1 && !u[g[i-1][j]] && !v[i-1][j] )
		dfs(i-1,j,dep+1);
	if ( i+1 <= n && !u[g[i+1][j]] && !v[i+1][j] )
		dfs(i+1,j,dep+1);
	if ( j-1 >= 1 && !u[g[i][j-1]] && !v[i][j-1] )
		dfs(i,j-1,dep+1);
	if ( j+1 <= n && !u[g[i][j+1]] && !v[i][j+1] )
		dfs(i,j+1,dep+1);
	u[g[i][j]] = v[i][j] = false;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while ( t-- && cin >> n ) {
		for ( int i=1; i<=n; ++i )
			for ( int j=1; j<=n; ++j )
				cin >> g[i][j];
		ans = 0;
		for ( int i=1; i<=n; ++i )
			for ( int j=1; j<=n; ++j ) {
				memset(u,false,sizeof(u));
				memset(v,false,sizeof(v));
				dfs(i,j,1);
			}
		cout << ans << '\n';
	}
	return 0;
}

