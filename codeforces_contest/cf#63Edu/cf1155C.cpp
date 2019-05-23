#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#define int long long
#define maxn 300005
using namespace std;
int arr[maxn];
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, st, x, y, pre;
	cin >> n >> m >> x >> y;
	st = x;
	pre = y;
	x = y-x;
	for ( int i=2; i<n; ++i ) {
		cin >> y;
		x = __gcd(x,y-pre);
		pre = y;
	}
	for ( int i=0; i<m; ++i )	cin >> arr[i];
	for ( int i=0; i<m; ++i ) {
		if ( x%arr[i] == 0 ) {
			cout << "YES\n";
			cout << st << ' ' << i+1 << '\n';
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}

