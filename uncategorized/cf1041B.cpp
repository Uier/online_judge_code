#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, x, y;
	cin >> a >> b >> x >> y;
	int gcd = __gcd(x,y);
	x /= gcd;
	y /= gcd;
	int w = a/x, h = b/y;
	cout << min(w,h) << '\n';
	return 0;
}

