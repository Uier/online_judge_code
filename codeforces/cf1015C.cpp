#include <iostream>
#include <algorithm>
#define maxn 100005
using namespace std;
int d[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, ans = 0;
	long long del = 0, sum = 0;
	cin >> n >> m;
	for ( int i=0, x, y; i<n; ++i ) {
		cin >> x >> y;
		d[i] = x-y;
		del += x-y;
		sum += x;
	}
	if ( sum-del > m )	return cout << -1 << '\n', 0;
	sort(d,d+n);
	for ( int i=n-1; i>=0; --i, ++ans ) {
		if ( sum <= m )	break;
		sum -= d[i];
	}
	cout << ans << '\n';
	return 0;
}

