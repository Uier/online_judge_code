#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q, n, a, b;
	cin >> q;
	while ( q-- && cin >> n >> a >> b ) {
		if ( a*2 < b ) {
			cout << n*a << '\n';
		} else {
			cout << n/2*b+(n%2)*a << '\n';
		}
	}
	return 0;
}

