#include <iostream>
#include <queue>
#include <math.h>
#define maxn 105
using namespace std;
typedef pair<int,int> pii;
pii pos[maxn];
int tour[maxn][3];
int state;
queue<pii> Q;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=1; i<=n; ++i ) {
		for ( int j=1; j<=n; ++j ) {
			cin >> g[i][j];
			pos[g[i][j]] = pii{i,j};
		}
	}
	// state: 1->knight, 2->bishop, 3->rook
	int ni = pos[1].first, nj = pos[1].second;
	for ( int i=2; i<=n*n; ++i ) {
		int di = pos[i].first, dj = pos[i+1].second;
		if ( (ni+nj)%2 != (di+dj)%2 )	tour[i][2] = -1;
		else	tour[i][2] = 2;
		if ( ni == di || nj == dj )
			tour[i][3] = 1;
		else if ( abs(ni+nj) == abs(di+dj) || abs(ni-nj) == abs(di-dj) )
			tour[i][2] = 1;
		else
			state = 1;
		tour[i][1]
		ni = di, nj = dj;
	}
	
//	D[1] = 0;
//	Q.push(pii{1,0});
//	int ans = -1;
//	while ( !Q.empty() ) {
//		pii tmp = Q.front();	Q.pop();
//		int x = tmp.first, d = tmp.second;
//		if ( x == n*n ) {
//			if ( ans == -1 || d < ans )	ans = d;
//			continue;
//		}
//		int ni = pos[x].first, nj = pos[x].second;
//		int di = pos[x+1].first, dj = pos[x+1].second;
//		if ( ni == di || nj == dj )
//			state = 3;
//		else if ( abs(ni+nj) == abs(di+dj) || abs(ni-nj) == abs(di-dj) )
//			state = 2;
//		else
//			state = 1;
//	}
	return 0;
}

