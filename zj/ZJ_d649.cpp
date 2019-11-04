#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while ( cin >> n && n ) {
		for ( int i=0; i<n; ++i ) {
			for ( int j=0; j<n-1-i; ++j ) {
				cout << '_';
			}
			for ( int j=0; j<i+1; ++j ) {
				cout << '+';
			}
			cout << '\n';
		}
		cout << '\n';
	}
	return 0;
}