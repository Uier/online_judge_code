#include <iostream>
#define int long long
using namespace std;
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int l, r, len;
	cin >> l >> r;
	len = r-l+1;
	cout << "YES\n";
	for ( int i=0; i<len/2; ++i, l+=2 )
		cout << l << ' ' << l+1 << '\n';
	return 0;
}

