#include <iostream>
using namespace std;
int a[105];
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n, mx = 0, ans = 0;
	cin >> n;
	for ( int i=0; i<n; ++i ) {
		cin >> a[i];
		mx = max(mx,a[i]);
	}
	for ( int i=0; i<n; ++i )
		ans += mx-a[i];
	cout << ans << '\n';
	return 0;
}

