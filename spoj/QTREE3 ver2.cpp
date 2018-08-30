#include <iostream>
#include <vector>
#define maxn 100005
using namespace std;
vector<int> G[maxn];
int n, q, a, b, D[maxn], siz[maxn], mson[maxn], fa[maxn];
int link[maxn], linktop[maxn], table[maxn], seg[maxn*4], cnt;
bool color[maxn]; // 0 for white, 1 for black
const int inf = 1e9;
void modify(int x, int val, int l, int r, int d) {
	if ( l > x || r < x )	return;
	if ( l == r && l == x )	{
		color[table[x]] = val;
		seg[d] = (color[table[x]] ? table[x] : inf);
		return;
	}
	int mid = (l+r)>>1;
	modify(x,val,l,mid,d<<1);
	modify(x,val,mid+1,r,(d<<1)+1);
	if ( seg[d<<1] != inf && seg[(d<<1)+1] != inf )
		seg[d] = (D[seg[d<<1]] <= D[seg[(d<<1)+1]] ? seg[d<<1] : seg[(d<<1)+1]);
	else 
		seg[d] = (seg[d<<1] != inf ? seg[d<<1] : seg[(d<<1)+1]);
}
int query(int a, int b, int l, int r, int d) {
	if ( l > a || r < a )	return inf;
	if ( a <= l && r <= b )	return seg[d];
	int mid = (l+r)>>1;
	int lx = query(a,b,l,mid,d<<1), rx = query(a,b,mid+1,r,(d<<1)+1);
	if ( lx != inf && rx != inf )
		return (D[lx] <= D[rx] ? lx : rx);
	else
		return (lx != inf ? lx : rx );
}
void dfs(int x) {
	siz[x] = 1;
	mson[x] = -1;
	for ( int i : G[x] )
		if ( i != fa[x] ) {
			D[i] = D[x] + 1;
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
	table[cnt] = x;
	modify(cnt,0,1,n,1);
	if ( mson[x] == -1 )	return;
	findlink(mson[x],top);
	for ( int i : G[x] )
		if ( i != fa[x] && i != mson[x] )
			findlink(i,i);
}
int solve(int x) { // first black node from 1 to x
	int tx = linktop[x], ans = inf;
	while ( tx != 1 ) {
		int tmp = query(link[tx],link[x],1,n,1);
		if ( tmp != inf && (ans == inf || D[tmp] <= D[ans]) )	ans = tmp;
		tx = linktop[x=fa[tx]];
	}
	int tmp = query(link[tx],link[x],1,n,1);
	if ( tmp != inf && (ans == inf || D[tmp] <= D[ans]) )	ans = tmp;
	return (ans == inf ? -1 : ans);
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
		else	modify(link[b],!color[b],1,n,1);
	return 0;
}

