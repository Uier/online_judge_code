#include <iostream>
using namespace std;
typedef pair<int,int> pii;
int n, m, tn[1005][1005], to;
char g[1005][1005];
void dfs(int i, int j, int wd) {
	if ( wd < tn[i][j] )
		tn[i][j] = wd;
	else
		return;
	if ( i-1 >=0 && g[i-1][j] != '*' ) {
		if ( to != 3 ) {
			to = 3;
			dfs(i-1,j,wd+1);
		} else	dfs(i-1,j,wd);
	} else if ( i+1 < n && g[i+1][j] != '*' ) {
		if ( to	!= 1 ) {
			to = 1;
			dfs(i+1,j,wd+1);
		} else dfs(i+1,j,wd);
	} else if ( j-1 >=0 && g[i][j-1] != '*' ) {
		if ( to	!= 4 ) {
			to = 4;
			dfs(i,j-1,wd+1);
		} else dfs(i,j-1,wd);
	} else if ( j+1 < m && g[i][j+1] != '*' ) {
		if ( to != 2 ) {
			to = 2;
			dfs(i,j+1,wd+1);
		} else	dfs(i,j+1,wd);
	}
}
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	pii st, ed;
	cin >> n >> m;
	for ( int i=0; i<n; ++i )
		for ( int j=0; j<m; ++j ) {
			cin >> g[i][j];
			tn[i][j] = 3;
			if ( g[i][j] == 'S' )
				st.first = i, st.second = j;
			else if ( g[i][j] == 'T' )
				ed.first = i, ed.second = j;
		}
	to = 1;
	dfs(st.first,st.second,0);
	to = 2;
	dfs(st.first,st.second,0);
	to = 3;
	dfs(st.first,st.second,0);
	to = 4;
	dfs(st.first,st.second,0);
	if ( tn[ed.first][ed.second] <= 2 )	cout << "YES\n";
	else	cout << "NO\n";
	return 0;
}

