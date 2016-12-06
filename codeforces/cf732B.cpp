#include <iostream>
using namespace std;
int a[510];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k, ans=0, tmp=0;
	cin >> n >> k >> a[0];
	for ( int i=1; i<n; i++ ) {
		cin >> a[i];
		tmp = k-(a[i]+a[i-1]);
		if ( tmp < 0 )	tmp = 0;
		ans += tmp;
		a[i] += tmp;
	}
	cout << ans << '\n';
	for ( int i=0; i<n-1; i++ )
		cout << a[i] << ' ';
	cout << a[n-1] << '\n';
	return 0;
}

