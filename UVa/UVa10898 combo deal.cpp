#include <iostream>
#include <string.h>
using namespace std;
int N, K, Q, PR[15], CB[15][10], order[10], dp[15][10][10][10][10][10][10];
int dfs(int index, int DM[]) {	// top down
	if ( index == 0 ) {
		for ( int i=1; i<=6; ++i )
			if ( DM[i] != 0 )	// illegal
				return 1e9;
		return 0;	// legal
	}
	if ( dp[index][DM[1]][DM[2]][DM[3]][DM[4]][DM[5]][DM[6]] != 0 )
		return dp[index][DM[1]][DM[2]][DM[3]][DM[4]][DM[5]][DM[6]];
	int pick[7] = {0,0,0,0,0,0,0};
	for ( int i=1; i<=6; ++i ) {
		pick[i] = DM[i] - CB[index][i];
		if ( pick[i] < 0 )	// illegal one
			return dp[index][DM[1]][DM[2]][DM[3]][DM[4]][DM[5]][DM[6]] = dfs(index-1,DM);
	}
	return	dp[index][DM[1]][DM[2]][DM[3]][DM[4]][DM[5]][DM[6]] = 
			min(dfs(index,pick)+PR[index], dfs(index-1,DM));	// legal, to pick or not to pick
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while ( cin >> N ) {
		memset(CB,0,sizeof(CB));
		memset(PR,0,sizeof(PR));
		memset(dp,0,sizeof(dp));	// set 0 as unused 
		for ( int i=1; i<=N; ++i ) {
			CB[i][i] = 1;
			cin >> PR[i];
			dp[i][i==1][i==2][i==3][i==4][i==5][i==6] = PR[i];
		}
		cin >> K;
		for ( int i=1; i<=K; ++i ){
			for ( int j=1; j<=N; ++j )	cin >> CB[N+i][j];
			cin >> PR[N+i];
			dp[i][CB[N+i][1]][CB[N+i][2]][CB[N+i][3]][CB[N+i][4]][CB[N+i][5]][CB[N+i][6]] = PR[N+i];
		}
		cin >> Q;
		while ( Q-- ) {
			for ( int i=1; i<=N; ++i )	cin >> order[i];
			cout << dfs(N+K,order) << '\n';
		}
	}
	return 0;
}

