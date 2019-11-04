#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	if ( n&1 ) {
		cout << "YES\n";
		int cur = 1;
		for ( int i=1; i<=n; ++i ) {
			cout << i*2-cur << ' ';
			cur ^= 1;
		}
		for ( int i=1; i<=n; ++i ) {
			cout << i*2-cur << ' ';
			cur ^= 1;
		}
		cout << '\n';
	} else	cout << "NO\n";
	return 0;
}