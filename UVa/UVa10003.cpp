#include <iostream>
#include <string.h>
using namespace std;
int n, a[55], dp[1000][1000];
int cut(int l, int r) {
	if ( dp[l][r] != -1 )	return dp[l][r];
	dp[l][r] = 1e9;
	bool flag = 0;
	for ( int i=1; i<=n; i++ )
		if ( a[i] > l && a[i] < r )
			dp[l][r] = min(dp[l][r],cut(l,a[i])+cut(a[i],r)+r-l);
	return ((dp[l][r]==1e9) ? (dp[l][r]=0) : dp[l][r]);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	while ( cin >> t && t ) {
		cin >> n;
		for ( int i=1; i<=n; i++ )
			cin >> a[i];
		memset(dp,-1,sizeof dp);
		printf("The minimum cutting is %d.\n", cut(0,t));
	}
	return 0;
}

