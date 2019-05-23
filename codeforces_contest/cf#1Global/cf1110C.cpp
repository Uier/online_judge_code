#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q, a;
	cin >> q;
	while ( q-- && cin >> a ) {
		int b = 0, c = a, cnt = 0;
		while ( c ) {
			if ( !(c&1) )	b += (1<<cnt);
			c >>= 1;
			cnt++;
		}
		if ( b == 0 ) {
			int ans = 1;
			for ( int i=2; i*i<=a; ++i ) {
				if ( a%i == 0 ) {
					ans = max(ans,__gcd(i,a-i));
					ans = max(ans,__gcd(a/i,a-a/i));
				}
			}
			cout << ans << '\n';
		}
		else	cout << __gcd((a^b),(a&b)) << '\n';
	}
	return 0;
}

