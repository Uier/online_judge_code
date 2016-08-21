#include<iostream>
#include<stdio.h>
using namespace std;
int bs[2000005];
int main()
{
	// wrong ans;
	int n;
	long long time=0;
	scanf("%d", &n);
	for ( int i=0; i<n; i++ )
		scanf("%d", &bs[i]);
	for ( int i=n-1; i>0; i-- )
	{
		for ( int j=0; j<i; j++ )
		{
			if ( bs[j] > bs[j+1] )
			{
				swap(bs[j], bs[j+1]);
				time++;
			}
		}
	}
	printf("%lld\n", time);
	return 0;
}

