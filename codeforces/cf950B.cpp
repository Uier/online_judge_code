#include <iostream>
#define mx 100005
using namespace std;
int a[mx], b[mx];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
	int n, m;
	cin >> n >> m;
	for ( int i=0; i<n; ++i )	cin >> a[i];
	for ( int i=0; i<m; ++i )	cin >> b[i];
	int x = 0, y = 0, ans = 0;
	while ( x<n && y<m ) {
		if ( a[x] == b[y] )	 {
			x++;	y++;
			ans++;
		} else {
			long long as = a[x++], bs = b[y++];
			while ( as != bs ) {
				if ( as < bs ) {
					as += a[x++];
				} else {
					bs += b[y++];
				}
			}
			ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}

