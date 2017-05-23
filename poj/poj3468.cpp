#include <iostream>
#define maxn 100001
using namespace std;
struct node {
	long long chg, val;
} seg[maxn*4];
int N, Q;
//	seg[d].val had been updated when you modified.
void push(int l, int r, int d) {
	seg[d*2].chg += seg[d].chg;
	seg[d*2+1].chg += seg[d].chg;
	int mid = (l+r)/2;
	seg[d*2].val += (mid-l+1)*seg[d].chg;
	seg[d*2+1].val += (r-(mid+1)+1)*seg[d].chg;
	seg[d].chg = 0;
}
void build(int l, int r, int d) {
	if ( l == r ) {
		cin >> seg[d].val;
		return;
	}
	int mid = (l+r)/2;
	build(l,mid,d*2);
	build(mid+1,r,d*2+1);
	seg[d].val = seg[d*2].val + seg[d*2+1].val;
}
void modify(int a, int b, int x, int l, int r, int d) {
	if ( a > r || b < l )	return;
	if ( a <= l && b >= r ) {
		seg[d].chg += x;
		seg[d].val += (r-l+1)*x;
		return;
	}
	push(l,r,d);
	int mid = (l+r)/2;
	modify(a,b,x,l,mid,d*2);
	modify(a,b,x,mid+1,r,d*2+1);
	seg[d].val = seg[d*2].val + seg[d*2+1].val;
}
long long query(int a, int b, int l, int r, int d) {
	if ( a > r || b < l )	return 0;
	if ( a <= l && b >= r )	return seg[d].val;
	push(l,r,d);
	int mid = (l+r)/2;
	long long xl = query(a,b,l,mid,d*2);
	long long xr = query(a,b,mid+1,r,d*2+1);
	return xl + xr;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> Q;
	build(1,N,1);
	while ( Q-- ) {
		int x, y, z;
		char p;
		cin >> p;
		if ( p == 'C' ) {
			cin >> x >> y >> z;
			modify(x,y,z,1,N,1);
		} else {
			cin >> x >> y;
			cout << query(x,y,1,N,1) << '\n';
		}
	}
	return 0;
}

