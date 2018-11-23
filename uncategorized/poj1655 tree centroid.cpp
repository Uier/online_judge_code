#include <iostream>
#include <vector>
#define maxn 20005
using namespace std;
vector<int> G[maxn];
int t, n, sz[maxn], id, idx;
void dfs(int x, int fa) {
	int mx = 0;
	for ( int i=0; i<G[x].size(); ++i )
		if ( G[x][i] != fa ) {
			dfs(G[x][i],x);
			sz[x] += sz[G[x][i]]+1;
			mx = max(mx,sz[G[x][i]]+1);
		}
	mx = max(mx,n-1-sz[x]);
	if ( id == -1 || mx < idx || (mx == idx && x < id) ) {
		id = x;
		idx = mx;
	}
} 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while ( t-- && cin >> n ) {
		id = -1;
		for ( int i=1, a, b; i<n; ++i ) {
			cin >> a >> b;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		dfs(1,1);
		cout << id << ' ' << idx << '\n';
		for ( int i=1; i<=n; ++i ) {
			G[i].clear();
			sz[i] = 0;
		}
	}
	return 0;
}
