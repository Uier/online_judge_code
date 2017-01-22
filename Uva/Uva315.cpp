#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
using namespace std;
vector<int> G[105], S[105];
int D[105], L[105];
bool V[105];
void dfs(int x, int d) {
	V[x] = true;
	L[x] = D[x] = d;
	for ( int i : G[x] ) {
		if ( !V[i] ) {	// Tree edge
			S[x].push_back(i);
			dfs(i,d+1);
			L[x] = min(L[x],L[i]);
		}
		else			// Back edge
			L[x] = min(L[x],D[i]);
	}
}
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x, y;
	while ( cin >> n && n ) {
		for ( int i=1; i<=n; i++ ) {
			G[i].clear();
			S[i].clear();
		}
		memset(D,0,sizeof D);
		memset(V,false,sizeof V);
		string s;
		getline(cin,s);
		while ( getline(cin,s) && s != "0" ) {
			istringstream ss(s);
			bool f = true;
			while ( ss >> x ) {
				if ( f ) {
					y = x;
					f = false;
				}
				else {
					G[x].push_back(y);
					G[y].push_back(x);
				}
			}
		}
		dfs(1,0);
		int ans = 0;
		if ( S[1].size() > 1 )
			ans++;
		for ( int i=2; i<=n; i++ )
			for ( int j : S[i] )
				if ( L[j] >= D[i] ) {
					ans++;
					break;
				}
		cout << ans << '\n';
	}
	return 0;
}

