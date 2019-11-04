#include <iostream>
#define maxn 200005
#define int long long
using namespace std;
const int inf = 1e18;
struct node {
	int pre, suf, ans, sum, ptl, ptr, ptpre, ptsuf;
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
	if ( seg[d<<1].ans >= seg[d<<1|1].ans ) {
		if ( seg[d<<1].ans >= seg[d<<1].suf+seg[d<<1|1].pre ) {
			seg[d].ans = seg[d<<1].ans;
			seg[d].ptl = seg[d<<1].ptl;
			seg[d].ptr = seg[d<<1].ptr;
		} else {
			seg[d].ans = seg[d<<1].suf+seg[d<<1|1].pre;
			seg[d].ptl = seg[d<<1].ptsuf;
			seg[d].ptr = seg[d<<1|1].ptpre;
		}
	} else {
		if ( seg[d<<1].suf+seg[d<<1|1].pre >= seg[d<<1|1].ans ) {
			seg[d].ans = seg[d<<1].suf+seg[d<<1|1].pre;
			seg[d].ptl = seg[d<<1].ptsuf;
			seg[d].ptr = seg[d<<1|1].ptpre;
		} else {
			seg[d].ans = seg[d<<1|1].ans;
			seg[d].ptl = seg[d<<1|1].ptl;
			seg[d].ptr = seg[d<<1|1].ptr;
		}
	}
	if ( seg[d<<1].pre >= seg[d<<1].sum + seg[d<<1|1].pre ) {
		seg[d].pre = seg[d<<1].pre;
		seg[d].ptpre = seg[d<<1].ptpre;
	} else {
		seg[d].pre = seg[d<<1].sum+seg[d<<1|1].pre;
		seg[d].ptpre = seg[d<<1|1].ptpre;
	}
	if ( seg[d<<1|1].sum+seg[d<<1].suf >= seg[d<<1|1].suf ) {
		seg[d].suf = seg[d<<1|1].sum+seg[d<<1].suf;
		seg[d].ptsuf = seg[d<<1].ptsuf;
	} else {
		seg[d].suf = seg[d<<1|1].suf;
		seg[d].ptsuf = seg[d<<1|1].ptsuf;
	}
	seg[d].sum = seg[d<<1].sum + seg[d<<1|1].sum;
}
node query(int l, int r, int d, int ql, int qr) {
	if ( ql > r || qr < l )	return node{-inf,-inf,-inf,-inf,-inf,-inf,-inf,-inf};
	if ( ql <= l && r <= qr )	return seg[d];
	int mid = l+r>>1;
//	cout << "l,mid,r: "<< l << ' ' << mid << ' ' << r << '\n';
	node al = query(l,mid,d<<1,ql,qr), ar = query(mid+1,r,d<<1|1,ql,qr);
	if ( al.ans == -inf )	return ar;
	if ( ar.ans == -inf )	return al;
	node ans;
	if ( al.ans >= ar.ans ) {
		if ( al.ans >= al.suf+ar.pre ) {
			ans.ans = al.ans;
			ans.ptl = al.ptl;
			ans.ptr = al.ptr;
		} else {
			ans.ans = al.suf+ar.pre;
			ans.ptl = al.ptsuf;
			ans.ptr = ar.ptpre;
		}
	} else {
		if ( al.suf+ar.pre >= ar.ans ) {
			ans.ans = al.suf+ar.pre;
			ans.ptl = al.ptsuf;
			ans.ptr = ar.ptpre;
		} else {
			ans.ans = ar.ans;
			ans.ptl = ar.ptl;
			ans.ptr = ar.ptr;
		}
	}
	if ( al.pre >= al.sum + ar.pre ) {
		ans.pre = al.pre;
		ans.ptpre = al.ptpre;
	} else {
		ans.pre = al.sum+ar.pre;
		ans.ptpre = ar.ptpre;
	}
	if ( ar.sum+al.suf >= ar.suf ) {
		ans.suf = ar.sum+al.suf;
		ans.ptsuf = al.ptsuf;
	} else {
		ans.suf = ar.suf;
		ans.ptsuf = ar.ptsuf;
	}
	ans.sum = al.sum + ar.sum;
//	cout << "ans l,mid,r: " << l << ' ' << mid << ' ' << r;
//	cout << " : " << ans.ptl << ' ' << ans.ptr << ' ' << ans.ans << '\n';
	return ans;
}
main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q, cs = 1;
	while ( cin >> n >> q ) {
		cout << "Case " << cs++ << ":\n";
		for ( int i=1, x; i<=n; ++i ) {
			cin >> x;
			modify(1,n,1,i,node{x,x,x,x,i,i,i,i});
		}
		for ( int i=1, l, r; i<=q; ++i ) {
			cin >> l >> r;
			node res = query(1,n,1,l,r);
			cout << res.ptl << ' ' << res.ptr << ' ' << res.ans << '\n';
		}
	}
	return 0;
}

