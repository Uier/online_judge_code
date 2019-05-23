#include <iostream>
#define int long long
using namespace std;
main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k, ans = 0;
	cin >> k >> n;
	for ( int i=0, b; i<n; ++i ) {
		cin >> b;
		ans = ans*k+b;
	}
	if ( ans&1 )	cout << "odd\n";
	else	cout << "even\n";
	return 0;
}

