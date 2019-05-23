#include <iostream>
#define maxn 505
using namespace std;
string G[505];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, ans = 0;
	cin >> n;
	for ( int i=0; i<n; ++i )	cin >> G[i];
	for ( int i=1; i<n-1; ++i ) {
		for ( int j=1; j<n-1; ++j ) {
			if ( G[i][j] == G[i-1][j-1] && G[i][j] == G[i-1][j+1] &&
				G[i][j] == G[i+1][j-1] && G[i][j] == G[i+1][j+1] &&
				G[i][j] == 'X' )
				ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}

