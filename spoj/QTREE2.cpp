#include <iostream>
#include <vector>
#include <string.h>
#define maxn 10005
#define logn 14
using namespace std;
struct edge {
	int to, cost;
};
int D[maxn], Dist[maxn], F[logn][maxn], dp[logn] = {1};
vector<edge> G[maxn];
void dfs(int x, int dep) {
	D[x] = dep;
	for ( edge i : G[x] )
		if ( !D[i.to] ) {
			F[0][i.to] = x;
			Dist[i.to] = Dist[x] + i.cost;
			dfs(i.to,dep+1);
		}
}
int lca(int u, int v) {
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
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n, a, b, c;
	string s;
	for ( int i=1; i<logn; ++i )	dp[i] = dp[i-1]<<1;
	cin >> t;
	while ( t-- && cin >> n ) {
		memset(D,0,sizeof(D));
		memset(F,0,sizeof(F));
		for ( int i=1; i<=n; ++i )	G[i].clear();
		for ( int i=1; i<n; ++i ) {
			cin >> a >> b >> c;
			G[a].emplace_back(edge{b,c});
			G[b].emplace_back(edge{a,c});
		}
		dfs(1,1);
		for ( int i=1; i<logn; ++i )
			for ( int j=1; j<=n; ++j )
				if ( F[i-1][j] )
					F[i][j] = F[i-1][F[i-1][j]];
		while ( cin >> s && s != "DONE" && cin >> a >> b ) {
			int LCA = lca(a,b);
			if ( s[0] == 'D' )	cout << Dist[a]+Dist[b]-(Dist[LCA]*2) << '\n';
			else {
				cin >> c;
				int l = D[a]-D[LCA]+1, r = D[b]-D[LCA]+1;
				if ( c > l )	c = l+r-c, swap(a,b);
				for ( int i=logn-1; i>=0; --i )
					if ( dp[i] <= c-1 )
						a = F[i][a], c -= dp[i];
				cout << a << '\n';
			}
		}
		cout << '\n';
	}
	return 0;
}

