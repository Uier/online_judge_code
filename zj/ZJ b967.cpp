#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
vector<int> G[100005];
int n, a, b, ans, ansd;
void dfs(int x, int fa, int dep) {
	if ( dep > ansd )	ans = x, ansd = dep;
	for ( int i : G[x] )
		if ( i != fa )
			dfs(i,x,dep+1);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while ( cin >> n ) {
		ans = ansd = 0;
		memset(G,0,sizeof G);
		for ( int i=0; i<n-1; ++i ) {
			cin >> a >> b;
			G[a].emplace_back(b);
			G[b].emplace_back(a);
		}
		dfs(0,-1,0);
		dfs(ans,-1,0);
		cout << ansd << '\n';
	}
	return 0;
}

