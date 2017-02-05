#include <iostream>
using namespace std;
int a[200005];
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=0; i<n; i++ ) {
		cin >> a[i];
	}
	for ( int i=0; i<n-1; i++ ) {
		if ( n%2 || i<n/2 ) {
			if ( i%2 == 0 )
				cout << a[n-i-1] << ' ';
			else
				cout << a[i] << ' ';
		}
		else {
			if ( i%2 == 0 )
				cout << a[i] << ' ';
			else
				cout << a[n-i-1] << ' ';
		}
	}
	cout << a[0] << '\n';
	return 0;
}

