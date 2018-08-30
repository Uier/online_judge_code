#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	long long lim = 0;
	cin >> n >> m;
	for ( int i=1; i<=n; ++i )	lim += (n/i-1)+(n%i);
	if ( m > lim )	cout << "Impossible\n";
	else {
		cout << "Possible\n";
		for ( int i=2, j=0; i<=n&&j<m; ++i, ++j )
			cout << 1 << ' ' << i << '\n';
		m -= (n-1);
		for ( int i=2; i<n; ++i ) {
			for ( int j=1; i*j<=n; ++j ) {
				for ( int k=1; k<i; ++k ) {
					if ( m <= 0 )	return 0;
					if ( i*j+k > n || ) break;
					m--;
					cout << i << ' ' << i*j+k << '\n';
				}
			}
		}
	}
	return 0;
}

