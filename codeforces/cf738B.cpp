#include <iostream>
using namespace std;
int n, m, G[1005][1005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	long long ans=0;
	for ( int i=0; i<n; i++ ) {
		bool a = false;
		int x=0;
		for ( int j=0; j<m; j++ ) {
			cin >> G[i][j];
			if ( G[i][j] == 1 && a ) {
				ans += (j-x-1)*2;
				x = j;
			}
			else if ( G[i][j] == 1 ) {
				a = true;
				ans += j;
				x = j;
			}
			else if ( j == m-1 && a )
				ans += j-x;
		}
	}
	for ( int j=0; j<m; j++ ) {
		bool a = false;
		int x = 0;
		for ( int i=0; i<n; i++ ) {
			if ( G[i][j] == 1 && a ) {
				ans += (i-x-1)*2;
				x = i;
			}
			else if ( G[i][j] ) {
				a = true;
				ans += i;
				x = i;
			}
			else if ( i == n-1 && a )
				ans += i-x;
		}
	}
	cout << ans << '\n';
	return 0;
}

