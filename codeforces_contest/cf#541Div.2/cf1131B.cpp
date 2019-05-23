#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <string.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
main() {
	ios::sync_with_stdio(false);
	//   sync_with_YinHsuan(true);
	cin.tie(0);
	int n, a = 0, x = 0, ans = 0, lim = -1, mil = -1;
	cin >> n;
	for ( int i=0, b, y; i<n; ++i ) {
		cin >> b >> y;
		if ( x <= a && b <= y ) {
			if ( b > lim )	ans += b-max(mil,a)+1;
			lim = b;
			mil = b+1;
		} else if ( a <= x && y <= b ) {
			if ( y > lim )	ans += y-max(mil,x)+1;
			lim = y;
			mil = y+1;
		} else if ( a <= x && x <= b ) {
			if ( b > lim )	ans += b-max(mil,x)+1;
			lim = b;
			mil = b+1;
		} else if ( x <= a && a <= y ) {
			if ( y > lim )	ans += y-max(mil,a)+1;
			lim = y;
			mil = y+1;
		}
		a = b;
		x = y;
	}
	cout << ans << '\n';
	return 0;
}

