#include <iostream>
#include <vector>
#include <algorithm>
#define maxn 200005
using namespace std;
vector<int> G[maxn];
int deg[maxn], p[maxn];
int find(int x) {
	return (p[x]==x ? x : (p[x]=find(p[x])));
}
inline void u_(int x, int y) {
	p[y] = x;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, mxid = 1;
	cin >> n >> m;
	for ( int i=1; i<=n; ++i )	p[i] = i;
	for ( int i=0, a, b; i<m; ++i ) {
		cin >> a >> b; 
		G[a].emplace_back(b);
		G[b].emplace_back(a); 
		deg[a]++;
		deg[b]++;
		if ( deg[a] > deg[mxid] )	mxid = a;
		if ( deg[b] > deg[mxid] )	mxid = b;
	}
	for ( int i : G[mxid] ) {
		u_(find(mxid),find(i));
		cout << mxid << ' ' << i << '\n';
	}
	int cnt = n-G[mxid].size()-1;
	for ( int i=1; i<=n; ++i ) {
		if ( i == mxid )	continue;
		for ( int j : G[i] ) {
			int tu = find(i), tv = find(j);
			if ( tu == tv )	continue;
			u_(tu,tv);
			cout << j << ' ' << i << '\n';
			cnt--;
		}
	}
	return 0;
}

