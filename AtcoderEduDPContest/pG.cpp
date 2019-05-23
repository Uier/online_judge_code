#include <iostream>
#include <vector>
#define maxn 100005
using namespace std;
int inedge[maxn], ans, sz[maxn];
vector<int> G[maxn];
void dfs(int x) {
	sz[x] = 1;
	int mx = 0;
	for ( int i : G[x] ) {
		if ( sz[i] == 0 )	dfs(i);
		mx = max(mx,sz[i]);
	}
	sz[x] += mx;
}
int main() {
	ios::sync_with_stdio(false);
	//   sync_with_YinHsuan(true);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for ( int i=0, a, b; i<m; ++i ) {
		cin >> a >> b;
		G[a].emplace_back(b);
		inedge[b]++;
	}
	for ( int i=1; i<=n; ++i )
		if ( inedge[i] == 0 ) {
			dfs(i);
			ans = max(ans,sz[i]-1);
		}
	cout << ans << '\n';
	return 0;
}

