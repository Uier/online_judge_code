#include <iostream>
#include <vector>
#include <algorithm>
#define maxn 1000005
#define maxm 3000005
using namespace std;
struct tree {
	int u, v, cost;
} T[maxm];
bool cmp(tree x, tree y) {
	return x.cost < y.cost;
}
struct edge {
	int to, cost;
};
vector<edge> G[maxn];
int p[maxn];
long long D[maxn];
int find(int x) {
	return (p[x] == x ? x : (p[x] = find(p[x])));
}
void dfs(int x, int fa) {
	for ( edge i : G[x] )
		if ( i.to != fa ) {
			D[i.to] = D[x]+i.cost;
			dfs(i.to,x);
		}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for ( int i=0; i<n; ++i )	p[i] = i;
	for ( int i=0; i<m; ++i )	cin >> T[i].u >> T[i].v >> T[i].cost;
	sort(T,T+m,cmp);
	for ( int i=0; i<m; ++i )
		if ( find(T[i].u) != find(T[i].v) )	{
			p[find(T[i].u)] = find(T[i].v);
			G[T[i].u].emplace_back(edge{T[i].v,T[i].cost});
			G[T[i].v].emplace_back(edge{T[i].u,T[i].cost});
		}
	dfs(0,0);
	int pt = 0;
	for ( int i=1; i<n; ++i )
		if ( D[i] > D[pt] )
			pt = i;
	D[pt] = 0;
	dfs(pt,pt);
	for ( int i=0; i<n; ++i )
		if ( D[i] > D[pt] )
			pt = i;
	cout << D[pt] << '\n';
	return 0;
}

