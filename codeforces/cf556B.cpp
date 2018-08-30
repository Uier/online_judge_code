#include <iostream>
using namespace std;
int a[1005], b[1005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=0; i<n; ++i )	cin >> a[i];
	for ( int k=0; k<=n; ++k ) {
		bool f = true;
		for ( int i=0; i<n; ++i ) {
			if ( a[i] != i ) {
				f = false;
			}
		}
		if ( f ) {
			cout << "Yes\n";
			return 0;
		}
		for ( int i=0; i<n; ++i ) {
			if ( i%2 ) {
				a[i] = (a[i]-1+n)%n;
			} else {
				a[i] = (a[i]+1)%n;
			}
		}
	}
	cout << "No\n";
	return 0;
}

