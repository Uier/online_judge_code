#include <stdio.h>
using namespace std;
int n, m, a[11] = {5,10,20,50,100,200,500,1000,2000,5000,10000};
long long dp[30005]={1};
int main() {
	for ( int i=0; i<11; i++ )
		for ( int j=a[i]; j<30005; j++ )
			dp[j] += dp[j-a[i]];
	while ( scanf("%d.%d", &n, &m) != EOF && !(n==0&&m==0) )
		printf("%3d.%02d%17lld\n", n, m, dp[n*100+m]);
	return 0;
}

