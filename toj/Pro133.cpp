#include <iostream>
using namespace std;
long long n, q, a[200010], l, r;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	a[0] = 0;
	cin >> n >> a[1];
	for ( int i=2; i<n+1; i++ ) {
		cin >> a[i];
		a[i] += a[i-1];	
	}
	cin >> q;
	while ( q-- ) {
		cin >> l >> r;
		if ( l > r )
			swap(l,r);
		cout << a[r]-a[l-1] << '\n';
	}
	return 0;
}

