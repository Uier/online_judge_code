#include <iostream>
#include <algorithm>
using namespace std;
int t, n, x, a[4005], b[4005], c[4005], d[4005], k[4005*4005], ans;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while ( t-- ) {
		x = ans = 0;
		cin >> n;
		for ( int i=0; i<n; i++ )
			cin >> a[i] >> b[i] >> c[i] >> d[i];
		for ( int i=0; i<n; i++ )
			for ( int j=0; j<n; j++ )
				k[x++] = a[i]+b[j];
		sort(k,k+x);
		for ( int i=0; i<n; i++ )
			for ( int j=0; j<n; j++ )
				ans += upper_bound(k,k+x,-c[i]-d[j])-lower_bound(k,k+x,-c[i]-d[j]);
		cout << ans << '\n';
		if ( t )	cout << '\n';
	}
	return 0;
}

