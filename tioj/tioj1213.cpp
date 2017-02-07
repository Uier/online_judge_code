#include <iostream>
#include <vector>
using namespace std;
struct Edge {
	int to, cost;
};
int ans;
pair<int,int> far;
vector<Edge> G[100005];
void dfs_far(int x, int fa, int dist) {
	for ( Edge i : G[x] )
		if ( i.to != fa ) {
			if ( dist + i.cost > far.second )
				far.first = i.to, far.second = dist+i.cost;
			dfs_far(i.to,x,dist+i.cost);
		}
}
void dfs_ans(int x, int fa, int dist) {
	for ( Edge i : G[x] )
		if ( i.to != fa ) {
			ans = max(ans,dist+i.cost);
			dfs_ans(i.to,x,dist+i.cost);
		}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, a, b, c;
	while ( cin >> n && n ) {
		for ( int i=1; i<=n; i++ )  G[i].clear();
		for ( int i=1; i<n; i++ ) {
			cin >> a >> b >> c;
			G[a].push_back({b,c});
			G[b].push_back({a,c});
		}
		far.first = far.second = ans = 0;
		dfs_far(1,0,0);
		dfs_ans(far.first,0,0);
		cout << ans << '\n';
	}
	return 0;
}

