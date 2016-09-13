#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int a[1000005], dp[1000005], pt[1000005];
void trace(int x) {
	if ( pt[x] != -1 )
		trace(pt[x]);
	printf("%d\n", a[x]);
}
int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int n;
	scanf("%d\n", &n);
	char str[256];
	while ( n-- ) {
		int x=0;
		while ( gets(str) && str[0] != 0 )
			sscanf(str, "%d", &a[x++]);
		memset(dp,0,x*4);
		memset(pt,-1,x*4);
		for ( int i=0; i<x; i++ ) {
			dp[i] = 1;
			for ( int j=0; j<i; j++ )
				if ( a[i] > a[j] && dp[j]+1 > dp[i] ) {
					dp[i] = dp[j] + 1;
					pt[i] = j;
				}
		}
		int m=dp[0], pos=0;
		for ( int i=1; i<x; i++ )
			if ( dp[i] > m ) {
				m = dp[i];
				pos = i;
			} 
		printf("Max hits: %d\n", m);
		trace(pos);
		if ( n )
			printf("\n");
	}
	return 0;
}

