#include <iostream>
#define maxn 300005
#define int long long
using namespace std;
int a[maxn], b[maxn];
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, ans = 0;
	cin >> n;
	for ( int i=1, x; i<=n; ++i ) {
		cin >> x;
		a[i] = a[i-1] + x;
	}
	cin >> m;
	for ( int i=1, x; i<=m; ++i ) {
		cin >> x;
		b[i] = b[i-1] + x;
	}
	for ( int i=1; i<=m; ++i ) {
		int pos = lower_bound(a+1,a+1+n,b[i])-a;
		if ( pos <= n && a[pos] == b[i] )	ans++;
	}
	if ( a[n] == b[m] && ans > 0 )	cout << ans << '\n';
	else	cout << -1 << '\n';
	return 0;
}

