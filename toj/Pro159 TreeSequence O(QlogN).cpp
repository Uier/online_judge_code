#include <iostream>
#include <vector>
#define maxn 50005
using namespace std;
vector<int> G[maxn];
int n, m, cnt = 1;
int W[maxn], fa[maxn], in[maxn], out[maxn], bit[maxn*2];
void add(int i, int v) {
	while ( i <= n*2 ) {	// n*2 !!!
		bit[i] += v;
		i += (i&-i);
	}
}
int sum(int i) {
	int s = 0;
	while ( i > 0 ) {
		s += bit[i];
		i -= (i&-i);
	}
	return s;
}
void dfs(int x) {
	in[x] = cnt;
	add(cnt++,W[x]);
	for ( int i : G[x] )
		if ( i != fa[x] ) {
			fa[i] = x;
			dfs(i);
		}
	out[x] = cnt;
	add(cnt++,-W[x]);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int a, b;
	for ( int i=1; i<n; ++i ) {
		cin >> a >> b;
		G[a].emplace_back(b);
		G[b].emplace_back(a);
	}
	for ( int i=1; i<=n; ++i )
		cin >> W[i];
	fa[1] = -1;
	dfs(1);
	int ans = 0;
	while ( m-- ) {
		char c;
		cin >> c >> a;
		if ( c == 'C' ) {
			cin >> b;
			add(in[a],b-W[a]);
			add(out[a],-b+W[a]);
			W[a] = b;
		} else
			ans += sum(in[a]);
	}
	cout << ans << '\n';
	return 0;
}

