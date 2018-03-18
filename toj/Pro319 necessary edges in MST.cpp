#include <iostream>
#include <algorithm>
#define maxn 505
#define maxm 50005
using namespace std;
int n, m, p[maxn], w_of_ban[maxn];
struct mst {
	int u, v, w, ban;
} a[maxm];
int find(int x) {
	return (p[x] == x ? x : (p[x] = find(p[x])));
}
bool cmp(mst x, mst y) {
	return x.w < y.w;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for ( int i=0; i<n; ++i )	p[i] = i;
	for ( int i=0; i<m; ++i )
		cin >> a[i].u >> a[i].v >> a[i].w;
	sort(a,a+m,cmp);
	for ( int i=1; i<m; ++i )
		if ( a[i].w == a[i-1].w )
			a[i].ban = a[i-1].ban = -1;
	int num_ban = 0, cost = 0;
	for ( int i=0; i<m; ++i ) {
		if ( find(a[i].u) == find(a[i].v) )	continue;
		p[find(a[i].u)] = find(a[i].v);
		cost += a[i].w;
		if ( a[i].ban == -1 ) {
			a[i].ban = ++num_ban;
			w_of_ban[num_ban] = a[i].w;
		}
	}
	int ans = n-1, ans_cost = cost;
	for ( int k=1; k<=num_ban; ++k ) {
		for ( int i=0; i<n; ++i )	p[i] = i;
		int newcost = 0;
		for ( int i=0; i<m; ++i ) {
			if ( find(a[i].u) == find(a[i].v) || a[i].ban == k )
				continue;
			p[find(a[i].u)] = find(a[i].v);
			newcost += a[i].w;
		}
		if ( newcost == cost ) {
			ans--;
			ans_cost -= w_of_ban[k];
		}
	}
	cout << ans << ' ' << ans_cost << '\n';
	return 0;
}

