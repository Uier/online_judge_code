#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#define MM 100005
#define MN 1000005
using namespace std;
struct Edge {
	int u, v, cost;
} G[MN];
struct Node {
	int to, weight;
};
vector<Node> MST[MM];
int N, M, Q, a, b, root, F[20][MM], FM[20][MM], D[MM], P[MM];
bool cmp(Edge x, Edge y) {
	return x.cost > y.cost;
}
int find(int x) {
	return (P[x] == x) ? x : (P[x]=find(P[x]));
}
void U(int x, int y) {
	P[find(y)] = find(x);
}
void Kruskal() {
	sort(G,G+M,cmp);
	for ( int i=0; i<N; i++ )	P[i] = i;
	for ( int i=0; i<M; i++ )
		if ( find(G[i].u) != find(G[i].v) ) {
			U(G[i].u,G[i].v);
			MST[G[i].u].push_back(Node{G[i].v,G[i].cost});
			MST[G[i].v].push_back(Node{G[i].u,G[i].cost});
		}
}
void Build() {
	for ( int i=1; i<20; i++ )
		for ( int j=0; j<N; j++ )
			if ( F[i-1][j] != -1 ) {
				F[i][j] = F[i-1][F[i-1][j]];
				FM[i][j] = min(FM[i-1][j],FM[i-1][F[i-1][j]]);
			}
}
void DFS(int x, int y, int d) {
	D[x] = d;
	for ( Node i : MST[x] )
		if ( i.to != y ) {
			F[0][i.to] = x;
			FM[0][i.to] = i.weight;
			DFS(i.to,x,d+1);
		}
}
int LCA(int u, int v) {
	int ans = 1e9;
	if ( D[u] < D[v] )	swap(u,v);
	for ( int i=19; i>=0; i-- )
		if ( F[i][u] != -1 && D[F[i][u]] >= D[v] ) {
			ans = min(ans,FM[i][u]);
			u = F[i][u];
		}
	if ( u == v )	return ans;
	for ( int i=19; i>=0; i-- )
		if ( F[i][u] != F[i][v] ) {
			ans = min(ans,min(FM[i][u],FM[i][v]));
			u = F[i][u], v = F[i][v];
		}
	return min(ans,min(FM[0][u],FM[0][v]));
}
main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(F,-1,sizeof F);
	memset(FM,63,sizeof FM);
	cin >> N >> M;
	for ( int i=0; i<M; i++ )
		cin >> G[i].u >> G[i].v >> G[i].cost;
	Kruskal();
	DFS(0,0,0);
	Build();
	cin >> Q;
	while ( Q-- ) {
		cin >> a >> b;
		cout << LCA(a,b) << '\n';
	}
	return 0;
}

