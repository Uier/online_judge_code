#include <iostream>
using namespace std;
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int a, b;
	while ( cin >> a >> b ) {
		int ans=0;
		bool rev=0;
		if ( a > b ) {
			swap(a,b);
			rev=1;
		}
		for ( int i=a; i<=b; i++ ) {
			int x=1, j=i;
			while ( j != 1 ) {
				if ( j%2 == 1 ) {
					j *= 3;
					j++;
				}
				else
					j /= 2;
				x++;
			}
			ans = max(ans,x);
		}
		if ( rev )
			cout << b << ' ' << a << ' ' << ans << '\n';
		else
			cout << a << ' ' << b << ' ' << ans << '\n';
	}
	return 0;
}

