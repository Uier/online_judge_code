#include <iostream>
#include <vector>
#include <string.h>
#define maxn 10005
using namespace std;
vector<int> G[maxn], A, B;
int D[maxn], F[15][maxn];
void dfs(int x, int fa, int dep) {
	D[x] = dep;
	for ( int i : G[x] )
		if ( i != fa ) {
			F[0][i] = x;
			dfs(i,x,dep+1);
		}
}
int lca(int u, int v) {
	for ( int i=14; i>=0; --i )
		if ( D[F[i][u]] != -1 && D[F[i][u]] >= D[v] )
			u = F[i][u];
	if ( u == v )	return u;
	for ( int i=14; i>=0; --i )
		if ( F[i][u] != F[i][v] )
			u = F[i][u], v = F[i][v];
	return F[0][u];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q, a, b, c;
	cin >> n >> q;
	for ( int i=1; i<n; ++i ) {
		cin >> a >> b;
		G[a].emplace_back(b);
		G[b].emplace_back(a);
	}
	memset(F,-1,sizeof(F));
	dfs(0,-1,1);
	for ( int i=1; i<15; ++i )
		for ( int j=0; j<n; ++j )
			if ( F[i-1][j] != -1 )
				F[i][j] = F[i-1][F[i-1][j]];
	while ( q-- ) {
		cin >> a >> b;
		if ( D[a] < D[b] )	swap(a,b);
		if ( a == b )	cout << a << '\n';
		else if ( F[0][a] == b )
			cout << min(a,b) << ' ' << max(a,b) << '\n';
		else {
			int ans = lca(a,b), c = a;
			int dist = D[a]+D[b]-D[ans]*2;
			for ( int i=14; i>=0; i-- )
				if ( F[i][a] != -1 && D[F[i][a]] >= D[c]-dist/2 )
					a = F[i][a];
			if ( dist%2 == 0 )	cout << a << '\n';
			else cout << min(a,F[0][a]) << ' ' << max(a,F[0][a]) << '\n';
		}
	}
	return 0;
}

