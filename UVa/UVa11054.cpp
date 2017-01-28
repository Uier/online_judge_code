#include <iostream>
#include <math.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, a, b;
	while ( cin >> n && n && cin >> a ) {
		long long ans = 0;
		while ( --n ) {
			cin >> b;
			ans += abs(a);
			a += b;
		}
		cout << ans << '\n';
	}
	return 0;
}

