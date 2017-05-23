#include <iostream>
#define maxn 1000005
using namespace std;
typedef pair<int,int> pii;
int c = 1, seg[4*maxn], tag[4*maxn];
void build(int l, int r, int d) {
	if ( l == r ) {
		seg[d] = 0;
		tag[d] = c++;
		return;
	}
	int mid = (l+r)/2;
	build(l,mid,d*2);
	build(mid+1,r,d*2+1);
	if ( seg[d*2] >= seg[d*2+1] ) {
		seg[d] = seg[d*2];
		tag[d] = tag[d*2];
	}
	else {
		seg[d] = seg[d*2+1];
		tag[d] = tag[d*2+1];
	}
}
void modify(int x, int val, int l, int r, int d) {
	if ( l > x || r < x )	return;
	else if ( l == r && l == x ) {
		seg[d] -= val;
		return;
	}
	int mid = (l+r)/2;
	modify(x,val,l,mid,d*2);
	modify(x,val,mid+1,r,d*2+1);
	if ( seg[d*2] >= seg[d*2+1] ) {
		seg[d] = seg[d*2];
		tag[d] = tag[d*2];
	}
	else {
		seg[d] = seg[d*2+1];
		tag[d] = tag[d*2+1];
	}
}
void print(int l, int r, int d) {
	if ( l == r ) {
		cout << seg[d] << '\n';
		return;
	}
	int mid = (l+r)/2;
	print(l,mid,d*2);
	print(mid+1,r,d*2+1);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	build(1,n,1);
	while ( q-- ) {
		int t, k, v;
		cin >> t;
		if ( t == 1 ) {
			cin >> k >> v;
			modify(k,-v,1,n,1);
		}
		else {
			cin >> v;
			modify(tag[1],v,1,n,1);
		}
	}
	print(1,n,1);
	return 0;
}

