#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	//   sync_with_YinHsuan(true);
	cin.tie(0);
	int a, b, c, d; //	((	()	)(	))
	cin >> a >> b >> c >> d;
	if ( a == d && c <= a*2 )	cout << 1 << '\n';
	else	cout << 0 << '\n';
	return 0;
}

