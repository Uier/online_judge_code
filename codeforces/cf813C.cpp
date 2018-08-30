#include <iostream>
#include <vector>
#define maxn 200005
using namespace std;
int n, bob, fa[maxn], D[maxn], sz[maxn];
vector<int> G[maxn];
void dfs(int x, int dep) {
	D[x] = dep;
	sz[x] = 1;
	int mx = 0;
	for ( int i : G[x] )
		if ( i != fa[x] ) {
			fa[i] = x;
			dfs(i,dep+1);
			mx = max(mx,sz[i]);
		}
	sz[x] += mx;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> bob;
	for ( int i=1, x, y; i<n; ++i ) {
		cin >> x >> y;
		G[x].emplace_back(y);
		G[y].emplace_back(x);
	}
	dfs(1,1);
	int step = (D[bob]-D[1]-1)/2, ans = (D[bob]-D[1]+sz[bob]-1)*2;
	int ans2 = (D[bob]-D[1]-step)*2;
	while ( step-- )	bob = fa[bob];
	ans2 += (sz[bob]-1)*2;
	cout << max(ans,ans2) << '\n';
	return 0;
}
