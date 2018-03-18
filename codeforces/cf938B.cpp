#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, l = 1, r = 1e6, x;
	bool ok = false;
	cin >> n;
	for ( int i=0; i<n; ++i ) {
		cin >> x;
		if ( x < 500001 )	l = x;
		else if ( !ok ) {
			ok = true;
			r = x;
		}
	}
	l = l-1;
	r = 1e6-r;
	cout << max(l,r) << '\n';
	return 0;
}

