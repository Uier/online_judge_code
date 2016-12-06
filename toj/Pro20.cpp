#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, c, d;
	while ( cin >> a >> b >> c >> d ) {
		int ans = 0;
		if ( a != c && b != d )
			ans += __gcd(abs(c-a),abs(d-b)) - 2;
		if ( a == b && b == c && c == d )
			ans += 1;
		else {
			ans += abs(d-b) + 1;
			ans += abs(c-a) + 1;
			if ( a == c || b == d )
				ans -= 1;
		}
		cout << ans << '\n';
	}
	return 0;
}

