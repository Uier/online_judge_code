#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int fac[13] = {1};
	bool vis[12];
	for ( int i=1; i<=12; ++i )	fac[i] = fac[i-1]*i;
	int n, m;
	while ( cin >> n >> m && n && m ) {
		for ( int i=0; i<12; ++i )	vis[i] = false;
		m = (m-1)%fac[n];
		for ( int i=n-1; i>=0; --i ) {
			int pos = m/fac[i], j = 0, cnt = 0;
			m -= pos*fac[i];
			for ( ; j<12; ++j ) {
				while ( vis[j] )	j++;
				if ( pos-- == 0 ) {
					vis[j] = 1;
					cout << (char)('A'+j) << ' ';
				}
			}
		}
		cout << '\n';
	}
	return 0;
}

