#include <iostream>
#include <string.h>
using namespace std;
main() {
	pair<int,int>
    ios::sync_with_stdio(false);
    cin.tie(0);
	int n, m, tc = 0, st, ed, ls, G[105][105];
	while ( cin >> n >> m && n ) {
		memset(G,0,sizeof G);
		for ( int i=0; i<m; i++ ) {
			int a, b, c;
			cin >> a >> b >> c;
			G[a][b] = G[b][a] = c;
		}
		for ( int k=1; k<=n; k++ )
			for ( int i=1; i<=n; i++ )
				for ( int j=1; j<=n; j++ )
					G[i][j] = max(G[i][j],min(G[i][k],G[k][j]));
		cin >> st >> ed >> ls;
		int ans = G[st][ed] - 1;
		cout << "Scenario #" << ++tc << '\n';
		cout << "Minimum Number of Trips = ";
		if ( ls%ans )	cout << ls/ans+1 << '\n';	
		else	cout << ls/ans << '\n'; 
		cout << '\n';
	}
	return 0;
}

