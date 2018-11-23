#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#define maxn 100005
#define logn 20
#define int long long
using namespace std;
struct edge {
	int u, v, cost;
} T[maxn];
struct tree {
	int to, cost;
};
inline bool cmp(edge x, edge y) {
	return x.cost < y.cost;
}
int dep[maxn], dist[maxn], F[logn][maxn], p[maxn];
vector<edge> unused;
vector<tree> G[maxn];
int find(int x) {
	return (p[x]==x ? x : (p[x]=find(p[x])));
}
void dfs(int x) {
	for ( tree i : G[x] )
		if ( i.to != F[0][x] ) {
			dep[i.to] = dep[x]+1;
			dist[i.to] = dist[x]+i.cost;
			F[0][i.to] = x;
			dfs(i.to);
		}
}
inline int LCA(int u, int v) {
	if ( dep[u] < dep[v] )	swap(u,v);
	for ( int i=logn-1; i>=0; --i )
		if ( F[i][u] != -1 && dep[F[i][u]] >= dep[v] )
			u = F[i][u];
	if ( u == v )	return u;
	for ( int i=logn-1; i>=0; --i )
		if ( F[i][u] != F[i][v] )
			u = F[i][u], v = F[i][v];
	return F[0][u];
}
inline int getdist(int u, int v) {
	int lca = LCA(u,v);
	return dist[u]+dist[v]-dist[lca]*2;
}
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	memset(F,-1,sizeof(F));
	for ( int i=1; i<=n; ++i )	p[i] = i;
	for ( int i=0; i<m; ++i )	cin >> T[i].u >> T[i].v >> T[i].cost;
	sort(T,T+m,cmp);
	for ( int i=0; i<m; ++i ) {
		int u = T[i].u, v = T[i].v, cost = T[i].cost;
		int pu = find(u), pv = find(T[i].v);
		if ( pu == pv ) {
			unused.emplace_back(T[i]);
			continue;
		}
		G[u].emplace_back(tree{v,cost});
		G[v].emplace_back(tree{u,cost});
		p[pu] = pv;
	}
	dfs(1);
	for ( int i=1; i<logn; ++i )
		for ( int j=1; j<=n; ++j )
			if ( F[i-1][j] != -1 )
				F[i][j] = F[i-1][F[i-1][j]];
	int q, u, v;
	cin >> q;
	while ( q-- && cin >> u >> v ) {
		int ans = getdist(u,v);
		for ( edge i : unused ) {
			ans = min(ans,getdist(u,i.u)+getdist(v,i.v)+i.cost);
			ans = min(ans,getdist(v,i.u)+getdist(u,i.v)+i.cost);
		}
		cout << ans << '\n';
	}
	return 0;
}

