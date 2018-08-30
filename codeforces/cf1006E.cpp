#include <iostream>
#include <vector>
#define maxn 200005
using namespace std;
vector<int> G[maxn];
int ts1, ts2, in[maxn], out[maxn], re1[maxn];
void dfs(int x) {
	in[x] = ts1;
	re1[ts1++] = x;
	for ( int i : G[x] )
		dfs(i);
	out[x] = ts2++;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, q, a, b;
	cin >> n >> q;
	for ( int i=2, x; i<=n; ++i ) {
		cin >> x;
		G[x].emplace_back(i);
	}
	dfs(1);
	while ( q-- && cin >> a >> b ) {
		int x = in[a]+b-1;
		if ( x < ts1 && out[re1[x]] <= out[a] )	cout << re1[x] << '\n';
		else	cout << -1 << '\n';
	}
	return 0;
}

