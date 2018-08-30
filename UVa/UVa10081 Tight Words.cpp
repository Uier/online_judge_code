#include <iostream>
#include <string.h>
using namespace std;
double dp[105][15];
int main() {
	int k, n;
	while ( scanf("%d %d", &k, &n) != EOF ) {
		memset(dp,0,sizeof(dp));
		for ( int i=1; i<=k+1; ++i )	dp[1][i] = 1.0/(double)(k+1);
		for ( int i=2; i<=n; ++i )
			for ( int j=1; j<=k+1; ++j )
				dp[i][j] = (dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1])/(double)(k+1);
		double sum = 0;
		for ( int i=1; i<=k+1; ++i )
			sum += dp[n][i];
		printf("%.5lf\n", sum*100);
	}
	return 0;
}

