#include <iostream>
using namespace std;
int a[1005];
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n, m, x;
	cin >> n >> m;
	while ( m-- && cin >> x ) {
		a[x]++;
	}
	int ans = a[1];
	for ( int i=2; i<=n; ++i )
		ans = min(ans,a[i]);
	cout << ans << '\n';
	return 0;
}

