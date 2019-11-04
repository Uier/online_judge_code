#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
struct node {
	int ans, pre, suf, val_l, val_r;
} seg[maxn*4];
void modify(int l, int r, int d, int x, node val) {
	if ( x < l || x > r )	return;
	if ( l == r && l == x ) {
		seg[d] = val;
		return;
	}
	int mid = l+r>>1;
	modify(l,mid,d<<1,x,val);
	modify(mid+1,r,d<<1|1,x,val);
	seg[d].ans = max(seg[d<<1].ans, seg[d<<1|1].ans);
	seg[d].pre = seg[d<<1].pre;
	seg[d].suf = seg[d<<1|1].suf;
	seg[d].val_l = seg[d<<1].val_l;
	seg[d].val_r = seg[d<<1|1].val_r;
	if ( seg[d<<1].val_r+1 == seg[d<<1|1].val_l ) {
		seg[d].ans = max(seg[d].ans, seg[d<<1].suf+seg[d<<1|1].pre);
		if ( seg[d<<1].pre == mid+1-l )
			seg[d].pre = seg[d<<1].pre + seg[d<<1|1].pre;
		if ( seg[d<<1|1].suf == r-mid )
			seg[d].suf = seg[d<<1|1].suf + seg[d<<1].suf;
	}
}
node query(int l, int r, int d, int ql, int qr) {
	if ( qr < l || ql > r )	return node{-1};
	if ( ql <= l && r <= qr ) return seg[d];
	int mid = l+r>>1;
	node al = query(l,mid,d<<1,ql,qr), ar = query(mid+1,r,d<<1|1,ql,qr), ans;
	if ( al.ans == -1 )	return ar;
	if ( ar.ans == -1 )	return al;
	ans.ans = max(al.ans, ar.ans);
	ans.pre = al.pre;
	ans.suf = ar.suf;
	ans.val_l = al.val_l;
	ans.val_r = ar.val_r;
	if ( al.val_r+1 == ar.val_l ) {
		ans.ans = max(ans.ans,al.suf+ar.pre);
		if ( al.pre == mid-l+1 )
			ans.pre = al.pre + ar.pre;
		if ( ar.suf == r-mid )
			ans.suf = ar.suf + al.suf;
	}
	return ans;
}
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n;
	for ( int i=1, x; i<=n; ++i ) {
		cin >> x;
		modify(1,n,1,i,node{1,1,1,x,x});
	}
	cin >> q;
	for ( int i=1, cmd, l, r; i<=q; ++i ) {
		cin >> cmd >> l >> r;
		if ( cmd == 1 )
			modify(1,n,1,l,node{1,1,1,r,r});
		else
			cout << query(1,n,1,l,r).ans << '\n';
	}
	return 0;
}
/*
5
1 2 2 3 4
6
2 1 4
1 3 3
2 1 5
1 5 5
1 4 4
2 1 5

5
5 4 3 2 1
3
2 1 5
1 3 5
2 2 4

*/