#include <iostream>
#define maxn 200005
#define int long long 
using namespace std;
int n, h[maxn], b[maxn], dp[maxn], seg[maxn*4];
void modify(int l, int r, int d, int x, int val) {
	if ( x > r || x < l )	return;
	if ( l == r && l == x ) {
		seg[d] = val;
		return;
	}
	int mid = l+r>>1;
	modify(l,mid,d<<1,x,val);
	modify(mid+1,r,d<<1|1,x,val);
	seg[d] = max(seg[d<<1],seg[d<<1|1]);
}
int query(int l, int r, int d, int a, int b) {
	if ( a > r || b < l )	return 0;
	if ( a <= l && r <= b )	return seg[d];
	int mid = l+r>>1;
	return max(query(l,mid,d<<1,a,b),query(mid+1,r,d<<1|1,a,b));
}
main() {
	ios::sync_with_stdio(false);
	//   sync_with_YinHsuan(true);
	cin.tie(0);
	cin >> n;
	for ( int i=1; i<=n; ++i )	cin >> h[i];
	for ( int i=1; i<=n; ++i )	cin >> b[i];
	for ( int i=1; i<=n; ++i ) {
		int mx = query(1,n,1,1,h[i]-1);
		dp[h[i]] += mx+b[i];
		modify(1,n,1,h[i],dp[h[i]]);
	}
	cout << query(1,n,1,1,n) << '\n';
	return 0;
}

