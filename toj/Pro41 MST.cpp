#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, sum, p[1002];
struct edge {
	int u, v, cost;
} G[500002];
bool cmp(edge a, edge b) {
	return a.cost < b.cost;
}
int find(int x) {
	return (p[x]==x) ? x : (p[x]=find(p[x]));
}
int solve() {
	sort(G,G+m,cmp);
	for ( int i=0; i<n; i++ ) 	p[i] = i;
	for ( int i=0; i<m; i++ ) 
		if ( find(G[i].u) != find(G[i].v) ) {
			p[find(G[i].u)] = find(G[i].v);
			sum += G[i].cost;
		}
	for ( int i=1; i<n; i++ )
		if ( find(i) != p[0] )
			sum = -1;
	return sum;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for ( int i=0; i<m; i++ )
		cin >> G[i].u >> G[i].v >> G[i].cost;
	cout << solve() << '\n';
	return 0;
}

