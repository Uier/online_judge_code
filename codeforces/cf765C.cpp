#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k, a, b, sum = 0;
	cin >> k >> a >> b;
	if ( a < k && b < k )
		cout << -1 << '\n';
	else if ( a < k && b%k )
		cout << -1 << '\n';
	else if ( b < k && a%k )
		cout << -1 << '\n';
	else
		cout << a/k+b/k << '\n';
	return 0;
}

