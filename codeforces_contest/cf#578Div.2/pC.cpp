#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, q, x1, y1, x2, y2;
	cin >> n >> m >> q;
	int gcd = __gcd(n,m);
	int ii = n/gcd, oo = m/gcd;
	while ( q-- && cin >> x1 >> y1 >> x2 >> y2 ) {
		if ( gcd == 1 ) {
			cout << "YES\n";
			continue;
		}
		y1--;
		y2--;
		if ( x1 == 1 ) {
			y1 /= ii;
		} else {
			y1 /= oo;
		}
		if ( x2 == 1 ) {
			y2 /= ii;
		} else {
			y2 /= oo;
		}
		if ( y1 == y2 ) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}