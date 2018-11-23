#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int q;
	long long n, m, k;
	cin >> q;
	while ( q-- && cin >> n >> m >> k ) {
		long long mind = max(n,m);
		if ( k < mind )	cout << -1 << '\n';
		else {
			if ( (n+m)%2 )	cout << k-1 << '\n';
			else {
				if ( k%2 == mind%2 )
					cout << k << '\n';
				else
					cout << k-2 << '\n';
			}
		}
	}
	return 0;
}

