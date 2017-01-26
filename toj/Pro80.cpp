#include <iostream>
#include <string.h>
using namespace std;
int a[1005], p[1005], dp[1005][1005];	// ans = dp[1][N]
int solve(int l, int r) {
	if ( dp[l][r] != -1 )	return dp[l][r];
	return dp[l][r] = p[r]-p[l-1]-min(solve(l+1,r),solve(l,r-1));
}
int main() {
	int N;
	scanf("%d", &N);
	memset(dp,-1,sizeof dp);
	for ( int i=1; i<=N; i++ ) {
		cin >> a[i];
		p[i] = p[i-1] + a[i];
		dp[i][i] = a[i];
	}
	solve(1,N);
//	for ( int k=2; k<=N; k++ )
//		for ( int i=1; i+k-1<=N; i++ ) {
//			int j = i+k-1;
//			dp[i][j] = p[j]-p[i-1]-min(dp[i+1][j],dp[i][j-1]);
//		}
	cout << dp[1][N] << ' ' << p[N]-dp[1][N] << '\n';
	return 0;
}

