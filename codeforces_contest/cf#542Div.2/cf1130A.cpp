#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	//   sync_with_YinHsuan(true);
	cin.tie(0);
	int n, pos = 0, neg = 0;
	cin >> n;
	for ( int i=0, x; i<n; ++i ) {
		cin >> x;
		if ( x > 0 ) {
			pos++;
		} else if ( x < 0 )	neg++;
	}
	if ( pos >= (n+1)/2 )	cout << 1 << '\n';
	else if ( neg >= (n+1)/2 )	cout << -1 << '\n';
	else	cout << 0 << '\n';
	return 0;
}

