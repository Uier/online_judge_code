#include <iostream>
#include <queue>
using namespace std;
struct P {
	int x, y;
};
int n, m, dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
bool V[51][51];
char G[51][51];
queue<P> Q;
int bfs() {
	int ans = 0;
	while ( !Q.empty() ) {
		P cur = Q.front();
		Q.pop();
		if ( G[cur.x][cur.y] == 'G' )
			ans++;
		bool trap = false;
		for ( int i=0; i<4; i++ ) {
			int nx = cur.x+dx[i], ny = cur.y+dy[i];
			if ( nx>=0 && nx<m && ny>=0 && ny<n
			  && G[nx][ny] == 'T' )
				trap = true;
		}
		if ( !trap ) {
			for ( int i=0; i<4; i++ ) {
				int nx = cur.x+dx[i], ny = cur.y+dy[i];
				if ( nx>=0 && nx<m && ny>=0 && ny<n
				  && G[nx][ny]!='#' && !V[nx][ny] ) {
					Q.push(P{nx,ny});
					V[nx][ny] = true;
				}
			}
		}
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while ( cin >> n >> m ) {
		for ( int i=0; i<m; i++ )
			for ( int j=0; j<n; j++ ) {
				cin >> G[i][j];
				V[i][j] = false;
				if ( G[i][j] == 'P' )
					Q.push(P{i,j});
			}
			cout << bfs() << '\n';
	}
	return 0;
}

