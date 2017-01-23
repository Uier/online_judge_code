#include <bits/stdc++.h>
#define MX 1005
using namespace std;
typedef pair<int,int> PR;
set<int> A;
vector<int> G[MX], S[MX];
int L[MX], P[MX];
bool V[MX];
int dfs(int x, int fa) {
	
}
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	while ( cin >> n >> m && n ) {
		memset(B,0,sizeof B);
		memset(V,false,sizeof V);
		A.clear();
		R.clear();
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
		
	}
	return 0;
}

