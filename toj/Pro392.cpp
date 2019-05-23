#include <iostream>
using namespace std;
int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int t, a, x;
	cin >> t;
	while ( t-- && cin >> a >> x ) {
		int b = a, y = x, ans = 1, cnt = 0, tmp = 1;
		while ( b ) {
			if ( !(b&1) )	ans <<= 1;
			b >>= 1;
		}
		ans -= 1;
		
	}
	return 0;
}

