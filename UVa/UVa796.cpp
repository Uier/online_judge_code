#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include <set>
#define maxn 100005
using namespace std;
vector<int> G[maxn];
int D[maxn], L[maxn];
set<pair<int,int>> S;
void dfs(int x, int fa, int dep) {
	L[x] = D[x] = dep;
	for ( int i : G[x] ) {
		if ( D[i] == -1 ) { // tree edge
			dfs(i,x,dep+1);
			L[x] = min(L[x],L[i]);
		} else if ( i != fa ) // back edge
			L[x] = min(L[x],D[i]);
		if ( D[x] < L[i] )
			S.insert(make_pair(min(x,i),max(x,i)));
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x, y;
	string s;
	while ( cin >> n ) {
		getline(cin,s);
		S.clear();
		memset(D,-1,sizeof(int)*n);
		for ( int i=0; i<n; ++i )	G[i].clear();
		for ( int i=0; i<n; ++i ) {
			cin >> x;
			getline(cin,s);
			stringstream ss(s);
			for ( char a=' '; a!=')'; ss>>a );
			while ( ss >> y ) {
				G[x].emplace_back(y);
				G[y].emplace_back(x);
			}
		}
		for ( int i=0; i<n; ++i )	if ( D[i] == -1 )	dfs(i,i,0);
		cout << S.size() << " critical links\n";
		for ( auto i=S.begin(); i!=S.end(); ++i )
			cout << i->first << " - " << i->second << '\n';
		cout << '\n';
	}
	return 0;
}
