#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
struct node {
	int to, cost;
};
vector<node> G[100005];
int D[100005];
void dfs(int x, int fa) {
	for ( node i : G[x] )
		if ( i.to != fa ) {
			D[i.to] = D[x] + i.cost;
			dfs(i.to,x);
		}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for ( int i=0; i<m; ++i ) {
		int a, b, c;
		cin >> a >> b >> c;
		G[a].push_back({b,c});
		G[b].push_back({a,c});
	}
	dfs(0,-1);
	int tmp = 0, idx = -1;
	for ( int i=0; i<n; ++i )
		if ( D[i] > tmp ) {
			tmp = D[i];
			idx = i;
		}
	memset(D,0,sizeof D);
	tmp = 0;
	dfs(idx,-1);
	for ( int i=0; i<n; ++i )
		tmp = max(D[i],tmp);
	cout << tmp << '\n';
	return 0;
}

