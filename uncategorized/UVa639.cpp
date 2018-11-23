#include <iostream>
#include <string.h>
#include <map>
using namespace std;
int n, ans, pt, M[20];
string arr[5];
bool G[20][20], B[20];
void dfs(int x, int cnt) {
	if ( x == pt ) {
		ans = max(ans,cnt);
		return;
	}
	for ( int i=0; i<pt; ++i )
		if ( (G[x][i] || G[i][x]) && B[i] ) {
			dfs(x+1,cnt);
			return;
		}
	B[x] = true;
	dfs(x+1,cnt+1);
	B[x] = false;
	dfs(x+1,cnt);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while ( cin >> n && n ) {
		pt = 0;
		ans = 0;
		memset(G,0,sizeof(G));
		memset(B,0,sizeof(B));
		memset(M,0,sizeof(M));
		for ( int i=0; i<n; ++i ) {
			cin >> arr[i];
			for ( int j=0; j<n; ++j )
				if ( arr[i][j] == '.' )
					M[i*n+j] = pt++;
		}
		for ( int i=0; i<n; ++i ) {
			for ( int j=0; j<n; ++j ) {
				if ( arr[i][j] == 'X' )	continue;
				for ( int k=j+1; k<n; ++k ) {
					if ( arr[i][k] == 'X' )	break;
					G[M[i*n+j]][M[i*n+k]] = G[M[i*n+k]][M[i*n+j]] = true;
				}
				for ( int k=i+1; k<n; ++k ) {
					if ( arr[k][j] == 'X' )	break;
					G[M[i*n+j]][M[k*n+j]] = G[M[k*n+j]][M[i*n+j]] = true;
				}
			}
		}
		dfs(0,0);
		cout << ans << '\n';
	}
	return 0;
}

