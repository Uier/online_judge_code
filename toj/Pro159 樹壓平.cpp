#include <iostream>
#include <vector>
#define maxn 50005
using namespace std;
int n, m, W[maxn], in[maxn], out[maxn], bit[maxn*2], cnt = 1;
vector<int> G[maxn];
void add(int x, int v) {
	for ( int i=x; i<=n*2; i+=(i&-i) )
		bit[i] += v;
}
int sum(int x) {
	int s = 0;
	for ( int i=x; i>0; i-=(i&-i) )
		s += bit[i];
	return s;
}
void dfs(int x, int fa) {
	in[x] = cnt++;
	add(in[x],W[x]);
	for ( int i : G[x] )
		if ( i != fa )
			dfs(i,x);
	out[x] = cnt++;
	add(out[x],-W[x]);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int a, b, x, w, ans = 0;
	char c;
	for ( int i=1; i<n; ++i ) {
		cin >> a >> b;
		G[a].emplace_back(b);
		G[b].emplace_back(a);
	}
	for ( int i=1; i<=n; ++i )	cin >> W[i];
	dfs(1,0);
	while ( m-- && cin >> c >> x ) {
		if ( c == (int)'C' ) {
			cin >> w;
			add(in[x],w-W[x]);
			add(out[x],-w+W[x]);
			W[x] = w;
		} else	ans += sum(in[x]);
	}
	cout << ans << '\n';
	return 0;
}

