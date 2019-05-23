#include <iostream>
#define int long long
using namespace std;
const long long mod = 998244353;
main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	long long ans;
	if ( s[0] == s[n-1] ) {
		char c = s[0];
		int ptl = 0, ptr = 0;
		for ( int i=1; i<n; ++i ) {
			ptl = i;
			if ( s[i] != c )	break;
		} 
		for ( int i=n-1; i>=0; --i ) {
			ptr = i;
			if ( s[i] != c )	break;
		}
		ans = ((ptl+1)*(n-ptr))%mod;
	} else {
		ans = 1;
		char c = s[0];
		int ptl = 0;
		for ( int i=1; i<n; ++i ) {
			ptl = i;
			if ( s[i] != c )	break;
		}
		ans += ptl;
		ans %= mod;
		c = s[n-1];
		int ptr = 0;
		for ( int i=n-1; i>=0; --i ) {
			ptr = i;
			if ( s[i] != c )	break;
		}
		ans += (n-1-ptr);
		ans %= mod;
	}
	cout << ans << '\n';
	return 0;
}


