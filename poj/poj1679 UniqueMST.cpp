#include <iostream>
#include <algorithm>
using namespace std;
struct mst {
	int u, v, w, ban;
} a[10005];
int p[10005];
int find(int x) {
	return (p[x] == x ? x : (p[x] = find(p[x])));
}
bool cmp(mst x, mst y) {
	return x.w < y.w;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n, m;
	cin >> t;
	while ( t-- && cin >> n >> m ) {
		for ( int i=1; i<=n; ++i )	p[i] = i;
		for ( int i=0; i<m; a[i].ban=0, ++i )
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
			if ( a[i].ban == -1 )	a[i].ban = ++num_ban;
		}
		if ( num_ban == 0 )	cout << cost << '\n';
		else {
			bool flag = true;
			for ( int k=1; k<=num_ban; ++k ) {
				for ( int i=1; i<=n; ++i )	p[i] = i;
				int newcost = 0;
				for ( int i=0; i<m; ++i ) {
					if ( find(a[i].u) == find(a[i].v) || a[i].ban == k )
						continue;
					p[find(a[i].u)] = find(a[i].v);
					newcost += a[i].w;
				}
				if ( newcost == cost ) {
					flag = false;
					break;
				}
			}
			if ( flag )	cout << cost <<'\n';
			else	cout << "Not Unique!\n";
		}
	}
	return 0;
}

