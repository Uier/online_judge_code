#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long a, b, c;
	while ( cin >> a >> b >> c ) {
		if ( a >= b && a >= c ) {
			if ( b+c > a ) {
				cout << (b>c ? 'B' : 'C') << '\n';
			} else {
				cout << 'A' << '\n';
			}
		} else if ( b >= a && b >= c ) {
			if ( a+c > b ) {
				cout << (a>c ? 'A' : 'C') << '\n';
			} else {
				cout << 'B' << '\n';
			}
		} else {
			if ( a+b > c ) {
				cout << (a>b ? 'A' : 'B') << '\n';
			} else {
				cout << 'C' << '\n';
			}
		}
	}
	return 0;
}

