#include <iostream>
#include <vector>
#define maxn 30005
#define logn 15
using namespace std;
int D[maxn], F[logn][maxn];
vector<int> G[maxn];
void dfs(int x, int dep) {
	D[x] = dep;
	for ( int i : G[x] ) {
		F[0][i] = x;
		dfs(i,dep+1);
	}
}
int LCA(int u, int v) {
	if ( D[u] < D[v] )	swap(u,v);
	for ( int i=logn-1; i>=0; --i )
		if ( F[i][u] && D[F[i][u]] >= D[v] )
			u = F[i][u];
	if ( u == v )	return u;
	for ( int i=logn-1; i>=0; --i )
		if ( F[i][u] != F[i][v] )
			u = F[i][u], v = F[i][v];
	return F[0][u];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q, x, a, b;
	cin >> n >> q;
	for ( int i=1; i<=n; ++i )
		while ( cin >> x && x )
			G[i].emplace_back(x);
	dfs(1,1);
	for ( int i=1; i<logn; ++i )
		for ( int j=1; j<=n; ++j )
			if ( F[i-1][j] )
				F[i][j] = F[i-1][F[i-1][j]];
	while ( q-- && cin >> a >> b ) {
		int lca = LCA(a,b);
		cout << lca << ' ' << D[b]-D[lca]+D[a]-D[lca] << '\n';
	}
	return 0;
}

