#include <iostream>
using namespace std;
int a[1005], b[1005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for ( int i=0; i<n; ++i )	cin >> a[i];
	for ( int i=0; i<m; ++i )	cin >> b[i];
	int ans = 0;
	for ( int i=0, j=0; i<m; ++i, ++j ) {
		while ( j < n && a[j] > b[i] )	j++;
		if ( j < n ) ans++;
	}
	cout << ans << '\n';
	return 0;
}

