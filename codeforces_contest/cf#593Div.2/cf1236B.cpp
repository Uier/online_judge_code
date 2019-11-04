#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
int dp[50];
int P(int a, int b) {
	int ans = 1, base = a;
	while ( b ) {
		if ( b&1 )	ans *= base;
		base *= base;
		base %= mod;
		ans %= mod;
		b >>= 1;
	}
	return ans%mod;
}
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	cout << P((P(2,m)-1+mod)%mod, n) << '\n';
	return 0;
}