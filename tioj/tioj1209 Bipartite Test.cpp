#include <iostream>
#include <vector>
#include <string.h>
#define maxn 40005
using namespace std;
vector<int> G[maxn];
int D[maxn];
bool ans;
void dfs(int u, int color) {
	D[u] = color;
	for ( int v : G[u] ) {
		if ( D[v] == -1 )
			dfs(v,color^1);
		else
			ans &= (D[u] != D[v]);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, a, b;
	while ( cin >> n >> m && n ) {
		for ( int i=1; i<=n; ++i )	G[i].clear();
		memset(D,-1,sizeof(D));
		ans = true;
		for ( int i=0; i<m; ++i ) {
			cin >> a >> b;
			G[a].emplace_back(b);
			G[b].emplace_back(a);
		}
		dfs(1,1);
		cout << (ans ? "Yes\n" : "No\n");
	}
	return 0;
}
