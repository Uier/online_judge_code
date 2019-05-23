#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n;
	cin >> t;
	while ( t-- && cin >> n ) {
		int x = __gcd(360,n*2);
		if ( abs(360/x - n*2/x) < 2 )	cout << 360/x*2 << '\n';
		else	cout << 360/x << '\n';
	}
	return 0;
}


