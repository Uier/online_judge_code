#include <iostream>
#define int long long
using namespace std;
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, ans = 0;
	cin >> n;
	while ( n ) {
		if ( n > 9 ) {
			ans += 9;
			n -= 9;
		}
		ans += n%10;
		n /= 10;
	}
	cout << ans << '\n';
	return 0;
}

