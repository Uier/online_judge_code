#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int n, m, p[1010];
ll origin, after;
struct edge {
	int u, v;
	ll cost;
} G[2010];
bool cmp (edge x, edge y) {
	return x.cost < y.cost;
}
int find(int x) {
	return (p[x]==x) ? x : (p[x]=find(p[x]));
}
void mst() {
	for ( int i=0; i<n; i++ )	p[i] = i;
	for ( int i=0; i<m; i++ )
		if ( find(G[i].u) != find(G[i].v) ) {
			after += G[i].cost;
			p[find(G[i].v)] = find(G[i].u);
		}
}
int main() {
	  ios::sync_with_stdio(0);
	  cin.tie(0);
	cin >> n >> m;
	for ( int i=0; i<m; i++ ) {
		cin >> G[i].u >> G[i].v >> G[i].cost;
		if ( i < n-1 )
			origin += G[i].cost;
	}
	sort(G,G+m,cmp);
	mst();
	cout << origin-after << '\n';
	return 0;
}

