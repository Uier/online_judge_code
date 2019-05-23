#include <iostream>
#include <vector>
#include <string.h>
#include <map>
#define maxn 30
using namespace std;
vector<int> G[2][maxn], fini;
map<string,int> M;
map<int,string> rM;
int n, m, scc[maxn];
bool vis[maxn];
void dfs1(int x) {
	vis[x] = true;
	for ( int i : G[0][x] )
		if ( !vis[i] )
			dfs1(i);
	fini.emplace_back(x);
}
void dfs2(int x, int cnt) {
	vis[x] = true;
	for ( int i : G[1][x] )
		if ( !vis[i] )
			dfs2(i,cnt);
	scc[x] = cnt;
}
int main() {
	ios::sync_with_stdio(false);
	//   sync_with_YinHsuan(true);
	cin.tie(0);
	int cs = 1;
	bool nf = 0;
	while ( cin >> n >> m && (n||m) ) {
		for ( int i=0; i<=n; ++i ) {
			G[0][i].clear();
			G[1][i].clear();
		}
		memset(scc,0,sizeof(scc));
		M.clear();
		rM.clear();
		fini.clear();
		if ( nf )	cout << '\n';
		nf = 1;
		string _tmp, __tmp;
		int cnt = 1;
		for ( int i=0; i<m; ++i ) {
			cin >> _tmp >> __tmp;
			if ( !M[_tmp] ) {
				M[_tmp] = cnt++;
				rM[cnt-1] = _tmp;
			}
			if ( !M[__tmp] ) {
				M[__tmp] = cnt++;
				rM[cnt-1] = __tmp;
			}
			G[0][M[_tmp]].emplace_back(M[__tmp]);
			G[1][M[__tmp]].emplace_back(M[_tmp]);
		}
		for ( int i=1; i<cnt; ++i )
			if ( !vis[i] )
				dfs1(i);
		memset(vis,0,sizeof(vis));
		int sz = fini.size(), _scc = 0;
		for ( int i=sz-1; i>=0; --i )
			if ( !vis[fini[i]] )
				dfs2(fini[i],_scc++);
		memset(vis,0,sizeof(vis));
		cout << "Calling circles for data set " << cs++ << ":\n";
		for ( int i=0; i<_scc; ++i ) {
			bool f = 1;
			for ( int j=1; j<cnt; ++j )
				if ( scc[j] == i ){
					if ( f )	cout << rM[j];
					else	cout << ", " << rM[j];
					f = 0;
				}
			cout << '\n';
		}
	}
	return 0;
}
