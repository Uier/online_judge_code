#include <iostream>
using namespace std;
int N, Q, seg[4194305];
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
void modify(int x, int v, int l, int r, int d) {
	if ( x < l || x > r )	return;
	if ( x >= l && x <= r ) {
		seg[d] = v;
		return;
	}
	int mid = (l+r)/2;
	modify(x,v,l,mid,d*2);
	modify(x,v,mid+1,r,d*2+1);
	seg[d] = max(seg[d*2],seg[d*2+1]);
}
int query(int a, int b, int l, int r, int d) {
	if ( a <= l && b >= r )	return seg[d];
	if ( a > r || b < l )	return -2147483648;
	int mid = (l+r)/2;
	int xl = query(a,b,l,mid,d*2);
	int xr = query(a,b,mid+1,r,d*2+1);
	return max(xl,xr);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	build(1,N,1);
	cin >> Q;
	while ( Q-- ) {
		int a, b;
		char p;
		cin >> p >> a >> b;
		if ( p == 'C' )
			modify(a,b,1,N,1);
		else
			cout << query(a,b,1,N,1)/2 << '\n';
	}
	return 0;
}

