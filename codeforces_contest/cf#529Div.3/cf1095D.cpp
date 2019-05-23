#include <iostream>
#include <vector>
#define maxn 200005
using namespace std;
int n;
bool V[maxn];
vector<int> G[maxn], ans, tmp;
void dfs(int x, int y, int dep) {
	if ( dep == n )	return;
	ans.emplace_back(y);
	int z = 0;
	if ( G[x][0] != y )	z = G[x][0];
	else	z = G[x][1];
	dfs(y,z,dep+1);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for ( int i=1, a, b; i<=n; ++i ) {
		cin >> a >> b;
		G[i].emplace_back(a);
		G[i].emplace_back(b);
	}
	ans.emplace_back(1);
	int a = G[1][0], b = G[1][1];
	if ( G[a][0] == b || G[a][1] == b )	dfs(1,a,1);
	else	dfs(1,b,1);
	for ( int i : ans )	cout << i << ' ';
	cout << '\n';
	return 0;
}

