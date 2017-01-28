#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#define mx 1005
using namespace std;
vector<int> G[mx];
int S[mx], T;
bool V[mx][mx];	// need visit
typedef pair<int,int> pii;
set<pii> A;
bool operator < (pii a, pii b) {
	if ( a.first == b.first )	return a.second < b.second;
	return a.first < b.first;
}
int dfs(int x, int fa) {
	int Lx = S[x] = ++T;
	for ( int i : G[x] ) {
		if ( !S[i] ) {
			int Li = dfs(i,x);
			Lx = min(Lx,Li);
			if ( Li > S[x] )
				A.insert(pii{i,x});
			if ( V[i][x] || V[x][i] ) {
				A.insert(pii{x,i});
				V[i][x] = V[x][i] = false;
			}
		}
		else if ( i != fa ) {
			Lx = min(Lx,S[i]);
			if ( V[i][x] || V[x][i] ) {
				A.insert(pii{x,i});
				V[i][x] = V[x][i] = false;
			}
		}
	}
	return Lx;
}
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, tc = 1;
	while ( cin >> n >> m && n ) {
		T = 0;
		A.clear();
		for ( int i=1; i<=n; i++ )	G[i].clear();
		memset(S,0,sizeof S);
		memset(V,0,sizeof V);
		for ( int i=0; i<m; i++ ) {
			int a, b;
			cin >> a >> b;
			V[a][b] = true;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		dfs(1,0);
		cout << tc++ << '\n' << '\n';
		for ( auto i = A.begin(); i!=A.end(); i++ ) {
			pii j = *i;
			cout << j.first << ' ' << j.second << '\n';
		}
		cout << "#\n";
	}
	return 0;
}

