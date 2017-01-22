#include <iostream>
using namespace std;
const int inf = 2147483647;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, a, b, r=inf, l=1899;
	bool ans = true;
	cin >> n >> a >> b;
	if ( n == 1 )
		if ( b == 1 )
			cout << "Infinity\n";
		else
			cout << 1899 + a << '\n';
	else {
		int x = a, s = b;
		for ( int i=1; i<n; i++ ) {
			cin >> a >> b;
			if ( b == s ) {
				if ( b == 1 && x < 0 )	l = 1900
			}
		}
	}
	return 0;
}

