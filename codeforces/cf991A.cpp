#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, c, n;
	cin >> a >> b >> c >> n;
	if ( c > a || c > b ) {
		cout << -1 << '\n';
		return 0;
	}
	int x = a+b-c; // pass
	if ( n-x > 0 )	cout << n-x << '\n';
	else	cout << -1 << '\n';
	return 0;
}

