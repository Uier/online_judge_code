#include <iostream>
#include <vector>
#define maxn 100005
#define logn 20
using namespace std;
int D[maxn], F[logn][maxn], dp[logn];
vector<int> G[maxn];
void dfs(int x, int dep) {
	D[x] = dep;
	for ( int i : G[x] )
		if ( !D[i] ) {
			F[0][i] = x;
			dfs(i,dep+1);
		}
}
inline int lca(int u, int v) {
	if ( D[u] < D[v] )	swap(u,v);
	for ( int i=logn-1; i>=0; --i )
		if ( F[i][u] != 0 && D[F[i][u]] >= D[v] )
			u = F[i][u];
	if ( u == v )	return u;
	for ( int i=logn-1; i>=0; --i )
		if ( F[i][u] != F[i][v] )
			u = F[i][u], v = F[i][v];
	return F[0][u];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, q, a, b, k;
	cin >> n >> q;
	for ( int i=1; i<n; ++i ) {
		cin >> a >> b;
		G[a].emplace_back(b);
		G[b].emplace_back(a);
	}
	dfs(1,1);
	for ( int i=1; i<logn; ++i )
		for ( int j=1; j<=n; ++j )
			if ( F[i-1][j] != 0 )
				F[i][j] = F[i-1][F[i-1][j]];
	dp[0] = 1;
	for ( int i=1; i<logn; ++i )	dp[i] = dp[i-1]<<1;
	while ( q-- && cin >> a >> b >> k ) {
		int m = lca(a,b);
		int l = D[a] - D[m], r = D[b] - D[m];
		if ( k > l+r )	cout << -1 << '\n';
		else {
			if ( k > l ) // over the lca
				k = l+r-k, a = b;
			for ( int i=logn-1; i>=0; --i )
				if ( dp[i] <= k )
					k -= dp[i], a = F[i][a];
			cout << a << '\n';
		}
	}
	return 0;
}

