#include <iostream>
#include <vector>
#include <map>
#define maxn 100005
using namespace std;
int sz[maxn], col[maxn], cnt[maxn], mx[maxn];
long long ans[maxn];
vector<int> G[maxn];
void add(int x, int fa, int mxson, int val, int root) {
	cnt[col[x]] += val;
	if ( root ) {
		if ( cnt[col[x]] == mx[root] )	ans[root] += col[x];
		else if ( cnt[col[x]] > mx[root] )
			mx[root] = cnt[col[x]], ans[root] = col[x];
	}
	for ( int i : G[x] )
		if ( i != fa && i != mxson )
			add(i,x,mxson,val,root);
}
void dfs1(int x, int fa) {
	sz[x] = 1;
	for ( int i : G[x] )
		if ( i != fa ) {
			dfs1(i,x);
			sz[x] += sz[i];
		}
}
void dfs2(int x, int fa, bool keep) {
	int mxson = 0;
	for ( int i : G[x] )
		if ( i != fa && sz[i] > sz[mxson] )
			mxson = i;
	for ( int i : G[x] )
		if ( i != fa && i != mxson )
			dfs2(i,x,0);
	if ( mxson )	dfs2(mxson,x,1);
	mx[x] = mx[mxson], ans[x] = ans[mxson];
	add(x,fa,mxson,1,x);
	if ( !keep )	add(x,fa,0,-1,0);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=1; i<=n; ++i )	cin >> col[i];
	for ( int i=1, u, v; i<n; ++i ) {
		cin >> u >> v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	dfs1(1,1);
	dfs2(1,1,1);
	for ( int i=1; i<=n; ++i )	cout << ans[i] << ' ';
	return 0;
}

