#include <iostream>
#include <string.h>
#include <vector>
#include <set>
#define MX 1005
using namespace std;
typedef pair<int,int> PR;
set<PR> A;
vector<int> G[MX], S[MX];
int L[MX], P[MX], T;
bool V[MX];
bool operator < (PR a, PR b)
int dfs(int x, int fa) {
	int Lx = P[x] = ++T;
	int child = 0;
	for ( int i : G[x] ) {
		if ( !P[i] ) {
			child++;
			int Li = dfs(i,x);
			Lx = min(Lx,Li);
			if ( Li > P[x] )
				A.insert(PR{min(i,x),max(i,x)});
		}
		else if ( i != fa )
			Lx = min(Lx,P[fa]);
	}
	return L[x] = Lx;
}
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	while ( cin >> n >> m && n ) {
		T = 0;
		memset(L,0,sizeof L);
		memset(P,0,sizeof P);
		memset(V,0,sizeof V);
		A.clear();
		for ( int i=0; i<n; i++ ) {
			G[i].clear();
			S[i].clear();
		}
		for ( int i=0; i<m; i++ ) {
			int a, b;
			cin >> a >> b;
			if ( a != b ) {
				G[a].push_back(b);
				G[b].push_back(a);
			}
		}
		dfs(0,-1);
		cout << A.size() << ((A.size()==0) ? '\n' : ' ');
		for ( auto i=A.begin(); i!=A.end(); i++ )
			cout << *i.first << ' ' << *i.second << ((j==A.size()-1) ? '\n' : ' ');
	}
	return 0;
}

