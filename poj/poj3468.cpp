#include <iostream>
#define maxn 100005
#define int long long
using namespace std;
struct Node {
	long long chg, data;
} seg[maxn*4];
void push(int l, int r, int d) {
	int mid = (l+r)/2;
	seg[d*2].chg += seg[d].chg;
	seg[d*2+1].chg += seg[d].chg;
	seg[d*2].data += (mid-l+1)*seg[d].chg;
	seg[d*2+1].data += (r-mid)*seg[d].chg;
	seg[d].chg = 0;
}
void build(int l, int r, int d) {
	if ( l == r ) {
		cin >> seg[d].data;
		return;
	}
	int mid = (l+r)/2;
	build(l,mid,d*2);
	build(mid+1,r,d*2+1);
	seg[d].data = seg[d*2].data + seg[d*2+1].data;
}
void modify(int a, int b, int val, int l, int r, int d) {
	if ( a <= l && r <= b ) {
		seg[d].chg += val;
		seg[d].data += (r-l+1)*val;
		return;
	}
	if ( l > b || r < a )	return;
	push(l,r,d);
	int mid = (l+r)/2;
	modify(a,b,val,l,mid,d*2);
	modify(a,b,val,mid+1,r,d*2+1);
	seg[d].data = seg[d*2].data + seg[d*2+1].data;
}
long long query(int a, int b, int l, int r, int d) {
	if ( a <= l && r <= b )	return seg[d].data;
	if ( l > b || r < a )	return 0;
	push(l,r,d);
	int mid = (l+r)/2;
	return query(a,b,l,mid,d*2)+query(a,b,mid+1,r,d*2+1);
}
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, q, a, b, c;
	cin >> n >> q;
	build(1,n,1);
	while ( q-- ) {
		char d;
		cin >> d;
		if ( d == 'Q' ) {
			cin >> a >> b;
			cout << query(a,b,1,n,1) << '\n';
		} else {
			cin >> a >> b >> c;
			modify(a,b,c,1,n,1);
		}
	}
	return 0;
}

