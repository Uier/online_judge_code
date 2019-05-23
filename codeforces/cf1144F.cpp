#include <iostream>
#include <vector>
#include <map>
#define maxn 200005
using namespace std;
typedef pair<int,int> pii;
vector<int> G[maxn];
vector<pii> edge;
bool vis[maxn], col[maxn];
bool dfs(int x, int c) {
	vis[x] = 1;
	col[x] = c;
	for ( int i : G[x] ) {
		if ( !vis[i] ) {
			if ( !dfs(i,c^1) )	return false;
		} else if ( col[i] == col[x] )	return false;
	}
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for ( int i=0; i<m; ++i ) {
		int a, b;
		cin >> a >> b;
		G[a].emplace_back(b);
		G[b].emplace_back(a);
		edge.emplace_back(pii{a,b});
	}
	if ( dfs(1,0) ) {
		cout << "YES\n";
		for ( pii i : edge ) {
			int u = i.first, v = i.second;
			if ( col[u] == 0 )	cout << 1;
			else	cout << 0;
		}
	} else {
		cout << "NO\n";
	}
	return 0;
}

