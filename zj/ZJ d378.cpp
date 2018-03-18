#include <iostream>
#include <string.h>
using namespace std;
int n, m, G[105][105], c = 1;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while ( cin >> n >> m ) {
		for ( int i=1; i<=n; ++i )
			for ( int j=1; j<=m; ++j )
				cin >> G[i][j];
		for ( int i=1; i<=n; ++i )
			for ( int j=1; j<=m; ++j )
				if ( i == 1 )	G[i][j] += G[i][j-1];
				else if ( j == 1 )	G[i][j] += G[i-1][j];
				else	G[i][j] += min(G[i-1][j],G[i][j-1]);
		cout << "Case #" << c++ << " :\n" << G[n][m] << '\n';
	}
	return 0;
}

