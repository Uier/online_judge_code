#include <iostream>
#include <sstream>
#include <string.h>
using namespace std;
long long g[105][105];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, w, n, x, y;
	bool q = false;
	string s;
	cin >> t;
	while ( t-- && cin >> w >> n ) {
		memset(g,-1,sizeof g);
		for ( int i=0; i<=max(w,n); ++i )
			g[0][i] = g[i][0] = 0;
		for ( int i=0; i<w; ++i ) {
			cin >> x;
			getline(cin,s);
			stringstream ss(s);
			while ( ss >> y ) {
				g[x][y] = 0;
			}
		}
		g[1][1] = 1;
		for ( int i=1; i<=w; ++i )
			for ( int j=1; j<=n; ++j ) {
				if ( g[i][j] == 0 || (i==1&&j==1) )
					continue;
				g[i][j] = g[i-1][j]+g[i][j-1];
			}		
		if ( q )	cout << '\n';
		cout << g[w][n] << '\n';
		q = true;
	}
	return 0;
}

