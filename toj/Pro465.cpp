#include <bits/stdc++.h>
#define maxn 100005
#define int long long
using namespace std;
int arr[maxn], seg[maxn*4], k;
int merge(int l, int r, int mid, int al, int ar) {
	int ans = al + ar, sum = 1;
	for ( int i=mid+1; i<=r; ++i ) {
		sum *= arr[i];
		if ( sum > k )	break;
		int j = mid, tmp = sum;
		while ( j >= l && tmp*arr[j] <= k )	tmp *= arr[j--];
		ans += mid-j;
	}
	return ans;
}
void modify(int l, int r, int d, int x, int val) {
	if ( x < l || x > r )	return;
	if ( l == r && l == x ) {
		seg[d] = val;
		return;
	}
	int mid = l+r>>1;
	modify(l,mid,d<<1,x,val);
	modify(mid+1,r,d<<1|1,x,val);
	seg[d] = merge(l,r,mid,seg[d<<1],seg[d<<1|1]);
	// cout << "l,r,seg[d].ans: " << l << ' ' << r << ' ' << seg[d].ans << '\n';
}
int query(int l, int r, int d, int ql, int qr) {
	if ( qr < l || ql > r )	return -1;
	if ( ql <= l && r <= qr ) return seg[d];
	int mid = l+r>>1;
	int al = query(l,mid,d<<1,ql,qr), ar = query(mid+1,r,d<<1|1,ql,qr);
	// cout << "l,r,mid: " << l << ' ' << r << ' ' << mid << '\n';
	if ( al == -1 )	return ar;
	if ( ar == -1 )	return al;
	return merge(ql,qr,mid,al,ar);
}
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q >> k;
	for ( int i=1; i<=n; ++i ) {
		cin >> arr[i];
		arr[i] = (arr[i] == 0 ? k+1 : arr[i]);
		modify(1,n,1,i,(arr[i]>k ? 0 : 1));
	}
	for ( int i=1, cmd, l, r; i<=q; ++i ) {
		cin >> cmd >> l >> r;
		if ( cmd == 1 ) {
			arr[l] = (r == 0 ? k+1 : r);
			modify(1,n,1,l,(arr[l]>k ? 0 : 1));
		} else	cout << query(1,n,1,l,r) << '\n';
	}
	return 0;
}
/*
5 5 10
1 5 3 2 4
2 1 5
1 3 2
2 1 5
1 2 11
2 1 5

6 5 12
2 2 1 2 3 2
2 1 5
1 3 4
2 1 4
1 2 2
2 1 4

4 5 6
0 0 0 0
2 1 4
1 2 6
2 1 4
1 3 1
2 1 4


*/