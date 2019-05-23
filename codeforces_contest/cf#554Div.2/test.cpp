#include <iostream>
#include <cmath>
#include <algorithm>
#define int long long
using namespace std;
main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a, b, ans = 1e18, k = 0;
	cin >> a >> b;
	if ( a > b )	swap(a,b);
	for ( int i=0; i<1e7; ++i ) {
		int gcd = __gcd(a+i,b+i);
		if ( gcd*((a+i)/gcd)*((b+i)/gcd) < ans ) {
			ans = gcd*((a+i)/gcd)*((b+i)/gcd);
			k = i;
		}
	}
	cout << k << '\n';
	return 0;
}

