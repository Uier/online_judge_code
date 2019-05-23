#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n;
	cin >> t;
	while ( t-- && cin >> n ) {
		if ( n&1 )	cout << 1+(n-3)/2 << '\n';
		else	cout << n/2 << '\n';
	}
	return 0;
}

