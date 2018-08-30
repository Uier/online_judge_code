#include <iostream>
#include <algorithm> 
#define maxn 100005
#define x first
#define y second
using namespace std;
typedef pair<int,int> pii;
pii seg[maxn*4];
void build(int l, int r, int d) {
	if ( l == r ) {
		cin >> seg[d].x;
		return;
	}
	int mid = (l+r)/2, ptl = d*2, ptr = d*2+1;
	build(l,mid,ptl);
	build(mid+1,r,ptr);
	int tmp[4] = {seg[ptl].x,seg[ptl].y,seg[ptr].x,seg[ptr].y};
	sort(tmp,tmp+4);
	seg[d] = pii{tmp[3],tmp[2]};
}
void update(int x, int val, int l, int r, int d) {
	if ( l > x || r < x )	return;
	if ( l == r && l == x ) {
		seg[d].x = val;
		return;
	}
	int mid = (l+r)/2, ptl = d*2, ptr = d*2+1;
	update(x,val,l,mid,ptl);
	update(x,val,mid+1,r,ptr);
	int tmp[4] = {seg[ptl].x,seg[ptl].y,seg[ptr].x,seg[ptr].y};
	sort(tmp,tmp+4);
	seg[d] = pii{tmp[3],tmp[2]};
}
pii query(int a, int b, int l, int r, int d) {
	if ( l > b || r < a )	return pii{-1,-1};
	if ( a <= l && r <= b )	return seg[d];
	int mid = (l+r)/2, ptl = d*2, ptr = d*2+1;
	pii u = query(a,b,l,mid,ptl), v = query(a,b,mid+1,r,ptr);
	int tmp[4] = {u.x,u.y,v.x,v.y};
	sort(tmp,tmp+4);
	return pii{tmp[3],tmp[2]};
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, q, a, b;
	char c;
	cin >> n;
	build(1,n,1);
	cin >> q;
	while ( q-- && cin >> c >> a >> b ) {
		if ( c == 'Q' ) {
			pii tmp = query(a,b,1,n,1);
			cout << tmp.x+tmp.y << '\n';
		} else
			update(a,b,1,n,1);
	}
	return 0;
}

