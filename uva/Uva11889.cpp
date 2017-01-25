#include <iostream>
#include <algorithm>
using namespace std;
main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
	int t;
	cin >> t;
	while ( t-- ) {
		int a, c;
		cin >> a >> c;
		if ( c%a )
			cout << "NO SOLUTION\n";
		else
			cout << (c*__gcd(a,))/a << '\n';
	}
	return 0;
}

