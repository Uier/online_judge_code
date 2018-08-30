#include <iostream>
#include <vector>
#include <string.h>
#define maxn 101
using namespace std;
int t, n, m, cnt;
bool G[maxn][maxn], ans[maxn], color[maxn];
// backtracking
void dfs(int x, int black) {
	// end
	if ( x > n ) {
		if ( black > cnt ) {
			cnt = black;
			for ( int i=1; i<=n; ++i )	ans[i] = color[i];
		}
		return;
	}
	// dfs
	for ( int i=1; i<=n; ++i )
		if ( G[x][i] && color[i] ) {
			// x has black neighbor, color white and return
			dfs(x+1,black);
			return;
		}
	// otherwise can color black, keep tracking
		// black case
	color[x] = 1;
	dfs(x+1,black+1);
		// white case
	color[x] = 0;
	dfs(x+1,black);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while ( t-- && cin >> n >> m ) {
		cnt = 0;
		memset(G,false,sizeof(G));
		memset(ans,false,sizeof(ans));
		memset(color,false,sizeof(color));
		for ( int i=0, x, y; i<m; ++i ) {
			cin >> x >> y;
			G[x][y] = G[y][x] = 1;
		}
		dfs(1,0);
		cout << cnt << '\n';
		for ( int i=1, j=1; i<=n; ++i )
			if ( ans[i] ) {
				cout << i;
				if ( j == cnt )	cout << '\n'; 
				else	cout << ' ';
				++j;
			}
	}
	return 0;
}

