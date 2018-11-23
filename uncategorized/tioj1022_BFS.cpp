#include <iostream>
#include <string.h>
#include <queue>
#define maxn 105
using namespace std;
typedef pair<int,int> pii;
int G[maxn][maxn], D[maxn][maxn], di[4] = {0,1,0,-1}, dj[4] = {1,0,-1,0};
queue<pii> Q;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n, m;
	cin >> t;
	while ( t-- && cin >> n >> m ) {
		for ( int i=1; i<=n; ++i )
			for ( int j=1; j<=m; ++j )
				cin >> G[i][j];
		memset(D,0x3f,sizeof(D));
		D[1][1] = 0;
		Q.push(make_pair(1,1));
		while ( !Q.empty() ) {
			pii x = Q.front();	Q.pop();
			int ni = x.first, nj = x.second;
			for ( int i=0; i<4; ++i ) {
				int mi = ni+di[i], mj = nj+dj[i];
				if ( mi < 1 || mi > n || mj < 1 || mj > m )	continue;
				if ( abs(G[ni][nj]-G[mi][mj]) > 5 || D[ni][nj]+1 >= D[mi][mj] )	continue;
				D[mi][mj] = D[ni][nj] + 1;
				Q.push(make_pair(mi,mj));
			}
		}
		cout << D[n][m] << '\n';
	}
	return 0;
}
