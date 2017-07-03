#include <iostream>
using namespace std;
int T, N, C;
bool seg[205][205*4];
void push(int x, int d) {
	seg[x][d*2] |= seg[x][d];
	seg[x][d*2+1] |= seg[x][d];
}
void build(int x, int l, int r, int d) {
	if ( l == r ) {
		seg[x][d] = false;
		return;
	}
	int mid = (l+r)/2;
	build(x,l,mid,d*2);
	build(x,mid+1,r,d*2+1);
	seg[x][d] = (seg[x][d*2] | seg[x][d*2+1]);
}
void modify(int x, int a, int b, int l, int r, int d) {
	if ( a <= l && b >= r ) {
		seg[x][d] = true;
		return;
	}
	if ( a > r || b < l )	return;
	push(x,d);
	int mid = (l+r)/2;
	modify(x,a,b,l,mid,d*2);
	modify(x,a,b,mid+1,r,d*2+1);
	seg[x][d] |= (seg[x][d*2] | seg[x][d*2+1]);
}
bool query(int x, int a, int b, int l, int r, int d) {
	if ( a <= l && b >= r ) return seg[x][d];
	if ( a > r || b < l )	return false;
	push(x,d);
	int mid = (l+r)/2;
	bool lv = query(x,a,b,l,mid,d*2);
	bool rv = query(x,a,b,mid+1,r,d*2+1);
	return (lv | rv);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while ( T-- ) {
		for ( int i=0; i<200; ++i )
			build(i,1,200,1);
		cin >> N;
		int ans = 0;
		for ( int i=0; i<N; ++i ) {
			int xa, ya, xb, yb;
			bool ocp = false;
			cin >> xa >> ya >> xb >> yb;
			xa += 100;	xb += 100;	ya += 100;	yb += 100;
			for ( int j=xa; j<=xb; ++j )
				ocp |= query(j,ya,yb,1,200,1);
			if ( xa+1 == xb )
			if ( !ocp ) {
				ans += (xb-xa)*(yb-ya);
				for ( int j=xa; j<=xb; ++j )
					modify(j,ya,yb,1,200,1);
			}
		}
		cout << "Case " << ++C << ": " << ans << '\n';
	}
	return 0;
}

