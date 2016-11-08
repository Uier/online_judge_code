#include <iostream>
#include <vector>
#include <string.h>
#include <set>
using namespace std;
//	先學強連通分量(scc)吧! 	以下為scc 非toj151 
bool V[50010];
vector<int> G[50010];
vector<int> rG[50010];
vector<int> fin;
set<int> S[50010];
void dfs(int x) {
	V[x] = true;
	for ( int i : G[x] )
		if ( !V[i] )
			dfs(i);
	fin.push_back(x);
}
void rdfs(int x, int c) {
	S[c].insert(x);
	V[x] = true;
	for ( int i : rG[x] )
		if ( !V[i] )
			rdfs(i,c);
}
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n, m, a, b, c=0, sn=0, pt=50011;
	cin >> n >> m;
	for ( int i=0; i<=n; i++ ) {
		G[i].clear();
		rG[i].clear();
		S[i].clear();
	}
	while ( m-- ) {
		cin >> a >> b;
		G[a].push_back(b);
		rG[b].push_back(a);
	}
	fin.clear();
	memset(V,false,sizeof V);
	for ( int i=1; i<=n; i++ )
		if ( !V[i] )
			dfs(i);
	memset(V,false,sizeof V);
	for ( int i=n; i>0; i-- )
		if ( !V[fin[i]] )
			rdfs(fin[i],c++);
	for ( int i=0; i<=c; i++ ) {
//		cout << "i: " << i << " S's: " << S[i].size() << " pt: " << *S[i].begin() << '\n';
		if ( S[i].size() > sn ) {
			sn = S[i].size();
			pt = *S[i].begin();
		}
		else if ( S[i].size() == sn && *S[i].begin() < pt ) {
			sn = S[i].size();
			pt = *S[i].begin();
		}
	}
	cout << pt << '\n';
	return 0;
}

