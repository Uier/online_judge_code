#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
int n, m, g[1505][1505];
bool a[1505][1505];
vector<pii> V;
bool cmp(pii x, pii y) {
	return ((x.first==y.first) ? (x.second<y.second) : (x.first<y.first));
}
void dfs(int x, int y) {
	if ( a[x][y] )	return;
	a[x][y] = true;
	V.push_back({y,x});
	if ( x+1 < n && g[x][y] <= g[x+1][y] )	dfs(x+1,y);
	if ( y+1 < m && g[x][y] <= g[x][y+1] )	dfs(x,y+1);
	if ( x-1 >-1 && g[x][y] <= g[x-1][y] )	dfs(x-1,y);
	if ( y-1 >-1 && g[x][y] <= g[x][y-1] )	dfs(x,y-1);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int s, t;
	cin >> n >> m;
	for ( int i=0; i<n; i++ )
		for ( int j=0; j<m; j++ )
			cin >> g[i][j];
	cin >> s >> t;
	dfs(t,s);
	sort(V.begin(),V.end(),cmp);
	for ( pii i : V )
		printf("(%d,%d)\n", i.first, i.second);
	return 0;
}

