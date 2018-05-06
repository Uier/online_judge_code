#include <iostream>
#include <vector>
#define maxn 200005
using namespace std;
int n, m;
vector<int> G[maxn];
bool V[maxn];
int now_st;
bool dfs(int x, int fa) {
	V[x] = true;
	if ( G[x].size() != 2 )	return false;
	int t = G[x][0];
	if ( t == fa )	t = G[x][1];
	if ( !V[t] ) return dfs(t,x);
	else if ( t == now_st )	return true;
	return false;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for ( int i=0; i<m; ++i ) {
		int a, b;
		cin >> a >> b;
		G[a].emplace_back(b);
		G[b].emplace_back(a);
	}
	for ( int i=1; i<=n; ++i )
		if ( G[i].size() == 0 )
			V[i] = true;
	int cnt = 0;
	for ( int i=1; i<=n; ++i )
		if ( !V[i] ) {
			now_st = i;
			if ( dfs(i,0) )	cnt++;
		}
	cout << cnt << '\n';
	return 0;
}
