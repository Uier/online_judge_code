#include <iostream>
using namespace std;
int G[4][13], V[15][15][15][15], cnt;
bool dp[15][15][15][15];
bool dfs(int a, int b, int c, int d) {
	if ( V[a][b][c][d] == cnt )	return dp[a][b][c][d];
	bool AB = 0, AC = 0, AD = 0, BC = 0, BD = 0, CD = 0;
	if ( a != 13 && b != 13 && G[0][a] == G[1][b] )
		AB = dfs(a+1,b+1,c,d);
	if ( a != 13 && c != 13 && G[0][a] == G[2][c] )
		AC = dfs(a+1,b,c+1,d);
	if ( a != 13 && d != 13 && G[0][a] == G[3][d] )
		AD = dfs(a+1,b,c,d+1);
	if ( b != 13 && c != 13 && G[1][b] == G[2][c] )
		BC = dfs(a,b+1,c+1,d);
	if ( b != 13 && d != 13 && G[1][b] == G[3][d] )
		BD = dfs(a,b+1,c,d+1);
	if ( c != 13 && d != 13 && G[2][c] == G[3][d] )
		CD = dfs(a,b,c+1,d+1);
	V[a][b][c][d] = cnt;
	return dp[a][b][c][d] = AB||AC||AD||BC||BD||CD;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while ( cin >> G[0][0] ) {
		for ( int i=1; i<13; ++i )	cin >> G[0][i];
		for ( int i=1; i<4; ++i )
			for ( int j=0; j<13; ++j )
				cin >> G[i][j];
		cnt++;
		V[13][13][13][13] = cnt;
		dp[13][13][13][13] = 1;
		if ( dfs(0,0,0,0) )	puts("YES");
		else	puts("NO");
	}
	return 0;
}

