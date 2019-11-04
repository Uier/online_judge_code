#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, a, b, c;
	cin >> t;
	while ( t-- && cin >> a >> b >> c ) {
		int sum = 0;
		while ( b >= 1 && c >= 2 ) {
			sum += 3;
			b -= 1;
			c -= 2;
		}
		while ( a >= 1 && b >= 2 ) {
			sum += 3;
			a -= 1;
			b -= 2;
		}
		cout << sum << '\n';
	}
	return 0;
}