#include <iostream>
#include <iomanip>
using namespace std;
int a[1003][1003];
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n, m, k;
	double ans = 0, x;
	cin >> n >> m >> k;
	for ( int i=0; i<n; i++ )
		for ( int j=0; j<m; j++ ) {
			cin >> x;
			ans = max(ans,x);
		}
	cout << fixed << setprecision(k) << ans << '\n';
	return 0;
}

