#include <iostream>
#include <algorithm>
#define maxn 5005
#define maxm 100005
using namespace std;
int p[maxn], pt = 1;
struct tree {
	int u, v, cost;
} T[maxm];
inline bool cmp(tree x, tree y) {
	return x.cost < y.cost;
}
int find(int x) {
	return (p[x]==x ? x : (p[x]=find(p[x])));
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for ( int i=1; i<=n; ++i )	p[i] = i;
	for ( int i=0; i<m; ++i )	cin >> T[i].u >> T[i].v >> T[i].cost;
	if ( k == -1 || k == n ) {
		cout << 0 << '\n';
		return 0;
	}
	sort(T,T+m,cmp);
	long long ans = 0;
	for ( int i=0; i<m; ++i ) {
		if ( find(T[i].u) == find(T[i].v) )	continue;
		p[find(T[i].u)] = find(T[i].v);
		if ( pt++ < n-k+1 || T[i].cost < 0 )	ans += T[i].cost;
	}
	cout << (pt<n ? -1 : ans) << '\n';
	return 0;
}

