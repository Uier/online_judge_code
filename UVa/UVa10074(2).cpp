#include <iostream>
using namespace std;
int g[105][105], limf[105][105];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	while ( cin >> n >> m && (n!=0||m!=0) ) {
		int ans = 0;
		for ( int i=1; i<=n; ++i )
			for ( int j=1; j<=m; ++j ) {
				cin >> g[i][j];
				if ( g[i][j] )	limf[i][j] = j;
				else {
					limf[i][j] = limf[i][j-1];
					int width = j-limf[i][j], height = 1;
					for ( int k=i; k>0; --k ) {
						if ( g[k][j] )	break;
						width = min(width,j-limf[k][j]);
						ans = max(ans,width*height++);
					}
				}
			}
		cout << ans << '\n';
	}
	return 0;
}

