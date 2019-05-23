#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	//   sync_with_YinHsuan(true);
	cin.tie(0);
	int x, y, z, a, b, c;
	cin >> x >> y >> z >> a >> b >> c;
	bool fail = false;
	if ( a < x )	fail = true;
	a -= x;
	if ( a+b < y )	fail = true;
	if ( a >= y ) {
		a -= y;
	} else {
		b -= (y-a);
		a = 0;
	}
	if ( a+b+c < z )	fail = true;
	if ( fail )	cout << "NO\n";
	else	cout << "YES\n";
	return 0;
}

