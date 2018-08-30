#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int l, r, ans = 0;
	cin >> l >> r;
	for ( int i=l; i<=r; ++i )
		if ( i%2 != 1 && i%3 != 1 )	ans++;
	cout << ans << '\n';
	return 0;
}

