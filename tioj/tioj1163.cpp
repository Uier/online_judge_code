#include <iostream>
#include <vector>
#include <algorithm>
#define maxn 30005
using namespace std;
struct mst {
	int u, v, cost;
} T[50005];
struct edge {
	int to, cost;
};
bool cmp(mst x, mst y) {
	return x.cost < y.cost;
}
vector<edge> G[maxn];
int D[maxn], F[16][maxn], P[16][maxn], pa[maxn], city, C[maxn];
int find(int x)	{
	return ((pa[x]==x) ? x : pa[x]=find(pa[x]));
}
void dfs(int x, int fa, int dep) {
	C[x] = city;
	D[x] = dep;
	for ( edge i : G[x] )
		if ( i.to != fa ) {
			F[0][i.to] = x;
			P[0][i.to] = i.cost;
			dfs(i.to,x,dep+1);
		}
}
int lca(int x, int y) {
	if ( D[x] < D[y] )	swap(x,y);
	int maxpath = 0;
	for ( int i=15; i>=0; --i )
		if ( F[i][x] != 0 && D[F[i][x]] >= D[y] ) {
			maxpath = max(maxpath,P[i][x]);
			x = F[i][x];
		}
	if ( x == y )	return maxpath;
	for ( int i=15; i>=0; --i )
		if ( F[i][x] != F[i][y] ) {
			maxpath = max(maxpath,max(P[i][x],P[i][y]));
			x = F[i][x], y = F[i][y];
		}
	return max(maxpath,max(P[0][x],P[0][y]));
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, q, a, b;
	cin >> n >> m;
	for ( int i=0; i<m; ++i )	cin >> T[i].u >> T[i].v >> T[i].cost;
	for ( int i=1; i<=n; ++i )	pa[i] = i;
	sort(T,T+m,cmp);
	for ( int i=0; i<m; ++i ) {
		if ( find(T[i].u) != find(T[i].v) )	{
			pa[find(T[i].v)] = find(T[i].u);
			G[T[i].u].emplace_back(edge{T[i].v,T[i].cost});
			G[T[i].v].emplace_back(edge{T[i].u,T[i].cost});
		}
	}
	for ( int i=1; i<=n; ++i, ++city )
		if ( D[i] == 0 )
			dfs(i,0,1);
	for ( int i=1; i<16; ++i )
		for ( int j=1; j<=n; ++j )
			if ( F[i-1][j] != 0 ) {
				F[i][j] = F[i-1][F[i-1][j]];
				P[i][j] = max(P[i-1][j],P[i-1][F[i-1][j]]);
			}
	cin >> q;
	while ( q-- && cin >> a >> b ) {
		if ( C[a] != C[b] )	cout << -1 << '\n';
		else if ( a == b )	cout << 0 << '\n';
		else	cout << lca(a,b) << '\n';
	}
	return 0;
}
