#include <iostream>
using namespace std;
int a[100];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while ( t-- ) {
		int n, sum=0;
		cin >> n;
		for ( int i=0; i<n; i++ ) {
			cin >> a[i];
			sum += a[i];
		}
		sum /= n;
		for ( int i=0; i<n; i++ )
			cout << a[i]-sum << ' ';
		cout << '\n';
	}
	return 0;
}

