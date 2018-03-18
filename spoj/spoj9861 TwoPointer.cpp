#include <iostream>
#define maxn 300005
using namespace std;
int a[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, x = 1, y = 1, ans = 0, sum = 0;
	cin >> n >> m;
	for ( int i=1; i<=n; ++i )
		cin >> a[i];
	while ( x <= y ) {
		while ( y <= n && m >= sum+a[y] )	sum += a[y++];
		ans = max(ans,sum);
		sum -= a[x++];
	}
	cout << ans << '\n';
	return 0;
}

