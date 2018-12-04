#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	if ( n == 2 )	cout << n << ' ' << n << '\n';
	else if ( n%2 == 0 )	cout << n/2 << ' ' << n/2 << '\n';
	else {
		if ( n == 1 )	cout << -1 << '\n';
		else	cout << (n+1)/2 << ' ' << (n+1)/2 << '\n';
	}
	return 0;
}

