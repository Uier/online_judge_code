#include <iostream>
#include <stdio.h>
using namespace std;
int a[5000010];
long long dp[5000010];
int main()
{
	int n;
	long long max=-9999999999999999;
	scanf("%d", &n);
	scanf("%d", &a[0]);
	dp[0] = a[0];
	for ( int i=1; i<n; i++ )
	{
		scanf("%d", &a[i]);
		if ( dp[i-1] > 0 )
			dp[i] = dp[i-1]+a[i];
		else
			dp[i] = a[i];
		if ( dp[i] > max )
			max = dp[i];
	}
	printf("%lld\n", max);
	return 0;
}