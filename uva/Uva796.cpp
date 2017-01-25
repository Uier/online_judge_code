#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#define mx 1005
using namespace std;
vector<int> G[mx];
int S[mx], T;
bool V[mx][mx];
typedef pair<int,int> pii;
set<pii> A;
int dfs(int x, int fa) {
	int Lx = S[x] = ++T;
	for ( int i : G[x] )
		if ( !S[i] ) {
			int Li = dfs(i,x);
			Lx = min(Lx,Li);
			if ( Li > S[x] )
				A.insert(pii{min(i,x),max(i,x)});
		}
		else if ( i != fa )
			Lx = min(Lx,S[i]);
	return Lx;
}
main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	int n;
	while ( cin >> n ) {
		T = 0;
		A.clear();
		memset(S,0,sizeof S);
		memset(V,0,sizeof V);
		for ( int i=0; i<n; i++ )	G[i].clear();
		for ( int i=0; i<n; i++ ) {
			int a, b, c;
			char d, e;
			cin >> a >> d >> b >> e;
			for ( int j=0; j<b; j++ ) {
				cin >> c;
				if ( !V[a][c] ) {
					G[a].push_back(c);
					G[c].push_back(a);
					V[a][c] = V[c][a] = true;
				}
			}
		}
		for ( int i=0; i<n; i++ )
			if ( !S[i] )
				dfs(i,-1);
		cout << A.size() << " critical links\n";
		for ( auto i=A.begin(); i!=A.end(); i++ ) {
			pii j = *i;
			cout << j.first << " - " << j.second << '\n';
		}
		cout << '\n';
	}
	return 0;
}

