#include <iostream>
#define int long long
using namespace std;
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, L, a, t = 0, l = 0, ans = 0;
	cin >> n >> L >> a;
	for ( int i=0, nt, nl; i<n; ++i ) {
		cin >> nt >> nl;
		if ( n == 0 )
			ans += nt/a;
		else
			ans += (nt-(t+l))/a;
		t = nt, l = nl;
	}
	ans += (L-(t+l))/a;
	cout << ans << '\n';
	return 0;
}

