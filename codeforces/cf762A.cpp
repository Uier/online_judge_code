#include <iostream>
#include <algorithm>
using namespace std;
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int a, b, c;
	cin >> a >> b >> c;
	int d = __gcd(a,b);
	d = a*(b/d);
	cout << c/d << '\n';
	return 0;
}

