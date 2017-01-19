#include <iostream>
#include <map>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
//			undone
map<string,int> M;
map<int,string> rM;
vector<int> G[105], A;
vector<string> output;
int D[105], L[105], S[105];
bool V[105], U[105][105];
void dfs(int x, int d) {
	D[x] = d;
	for ( int i : G[x] )	// Back edge
		if ( V[i] )
			L[x] = min(L[x],D[i]);
	for ( int i : G[x] ) {	// Tree edge
		if ( !V[i] ) {
			V[i] = true;
			S[x] = i;
			L[i] = D[x];
			dfs(i,d+1);
			L[x] = min(L[x],L[i]);
		}
	}	
}
main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
	int n, m, c = 1;
	while ( cin >> n && n ) {
		string s, t;
		for ( int i=0; i<n; i++ ) {
			cin >> s;
			M[s] = i;
			rM[i] = s;
			G[i].clear();
		}
		cin >> m;
		for ( int i=0; i<m; i++ ) {
			cin >> s >> t;
			if ( !U[M[s]][M[t]] && !U[M[t]][M[s]] ) {
				G[M[s]].push_back(M[t]);
				G[M[t]].push_back(M[s]);
				U[M[s]][M[t]] = true;
			}
		}
		memset(L,0,sizeof L);
		memset(S,-1,sizeof S);
		memset(V,false,sizeof V);
		memset(U,false,sizeof U);
		A.clear();
		output.clear();
		if ( G[0].size() > 1 )	A.push_back(0);
		V[0] = true;
		L[0] = 0;
		dfs(0,0);
		for ( int i=1; i<n; i++ )
			if ( S[i] != -1 )
				if ( L[S[i]] < D[i] )
					A.push_back(i);
		cout << "City map #" << c++ << ": " << A.size() << " camera(s) found\n";
		for ( int i : A )
			output.push_back(rM[i]);
		sort(output.begin(),output.end());
		for ( string i : output )
			cout << i << '\n';
		for ( int i=0; i<n; i++ )
			cout << i << "'low: " << L[i] << '\n';
	}
	return 0;
}

