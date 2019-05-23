#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, l, r, d;
	cin >> t;
	while ( t-- && cin >> l >> r >> d ) {
		if ( d < l )	cout << d << '\n';
		else cout << (r/d+1)*d << '\n';
	}
	return 0;
}

