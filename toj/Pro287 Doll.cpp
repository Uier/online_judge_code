#include <iostream>
#include <vector>
#include <string.h>
#define maxn 205
using namespace std;
int match[maxn], V[maxn], cnt = 1;
vector<int> G[maxn];
bool dfs(int x) {
	for ( int i : G[x] )
		if ( V[i] != cnt ) {
			V[i] = cnt;
			if ( match[i] == -1 || dfs(match[i]) ) {
				match[i] = x;
				return true;
			}
		}
	return false;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n, m, a, b;
	cin >> t;
	while ( t-- && cin >> n >> m ) {
		memset(match,-1,sizeof(int)*n);
		for ( int i=0; i<n; ++i )	G[i].clear();
		while ( m-- && cin >> a >> b )
			G[a-1].emplace_back(b-1);
		int ans = n;
		for ( int i=0; i<n; ++i, ++cnt )
			if ( dfs(i) )	ans--;
		cout << ans << '\n';
	}
	return 0;
}

