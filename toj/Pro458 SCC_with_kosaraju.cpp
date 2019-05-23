#include <iostream>
#include <vector>
#include <string.h>
#define maxn 1005
#define maxp 1000005
using namespace std;
int n, m, G[maxn][maxn], dx[] = {-1,1,0,0,-1,-1,1,1}, dy[] = {0,0,-1,1,-1,1,-1,1};
vector<int> T[2][maxp], bomb, fini;
bool vis[maxp];
int scc[maxp], inedge[maxp];
void make_edge(int tx, int ty) {
	int st = 0, ed = 8;
	if ( G[tx][ty] == 1	)	ed = 4;
	else if ( G[tx][ty] == 2 )	st = 4;
	for ( int i=st; i<ed; ++i ) {
		int x = tx+dx[i], y = ty+dy[i];
		if ( x >= 0 && y >= 0 && x < n && y < m && G[x][y] ) {
			T[0][tx*1000+ty].emplace_back(x*1000+y);
			T[1][x*1000+y].emplace_back(tx*1000+ty);
		}
	}
}
void dfs1(int x) {
	vis[x] = true;
	for ( int i : T[0][x] )
		if ( !vis[i] )
			dfs1(i);
	fini.emplace_back(x);
}
void dfs2(int x, int cnt) {
	vis[x] = true;
	for ( int i : T[1][x] )
		if ( !vis[i] )
			dfs2(i,cnt);
	scc[x] = cnt;
}
main() {
	ios::sync_with_stdio(false);
	//   sync_with_YinHsuan(true);
	cin.tie(0);
	cin >> n >> m;
	for ( int i=0; i<n; ++i )
		for ( int j=0; j<m; ++j )
			cin >> G[i][j];
	for ( int i=0; i<n; ++i )
		for ( int j=0; j<m; ++j )
			if ( G[i][j] ) {
				make_edge(i,j);
				bomb.emplace_back(i*1000+j);
			}
	for ( int i : bomb )
		if ( !vis[i] )
			dfs1(i);
	memset(vis,0,sizeof(vis));
	int sz = fini.size(), cnt = 0, ans = 0;
	for ( int i=sz-1; i>=0; --i )
		if ( !vis[fini[i]] )
			dfs2(fini[i],cnt++);
	for ( int i : bomb )
		for ( int j : T[0][i] )
			if ( scc[i] != scc[j] )
				inedge[scc[j]]++;
	for ( int i=0; i<cnt; ++i )	if ( !inedge[i] )	ans++;
	cout << ans << '\n';
	return 0;
}

