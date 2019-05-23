#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, x, odd = 0, even = 0;
	cin >> n >> m;
	for ( int i=0; i<n; ++i ) {
		cin >> x;
		if ( x&1 )	odd++;
		else	even++;
	}
	int ans = 0;
	for ( int i=0; i<m; ++i ) {
		cin >> x;
		if ( x&1 && even > 0 ) {
			ans++;
			even--;
		} else if ( !(x&1) && odd > 0 ) {
			ans++;
			odd--;
		}
	}
	cout << ans << '\n';
	return 0;
}

