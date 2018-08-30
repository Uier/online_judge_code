#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,e1, e2, a = 0, b = 0, c = 0, d = 0;
	cin >> n >> e1 >> e2;
	for ( int i=0, x, y; i<n; ++i ) {
		cin >> x >> y;
		// both up
		if ( (x >= e1 && y > x) || (x >= e2 && y > x) )	a++;
		// e1 up, e2 down
		if ( (x >= e1 && y > x) || (x <= e2 && y < x) )	b++;
		// e1 down, e2 up
		if ( (x <= e1 && y < x) || (x >= e2 && y > x) )	c++;
		// both down
		if ( (x <= e1 && y < x) || (x <= e2 && y < x) )	d++;
	}
	cout << max(a,max(b,max(c,d))) << '\n';
	return 0;
}

