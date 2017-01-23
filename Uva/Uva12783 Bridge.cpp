#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#define MX 1005
using namespace std;
typedef pair<int,int> PR;
vector<int> G[MX], S[MX];
vector<PR> R;
int L[MX], D[MX];
bool V[MX], A[MX];
void dfs(int x, int d) {
	V[x] = true;
	D[x] = d;
	for ( int i : G[x] ) {
		if ( V[i] )	// Back E
			L[x] = min(L[x],D[i]);
		else {
			S[x].push_back(i);
			L[i] = min(L[i],D[x]);
			dfs(i,d+1);
			L[x] = min(L[x],L[i]);
		}
	}
}
bool cmp(PR a, PR b) {
	if ( a.first == b.first )	return a.second < b.second;
	return a.first < b.first;
}
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	while ( cin >> n >> m && n ) ) {
		memset(V,false,sizeof V);
		memset(A,false,sizeof A);
		R.clear();
		for ( int i=0; i<n; i++ ) {
			G[i].clear();
			S[i].clear();
			L[i] = i;
		}
		for ( int i=0; i<m; i++ ) {
			int a, b;
			cin >> a >> b;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		dfs(0,0);
		A[0] = true;
		for ( int i=1; i<n; i++ )
			if ( G[i].size() == 1 )	A[i] = true;
			else
				for ( int j : S[i] )
					if ( L[j] >= D[i] ) {
						A[i] = true;
						break;
					}
		for ( int i=0; i<n; i++ )
			if ( A[i] )
				for ( int j : G[i] )
					if ( A[j] )
						R.push_back(PR{min(i,j),max(i,j)});
		sort(R.begin(),R.end(),cmp);
		auto it = unique(R.begin(),R.end());
		R.resize(distance(R.begin(),it));
		cout << R.size() << ((R.size()==0) ? '\n' : ' ');
		for ( int i=0; i<R.size(); i++ )
			cout << R[i].first << ' ' << R[i].second << ((i!=R.size()-1) ? ' ' : '\n');
	}
/*	
	bridge
	1.	有割點	-> 有橋
	2.	有橋	-> 不一定有割點 ex. 1--2, --是橋 但1, 2非割點 
	3.	橋在
		a.	割點與割點之間 
		b.	割點與葉子之間
	4.	只有一個邊的就是葉子, 該邊即是橋 
*/ 
	return 0;
}

