#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n, m;
	cin >> t;
	while ( t-- ) {
		cin >> n >> m;
		while ( m-- ) {
			for ( int i=0; i<n; i++ ) {
				for ( int j=0; j<i+1; j++ )
					cout << i+1;
				cout << '\n';
			}
			for ( int i=n-1; i>0; i-- ) {
				for ( int j=0; j<i; j++ )
					cout << i;
				cout << '\n';
			}
			if ( m )	cout << '\n';
		}
		if ( t )	cout << '\n';
	}
	return 0;
}

