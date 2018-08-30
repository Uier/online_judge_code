#include <iostream>
using namespace std;
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int a, b, c;
	cin >> a >> b;
	c = min(a,b);
	long long ans = 1;
	for ( int i=2; i<=c; ++i )
		ans *= i;
	cout << ans << '\n';
	return 0;
}

