#include <iostream>
#include <math.h>
#define int long long
using namespace std;
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n, x, y, d;
	cin >> t;
	while ( t-- && cin >> n >> x >> y >> d ) {
		if ( abs(y-x)%d == 0 ) {
			cout << abs(y-x)/d << '\n';
		} else {
			int a = y-1, b = n-y, c = x-1, dd = n-x;
			if ( c%d )	c = c/d+1;
			else	c = c/d;
			if ( dd%d )	dd = dd/d+1;
			else	dd = dd/d;
			if ( a%d != 0 && b%d != 0 ) {
				cout << -1 << '\n';
			} else if ( a%d == 0 && b%d == 0 ) {
				cout << min(a/d+c,b/d+dd) << '\n';
			} else if ( a%d == 0 ) {
				cout << a/d+c << '\n';
			} else {
				cout << b/d+dd << '\n';
			}
		}
	} 
	return 0;
}

