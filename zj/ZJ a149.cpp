#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long T, n, x;
	cin >> T;
	while ( T-- && cin >> n ) {
		long long ans = ((n == 0) ? 0 : 1);
		while ( n ) {
			ans *= n%10;
			n /= 10;
		}
		cout << ans << '\n';
	}
	return 0;
}

