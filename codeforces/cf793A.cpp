#include <iostream>
using namespace std;
int a[100005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k, base = 2e9;
	long long ans = 0;
	bool fail = false;
	cin >> n >> k;
	for ( int i=0; i<n; ++i ) {
		cin >> a[i];
		base = min(base,a[i]);
	}
	for ( int i=0; i<n; ++i ) {
		int r = a[i]-base;
		if ( r%k ) {
			fail = true;
			break;
		}
		ans += r/k;
	}
	if ( fail )
		cout << -1 << '\n';
	else
		cout << ans << '\n';
	return 0;
}

