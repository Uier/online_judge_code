#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, l, r;
	cin >> t;
	while ( t-- && cin >> l >> r ) {
		if ( l == 1 )	cout << l << ' ' << r << '\n';
		else {
			cout << l << ' ' << l*2 << '\n';
		}
	}
	return 0;
}


