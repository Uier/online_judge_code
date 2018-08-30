#include <iostream>
using namespace std;
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n, tmp, ans = 0, bit[5] = {100,20,10,5,1};
	cin >> n;
	for ( int i=0; i<5; ++i )
		if ( n >= bit[i] ) {
			tmp = n/bit[i];
			n -= tmp*bit[i];
			ans += tmp;
		}
	cout << ans << '\n';
	return 0;
}

