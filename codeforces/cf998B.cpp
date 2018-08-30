#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int a[105], cost[105];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, b;
	cin >> n >> b;
	for ( int i=0; i<n; ++i ) {
		cin >> a[i];
	}
	int even = 0, odd = 0, pt = 0;
	for ( int i=0; i<n; ++i ) {
		if ( a[i]%2 )	odd++;
		else	even++;
		if ( even == odd && i != n-1 )	cost[pt++] = abs(a[i+1]-a[i]);
	}
	int ans = 0;
	sort(cost,cost+pt);
	for ( int i=0; i<pt; ++i ) {
		if ( b >= cost[i] ) {
			b -= cost[i];
			ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}

