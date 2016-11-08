#include <iostream>
using namespace std;
typedef pair<int,int> pr;
int n, q, seg[50000005], tag[50000005];
void init(int x) {
	n = 1;
	while ( n < x )
		n *= 2;
	for ( int i=0; i<n*2-1; i++ )
		seg[i] = tag[i] = -1;
}
void update(int p, int v) {
	p += n-1;
	seg[p] = v;
	tag[p] = p-n+1;
	while ( p > 0 ) {
		p = (p-1) / 2;
		if ( seg[p*2+1] > seg[p*2+2] ) {
			seg[p] = seg[p*2+1];
			tag[p] = tag[p*2+1];
		}
		else if ( seg[p*2+1] == seg[p*2+2] ) {
			if ( tag[p*2+1] > tag[p*2+2] ) {
				seg[p] = seg[p*2+1];
				tag[p] = tag[p*2+1];
			}
			else {
				seg[p] = seg[p*2+2];
				tag[p] = tag[p*2+2];
			}
		}
		else {
			seg[p] = seg[p*2+2];
			tag[p] = tag[p*2+2];
		}
	}
}
pr query(int a, int b, int p, int l, int r) {
	if ( r <= a || l >= b )
		return {-1,-1};
	if ( b >= r && a <= l )
		return {seg[p],tag[p]};
	else {
		pr vl = query(a,b,p*2+1,l,(l+r)/2);
		pr vr = query(a,b,p*2+2,(l+r)/2,r);
		if ( vl.first == vr.first )
			return (vl.second>vr.second) ? vl : vr;
		else
			return (vl.first>vr.first) ? vl : vr;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	init(n);
	while ( q-- ) {
		int a, b, c;
		cin >> a >> b >> c;
		if ( a == 0 )
			update(b-1,c);
		else {
			if ( b > c )
				swap(b,c);
			pr d = query(b-1,c,0,0,n);
			cout << d.first << '\n';
			if ( d.first > -1 )
				update(d.second,-1);
//		for ( int i=0; i<n*2-1; i++ )
//			cout << i << ": " << seg[i] << ' ' << tag[i] << '\n';
		}
	}
	return 0;
}

