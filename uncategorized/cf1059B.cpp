#include <iostream>
#define maxn 1005
using namespace std;
int n, m;
int dx[8]={-1,-1,-1,0,0,1,1,1}, dy[8]={-1,0,1,-1,1,-1,0,1};
bool G[maxn][maxn], nG[maxn][maxn], ans = true;
inline void fill(int x, int y) {
	bool flag = true;
	for ( int i=0; i<8; ++i ) {
		int di = dx[i], dj = dy[i];
		flag &= G[x+di][y+dj];
	}
	if ( flag ) {
		for ( int i=0; i<8; ++i ) {
			int di = dx[i], dj = dy[i];
			nG[x+di][y+dj] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int cnt = 0;
	for ( int i=1; i<=n; ++i ) {
		for ( int j=1; j<=m; ++j ) {
			char c;
			cin >> c;
			if ( c == '#' )	G[i][j] = nG[i][j] = 1;
			else {
				G[i][j] = nG[i][j] = 0;
				cnt++;
			}
		}
	}
	for ( int i=2; i<n; ++i ) 
		for ( int j=2; j<m; ++j )
			fill(i,j);
	bool fail = 0;
	for ( int i=1; i<=n; ++i ) 
		for ( int j=1; j<=m; ++j )
			fail |= nG[i][j];
	if ( !fail || (cnt == 0 && (n>3||m>3)) )
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}

