#include <iostream>
#include <vector>
#define maxn 100005
#define int long long
using namespace std;
struct node {
	int w, b;
};
vector<int> G[maxn];
const int mod = 1000000007;
node dfs(int x, int fa) {
	int w = 1, b = 1;
	for ( int i : G[x] ) {
		if ( i == fa )	continue;
		node tmp = dfs(i,x);
		w *= (tmp.w+tmp.b)%mod;
		w %= mod;
		b *= tmp.w;
		b %= mod;
	}
	return node{w,b};
}
main() {
	ios::sync_with_stdio(false);
	//   sync_with_YinHsuan(true);
	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=1; i<n; ++i ) {
		int u, v;
		cin >> u >> v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	node ans = dfs(1,1);
	cout << (ans.w+ans.b)%mod << '\n';
	return 0;
}

