#include <iostream>
#include <vector>
#define maxn 500005
using namespace std;
int in[maxn], out[maxn], F[maxn], cnt = 1;
int seg[maxn*8], tag[maxn*8]; // filled: 1, empty: 2
vector<int> G[maxn];
void dfs(int x) {
	in[x] = cnt++;
	for ( int i : G[x] )
		if ( i != F[x] ) {
			F[i] = x;
			dfs(i);
		}
	out[x] = cnt++;
}
void push(int d) {
	seg[d<<1] = seg[d<<1|1] = tag[d];
	tag[d<<1] = tag[d<<1|1] = tag[d];
	tag[d] = 0;
}
void modify(int l, int r, int d, int ql, int qr, int val) {
	if ( qr < l || r < ql )	return;
	if ( ql <= l && r <= qr ) {
		seg[d] = tag[d] = val;
		return;
	}
	if ( tag[d] ) push(d);
	int mid = l+r>>1;
	modify(l,mid,d<<1,ql,qr,val);
	modify(mid+1,r,d<<1|1,ql,qr,val);
	seg[d] = max(seg[d<<1], seg[d<<1|1]);
}
int query(int l, int r, int d, int ql, int qr) {
	if ( qr < l || r < ql )	return 0;
	if ( ql <= l && r <= qr )	return seg[d];
	if ( tag[d] ) push(d);
	int mid = l+r>>1;
	return max(query(l,mid,d<<1,ql,qr), query(mid+1,r,d<<1|1,ql,qr));
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q, a, b;
	cin >> n;
	for ( int i=1; i<n; ++i ) {
		cin >> a >> b;
		G[a].emplace_back(b);
		G[b].emplace_back(a);
	}
	F[1] = 1;
	dfs(1);
	modify(1,n<<1,1,1,n,2); // set every nodes as empty(2)
	cin >> q;
	while ( q-- && cin >> a >> b ) {
		if ( a == 1 ) {
			if ( query(1,n<<1,1,in[b],out[b]) == 2 )	modify(1,n<<1,1,in[F[b]],in[F[b]],2);
			modify(1,n<<1,1,in[b],out[b],1);
		} else if ( a == 2 ) {
			modify(1,n<<1,1,in[b],in[b],2);
		} else {
			if ( query(1,n<<1,1,in[b],out[b]) == 2 )	cout << 0 << '\n';
			else	cout << 1 << '\n';
		}
	}
	return 0;
}