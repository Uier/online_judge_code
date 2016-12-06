#include <iostream>
#include <algorithm>
using namespace std;
struct P {
	int a;
	int x;
	int y;
} ans[200];
bool cmp(P u, P v) {
	return u.a < v.a;
}
int n, m, k, q=0;
char G[51][51], rG[51][51];
void dfs(int i, int j) {
	G[i][j] = '*';
	if ( i != 0 && G[i-1][j] == '.' )	dfs(i-1,j);
	if ( i != m-1 && G[i+1][j] == '.' )	dfs(i+1,j);
	if ( j != 0 && G[i][j-1] == '.' )	dfs(i,j-1);
	if ( j != n-1 && G[i][j+1] == '.' )	dfs(i,j+1);
}
void sdfs(int i, int j) {
	ans[q].a += 1;
	G[i][j] = '*';
	if ( i != 0 && G[i-1][j] == '.' )	sdfs(i-1,j);
	if ( i != m-1 && G[i+1][j] == '.' )	sdfs(i+1,j);
	if ( j != 0 && G[i][j-1] == '.' )	sdfs(i,j-1);
	if ( j != n-1 && G[i][j+1] == '.' )	sdfs(i,j+1);
}
void tdfs(int i, int j) {
	rG[i][j] = '*';
	if ( i != 0 && rG[i-1][j] == '.' )	tdfs(i-1,j);
	if ( i != m-1 && rG[i+1][j] == '.')	tdfs(i+1,j);
	if ( j != 0 && rG[i][j-1] == '.' )	tdfs(i,j-1);
	if ( j != n-1 && rG[i][j+1] == '.')	tdfs(i,j+1);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for ( int i=0; i<n; i++ )
		for ( int j=0; j<m; j++ ) {
			cin >> G[i][j];
			rG[i][j] = G[i][j];
		}
	for ( int i=0; i<m; i++ )
		if ( G[0][i] == '.' )
			dfs(0,i);
	for ( int i=0; i<m; i++ )
		if ( G[n-1][i] == '.' )
			dfs(n-1,i);
	for ( int i=0; i<n; i++ )
		if ( G[i][0] == '.' )
			dfs(i,0);			
	for ( int i=0; i<n; i++ )
		if ( G[i][m-1] == '.' )
			dfs(i,m-1);
	for ( int i=1; i<n-1; i++ )
		for ( int j=1; j<m-1; j++ )
			if ( G[i][j] == '.' ) {
				sdfs(i,j);
				ans[q].x = i;
				ans[q].y = j;
				q++;
			}
	sort(ans,ans+q,cmp);
	for ( int i=0; i<q-k; i++ )
		tdfs(ans[i].x,ans[i].y);
	cout << q-k << '\n';
	for ( int i=0; i<n; i++ ) {
		for ( int j=0; j<m; j++ )
			cout << rG[i][j];
		cout << '\n';
	}
	return 0;
}

