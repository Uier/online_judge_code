#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int root, D[10005], P[10005][16], t, n, a, b;
vector<int> G[10005];
void init() {
	memset(G,false,sizeof G);
	memset(P,false,sizeof P);
	memset(D,false,sizeof D);
}
void Build() {
	for ( int j=1; j<16; j++ )
		for ( int i=1; i<=n; i++ )
			if ( P[i][j-1] != -1 )
				P[i][j] = P[P[i][j-1]][j-1];
}
void DFS(int x, int d) {
	D[x] = d;
	for ( int i : G[x] )
		DFS(i,d+1);
}
int LCA(int u, int v) {
	if ( D[u] < D[v] )	swap(u,v);
	for ( int i=15; i>=0; i-- )	// u goto the depth v is.;
		if ( P[u][i] != -1 && D[P[u][i]] >= D[v] )
			u = P[u][i];
	if ( u == v )	return u;	// if u and v, same depth, is same node.
	for ( int i=15; i>=0; i-- )
		if ( P[u][i] != P[v][i] )
			u = P[u][i], v = P[v][i];
	return P[u][0];
}
main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while ( t-- ) {
		init();
		cin >> n;
		for ( int i=0; i<n-1; i++ ) {
			cin >> a >> b;	//	b is a's child.
			G[a].push_back(b);
			P[b][0] = a;
		}
		Build();
		for ( int i=1; i<=n; i++ )
			if ( P[i][0] == -1 )
				root = i;
		DFS(root,0);
		cin >> a >> b;
		cout << LCA(a,b) << '\n';
	}
	return 0;
}

