#include <iostream>
#include <queue>
#define maxn 1005
#define maxp 10
#define int long long
using namespace std;
typedef pair<int,int> pii;
struct node {
	pii pos;
	int rnd;
};
int n, m, s[maxp], dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1}, arr[maxp];
string G[maxn];
queue<node> Q[maxp];
main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int p;
	cin >> n >> m >> p;
	for ( int i=1; i<=p; ++i )	cin >> s[i];
	for ( int i=0; i<n; ++i ) {
		string tmptmp;
		cin >> G[i];
		for ( int j=0; j<m; ++j )
			if ( '1' <= G[i][j] && G[i][j] <= '9' )
				Q[G[i][j]-'0'].push(node{make_pair(i,j),1});
	}
	int _rnd = 2;
	bool run = 1;
	while ( run ) {
		run = 0;
		for ( int i=1; i<=p; ++i )
			for ( int j=0; j<s[i]; ++j, ++_rnd ) {
				bool move = 0;
				while ( !Q[i].empty() ) {
					node tmp = Q[i].front();
					if ( tmp.rnd == _rnd )	break;
					Q[i].pop();
					int x = tmp.pos.first, y = tmp.pos.second;
					for ( int k=0; k<4; ++k ) {
						int tx = x+dx[k], ty = y+dy[k];
						if ( tx >= 0 && ty >= 0 && tx < n && ty < m && G[tx][ty] == '.' ) {
							move = 1;
							G[tx][ty] = '0'+i;
							Q[i].push(node{pii{tx,ty},_rnd});
						}
					}
				}
				run |= move;
				if ( !move )	break;
			}
	}
	for ( int i=0; i<n; ++i )
		for ( int j=0; j<m; ++j )
			if ( '1' <= G[i][j] && G[i][j] <= '9' )
				arr[G[i][j]-'0']++;
	for ( int i=1; i<=p; ++i )	cout << arr[i] << ' ';
	cout << '\n';
	return 0;
}
