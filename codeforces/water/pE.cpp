#include <iostream>
using namespace std;
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int a, b, c;
	cin >> a >> b >> c;
	b /= 2;
	c /= 4;
	int d = min(a,min(b,c));
	cout << d*7 << '\n';
	return 0;
}

