#include <iostream>
#include <algorithm>
using namespace std;
int a[2005], g[2005][2005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
	int n, cnt = 0, gg = 1e9;
	cin >> n;
	for ( int i=1; i<=n; ++i ) {
		cin >> a[i];
		if ( a[i] == 1 )	cnt++;
	}
	if ( cnt > 0 ) {
		cout << n-cnt << '\n';
	} else {
		for ( int i=1; i<=n; ++i )	g[i][i] = a[i];
		int ans = 1e9;
		for ( int i=1; i<n; ++i ) {
			int sum = 0;
			for ( int j=i+1; j<=n; ++j ) {
				g[i][j] = __gcd(g[i][j-1],a[j]);
				if ( g[i][j] == 1 ) {
					sum += (j-i)+(n-1);
					break;
				}
			}
			if ( sum != 0 )
				ans = min(ans,sum);
		}
		if ( ans && ans != 1e9 )	cout << ans << '\n';
		else	cout << -1 << '\n';
	}
	return 0;
}

