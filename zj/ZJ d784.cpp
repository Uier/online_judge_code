#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n, x, y, sum;
	cin >> t;
	while ( t-- && cin >> n >> x ) {
		y = x, sum = -10000;
		while ( --n && cin >> x ) {
			if ( y > 0 )	y += x;
			else	y = x;
			sum = max(sum,y);
		}
		cout << sum << '\n';
	} 
	return 0;
}

