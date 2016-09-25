#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pr;
const ll INF=10000000000;
ll segH[2000100], segL[2000100], n, m;
void init(int x) {
	n = 1;
	while ( n < x )
		n *= 2;
	for ( int i=0; i<n*2-1; i++ ) {
		segH[i] = 0;
		segL[i] = INF;
	}
}
void update(int p, ll v) {
	p += n-1;
	segH[p] = v;
	segL[p] = v;
	while ( p > 0 ) {
		p = (p-1) / 2;
		segH[p] = max(segH[p*2+1], segH[p*2+2]);
		segL[p] = min(segL[p*2+1], segL[p*2+2]);
	}
}
pr query(int a, int b, int p, int l, int r) {
	if ( r <= a || l >= b )
		return {0,0};
	if ( a <= l && b >= r )
		return {segH[p],segL[p]};
	else {
		pr vl = query(a,b,p*2+1,l,(l+r)/2);
		pr vr = query(a,b,p*2+2,(l+r)/2,r);
		if ( vl.second == 0 )
			vl.second = INF;
		if ( vr.second == 0 )
			vr.second = INF;
		return {max(vl.first,vr.first),min(vl.second,vr.second)};
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int n2 = n;
	init(n);
	for ( int i=0; i<n2; i++ ) {
		ll a;
		cin >> a;
		update(i,a);
	}
	while ( m-- ) {
		int a, b;
		cin >> a >> b;
		pr c = query(a-1,b,0,0,n);
		cout << c.first-c.second << '\n';
	}
	return 0;
}

