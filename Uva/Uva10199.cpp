#include <iostream>
#include <map>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
map<string,int> M;
map<int,string> rM;
vector<int> G[105], A, S[105];
vector<string> output;
int D[105], L[105];
bool V[105], U[105][105], R[105];
void dfs(int x, int d) {
	D[x] = d;
//	for ( int i : G[x] )	// Back edge
//		if ( V[i] )
//			L[x] = min(L[x],D[i]);
	for ( int i : G[x] ) {	// Tree edge
		if ( !V[i] ) {
			V[i] = true;
			S[x].push_back(i);
			L[i] = D[x];
			dfs(i,d+1);
			L[x] = min(L[x],L[i]);
		}
		else				// Back edge
			L[x] = min(L[x],D[i]);
	}	
}
main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	int n, m, c = 1;
	while ( cin >> n && n ) {
		string s, t;
		memset(L,0,sizeof L);
		memset(V,false,sizeof V);
		memset(U,false,sizeof U);
		memset(R,false,sizeof R);
		for ( int i=0; i<n; i++ ) {
			S[i].clear();
			G[i].clear();
		}
		A.clear();
		output.clear();
		for ( int i=0; i<n; i++ ) {
			cin >> s;
			M[s] = i;
			rM[i] = s;
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
		for ( int i=0; i<n; i++ ) {
			if ( !V[i] ) {
				V[i] = true;
				R[i] = true;
				dfs(i,0);
			}
		}
		for ( int i=0; i<n; i++ )
			if ( !R[i] )  {
				for ( int j : S[i] )
					if ( j )
						if ( L[j] >= D[i] ) {
							A.push_back(i);
							break;
						}
			}
			else if ( S[i].size() > 1 )
				A.push_back(i);
		if ( c > 1 )
			cout << '\n';
		cout << "City map #" << c++ << ": " << A.size() << " camera(s) found\n";
		for ( int i : A )
			output.push_back(rM[i]);
		sort(output.begin(),output.end());
		for ( string i : output )
			cout << i << '\n';
//		for ( int i=0; i<n; i++ )
//			cout << i << "'low: " << L[i] << '\n';
//		for ( int i=0; i<n; i++ )
//			cout << i << "'depth: " << D[i] << '\n';
	}
	return 0;
}

