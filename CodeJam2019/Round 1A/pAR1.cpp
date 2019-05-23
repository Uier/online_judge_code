#include <iostream>
#include <string.h>
#include <vector>
#define maxn 21
using namespace std;
typedef pair<int,int> pii;
int n, m, G[maxn][maxn];
vector<pii> ans;
bool dfs(int x, int y, int z) {
	if ( z > n*m )	return true;
	for ( int i=0; i<n; ++i ) {
		for ( int j=0; j<m; ++j ) {
			if ( i == x || j == y || (x-y)==(i-j) || (x+y)==(i+j) || G[i][j] )	continue;
			G[i][j] = z;
			ans.emplace_back(make_pair(i,j));
			if ( dfs(i,j,z+1) )	return true;
			ans.pop_back();
			G[i][j] = 0;
		}
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, cs = 1;
	cin >> t;
	while ( t-- && cin >> n >> m ) {
		memset(G,0,sizeof(G));
		cout << "Case #" << cs++ << ": ";
		bool flag = 1;
		ans.clear();
		for ( int i=0; i<n&&flag; ++i )
			for ( int j=0; j<m&&flag; ++j ) {
				G[i][j] = 1;
				ans.emplace_back(make_pair(i,j));
				if ( dfs(i,j,2) ) {
					flag = 0;
					cout << "POSSIBLE\n";
					for ( pii x : ans )
						cout << x.first+1 << ' ' << x.second+1 << '\n';
				}
				ans.pop_back();
				G[i][j] = 0;
			}
		if ( flag )	cout << "IMPOSSIBLE\n";
	}
	return 0;
}

