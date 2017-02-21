#include <iostream>
#define maxn 100005
using namespace std;
int seg[maxn*4];
void build(int l, int r, int d) {
	if ( l == r ) {
		cin >> seg[d];
		return;
	}
	int mid = (l+r)/2;
	build(l,mid,d*2);
	build(mid+1,r,d*2+1);
	seg[d] = max(seg[d*2],seg[d*2+1]);
}
void modify(int x, int val, int l, int r, int d) {
	if ( l > x || r < x )	return;
	if ( l == r && r == x ) {
		seg[d] += val;
		return;
	}
	int mid = (l+r)/2;
	modify(x,val,l,mid,d*2);
	modify(x,val,mid+1,r,d*2+1);
	seg[d] = max(seg[d*2],seg[d*2+1]);
}
int query(int ql, int qr, int l, int r, int d) {
	if ( l > qr || r < ql )	return -1e9;
	if ( ql <= l && r <= qr )	return seg[d];
	int mid = (l+r)/2;
	return max(query(ql,qr,l,mid,d*2),query(ql,qr,mid+1,r,d*2+1));
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k, a, b, c;
	while ( cin >> n >> k ) {
		build(1,n,1);
		while ( k-- ) {
			cin >> a >> b >> c;
			if ( a == 1 )
				cout << query(min(b,c),max(b,c),1,n,1) << '\n';
			else
				modify(b,c,1,n,1);
		}
	}
	return 0;
}

