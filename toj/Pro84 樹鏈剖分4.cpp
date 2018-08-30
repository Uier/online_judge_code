#include <iostream>
#include <vector>
#define maxn 200005
using namespace std;
vector<int> G[maxn];
int n, q, a, b, siz[maxn], mson[maxn], fa[maxn];
int link[maxn], anti[maxn], linktop[maxn], seg[maxn*4], cnt;
const int inf = 1e9;
void modify(int x, int l, int r, int d) {
	if ( l > x || r < x )	return;
	if ( l == r && l == x )	{
		seg[d] = (seg[d] == inf ? x : inf);
		return;
	}
	int mid = (l+r)>>1;
	modify(x,l,mid,d<<1);
	modify(x,mid+1,r,d<<1|1);
	seg[d] = min(seg[d<<1],seg[d<<1|1]);
}
int query(int a, int b, int l, int r, int d) {
	if ( l > b || r < a )	return inf;
	if ( a <= l && r <= b )	return seg[d];
	int mid = (l+r)>>1;
	return min(query(a,b,l,mid,d<<1),query(a,b,mid+1,r,d<<1|1));
}
void dfs(int x) {
	siz[x] = 1;
	mson[x] = -1;
	for ( int i : G[x] ) {
		if ( i == fa[x] )	continue;
		fa[i] = x;
		dfs(i);
		if ( mson[x] == -1 || siz[i] > siz[mson[x]] )
			mson[x] = i;
		siz[x] += siz[i];
	}
}
void findlink(int x, int top) {
	linktop[x] = top;
	link[x] = ++cnt;
	anti[cnt] = x;
	modify(cnt,1,n,1);
	if ( mson[x] == -1 )	return;
	findlink(mson[x],top);
	for ( int i : G[x] )
		if ( i != fa[x] && i != mson[x] )
			findlink(i,i);
}
int solve(int x) { // first black node from 1 to x
	int tx = linktop[x], ans = inf;
	while ( tx != 1 ) {
		ans = min(ans,query(link[tx],link[x],1,n,1));
		tx = linktop[x=fa[tx]];
	}
	ans = min(ans,query(link[tx],link[x],1,n,1));
	return (ans == inf ? -1 : anti[ans]);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for ( int i=1; i<n; ++i ) {
		cin >> a >> b;
		G[a].emplace_back(b);
		G[b].emplace_back(a);
	}
	dfs(1);
	findlink(1,1);
	while ( q-- && cin >> a >> b )
		if ( a )	cout << solve(b) << '\n';
		else	modify(link[b],1,n,1);
	return 0;
}
