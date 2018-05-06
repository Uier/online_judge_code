#include <iostream>
#include <vector>
#define maxn 100005
using namespace std;
int n, m, in[maxn], out[maxn], cnt = 1;
vector<int> G[maxn];
struct liar {
	bool val, chg;
} seg[maxn*8];
void dfs(int x) {
	in[x] = cnt++;
	for ( int i : G[x] )
		dfs(i);
	out[x] = cnt++;
}
void push(int d) {
	seg[d].chg = false;
	seg[d*2].chg ^= 1;
	seg[d*2+1].chg ^= 1;
	seg[d*2].val ^= 1;
	seg[d*2+1].val ^= 1;
}
void modify(int a, int b, int l, int r, int d) {
	if ( a > r || b < l )	return;
	if ( a <= l && r <= b )	{
		seg[d].chg ^= 1;
		seg[d].val ^= 1;
		return;
	}
	if ( seg[d].chg )	push(d);
	int mid = (l+r)>>1;
	modify(a,b,l,mid,d*2);
	modify(a,b,mid+1,r,d*2+1);
}
int query(int x, int l, int r, int d) {
	if ( x > r || x < l )	return -1;
	if ( x == l && r == x )	return (seg[d].val ? 1 : 0 );
	if ( seg[d].chg )	push(d);
	int mid = (l+r)>>1;
	int lx = query(x,l,mid,d*2), rx = query(x,mid+1,r,d*2+1);
	return (lx == -1 ? rx : lx );
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int x, a, b;
	for ( int i=1; i<=n; ++i ) {
		cin >> x;
		while ( x-- && cin >> a )
			G[i].emplace_back(a);
	}
	dfs(1);
	while ( m-- && cin >> a >> b )
		if ( a )	cout << query(in[b],1,n*2,1) << '\n';
		else	modify(in[b],out[b],1,n*2,1);
	return 0;
}

