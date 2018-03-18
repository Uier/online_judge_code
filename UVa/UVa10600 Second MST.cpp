#include <iostream>
#include <algorithm>
#include <vector>
#define maxn 105
#define maxm 5005
using namespace std;
struct tree {
	int u, v, w;
} T[maxm];
vector<int> mst;
int p[maxn];
int find(int x) {
	return (p[x]==x ? x : p[x]=find(p[x]));
}
bool cmp(tree x, tree y) {
	return x.w < y.w;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n, m;
	cin >> t;
	while ( t-- && cin >> n >> m ) {
		for ( int i=0; i<m; ++i )
			cin >> T[i].u >> T[i].v >> T[i].w;
		sort(T,T+m,cmp);
		for ( int i=1; i<=n; ++i )	p[i] = i;
		mst.clear();
		int cost = 0, secondcost = 1e9;
		for ( int i=0; i<m; ++i ) {
			if ( find(T[i].u) == find(T[i].v) )	continue;
			mst.emplace_back(i);
			p[find(T[i].u)] = find(T[i].v);
			cost += T[i].w;
		}
		for ( int k=0; k<n-1; ++k ) {
			for ( int i=1; i<=n; ++i )	p[i] = i;
			int newcost = 0, cnt = 1;
			for ( int i=0; i<m; ++i ) {
				if ( find(T[i].u) == find(T[i].v) || i == mst[k] )
					continue;
				cnt++;
				p[find(T[i].u)] = find(T[i].v);
				newcost += T[i].w;
			}
			if ( cnt == n )
				secondcost = min(secondcost,newcost);
		}
		cout << cost << ' ' << secondcost << '\n';
	}
	return 0;
}

