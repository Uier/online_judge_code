#include <iostream>
#include <vector>
#include <string.h>
#define maxn 100005
using namespace std;
struct edge {
	int to, cost;
};
vector<edge> G[maxn], Q[maxn];	// Q'cost means number
int n, q, a, b, p[maxn], qu[maxn], qv[maxn], LCA[maxn];
long long D[maxn];
bool V[maxn];
int find(int x) {
	return ((p[x] == x) ? x : (p[x] = find(p[x])));
}
void dfs(int x) {
	p[x] = x;
	for ( edge i : G[x] ) {
		dfs(i.to);
		p[i.to] = x;
	}
	V[x] = true;
	for ( edge i : Q[x] )
		if ( V[i.to] )
			LCA[i.cost] = find(i.to);
}
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	while ( cin >> n && n ) {
		memset(V,0,sizeof V);
		memset(G,0,sizeof G);
		memset(Q,0,sizeof Q);
		memset(D,0,sizeof D);
		for ( int i=1; i<n; i++ ) {
			cin >> a >> b;
			G[a].push_back(edge{i,b});
		}
		cin >> q;
		for ( int i=0; i<q; i++ ) {
			cin >> qu[i] >> qv[i];
			Q[qu[i]].push_back(edge{qv[i],i});
			Q[qv[i]].push_back(edge{qu[i],i});
		}
		dfs(0);
		for ( int i=0; i<n; i++ )
			for ( edge j : G[i] )
				D[j.to] = D[i] + j.cost;
		for ( int i=0; i<q; i++ ) {
			if ( i )	cout << ' ';
			cout << D[qu[i]]+D[qv[i]]-D[LCA[i]]*2;
		}
		cout << '\n';
	}
	return 0;
}

