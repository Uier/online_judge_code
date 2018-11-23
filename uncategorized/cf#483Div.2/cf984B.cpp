#include <iostream>
using namespace std;
int di[8] = {-1,-1,-1,0,0,1,1,1};
int dj[8] = {-1,0,1,-1,1,-1,0,1};
char g[105][105];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for ( int i=1; i<=n; ++i )
		for ( int j=1; j<=m; ++j )
			cin >> g[i][j];
	bool fail = 0;
	for ( int i=1; i<=n; ++i )
		for ( int j=1; j<=m; ++j )
			if ( g[i][j] == '.' || (g[i][j] >= '0' && g[i][j] <= '9') ) {
				int cnt = 0;
				for ( int k=0; k<8; ++k )
					if ( g[i+di[k]][j+dj[k]] == '*' )	cnt++;
				if ( g[i][j] == '.' && cnt != 0 )	fail = 1;
				if ( g[i][j] >= '0' && g[i][j] <= '9' && cnt != g[i][j]-'0' )	fail = 1;
			}
	if ( fail )	cout << "NO\n";
	else	cout << "YES\n";
	return 0;
}

