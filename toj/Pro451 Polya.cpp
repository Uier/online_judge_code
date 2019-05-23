#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
const int mod = 1e9+7;
int _pow(int a, int b) {
	int ans = 1, base = a;
	while ( b ) {
		if ( b&1 )	ans *= base;
		base *= base;
		base %= mod;
		ans %= mod;
		b >>= 1;
	}
	return ans;
}
main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, c, ans = 0;
	cin >> n >> m >> c;
	int col = _pow(c,n*n);
	for ( int i=1; i<=m; ++i ) {
		ans += _pow(col,__gcd(i,m));
		ans %= mod;
	}
	cout << ans*_pow(m,mod-2)%mod << '\n';
	return 0;
}

