#include <iostream>
#include <vector>
#include <string.h>
#define maxn 205
using namespace std;
int n, m, _scc, scc[maxn], sat[maxn];
bool vis[maxn];
vector<int> G[maxn], fini, ans;
inline int _not(int x) {
	return x > n ? x : x+n;
}
void dfs1(int x) {
	vis[x] = true;
	for ( int i : G[x] )
		if ( !vis[i] )
			dfs1(i);
	fini.emplace_back(x);
}
void dfs2(int x, int cnt) {
	vis[x] = true;
	for ( int i : G[x] )
		if ( !vis[i] )
			dfs2(i,cnt);
	scc[x] = cnt;
}
int main() {
//	ios::sync_with_stdio(false);
//	//   sync_with_YinHsuan(true);
//	cin.tie(0);
	cin >> n >> m;
	for ( int i=0, a, b, c; i<m; ++i ) {
		cin >> a >> b >> c;
		if ( c == 0 ) {
			G[a].emplace_back(_not(b));
			G[b].emplace_back(_not(a));
			G[_not(a)].emplace_back(b);
			G[_not(b)].emplace_back(a);
		} else {
			G[a].emplace_back(b);
			G[b].emplace_back(a);
			G[_not(a)].emplace_back(_not(b));
			G[_not(b)].emplace_back(_not(a));
		}
	}
	for ( int i=1; i<=n*2; ++i )
		if ( !vis[i] )
			dfs1(i);
	memset(vis,0,sizeof(vis));
	int sz = fini.size();
	for ( int i=sz-1; i>=0; --i )
		if ( !vis[fini[i]] )
			dfs2(fini[i],_scc++);
	for ( int i=1; i<=n; ++i )
		if ( scc[i] == scc[_not(i)] )
			return cout << "Impossible\n", 0;
	for ( int i=1; i<=n*2; ++i ) {
		int x = fini[i-1];
		if ( !sat[scc[x]] ) {
			sat[scc[x]] = 1;
			sat[scc[_not(x)]] = 2;
		}
	}
	for ( int i=1; i<=n; ++i )
		if ( sat[scc[i]] == 1 ) {
			cout << i << '\n';
			ans.emplace_back(i);
		} else {
			cout << "not " << i << '\n';
		}
	cout << (int)ans.size() << '\n';
	for ( int i : ans )
		cout << i << ' ';
	return 0;
}

