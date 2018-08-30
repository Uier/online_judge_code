#include <iostream>
#include <vector>
#include <string.h>
#define maxn 100005
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
	int t, p, q, k, a, b;
	cin >> t;
	while ( t-- && cin >> p >> q >> k ) {
		for ( int i=0; i<p; ++i )	G[i].clear();
		memset(match,-1,sizeof(int)*q);
		for ( int i=0; i<k; ++i ) {
			cin >> a >> b;
			G[a-1].emplace_back(b-1);
		}
		int ans = 0;
		for ( int i=0; i<p; ++i, ++cnt )
			if ( dfs(i) )
				ans++;
		cout << ans << '\n';
	} 
	return 0;
}

