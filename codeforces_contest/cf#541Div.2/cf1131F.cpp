#include <iostream>
#include <vector>
#define maxn 150005
using namespace std;
vector<int> G[maxn];
void dfs(int x, int fa) {
	cout << x << ' ';
	for ( int i : G[x] )
		if ( i != fa )
			dfs(i,x);
}
int main() {
	ios::sync_with_stdio(false);
	//   sync_with_YinHsuan(true);
	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=1; i<n; ++i ) {
		int a, b;
		cin >> a >> b;
		G[a].emplace_back(b);
		G[b].emplace_back(a);
	}
	for ( int i=1; i<=n; ++i ) {
		if ( G[i].size() == 1 ) {
			dfs(i,i);
			break;
		}
	}
	return 0;
}

