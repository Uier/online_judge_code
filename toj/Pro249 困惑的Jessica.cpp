#include<stdio.h>
using namespace std;
int ant[5000050];
int main()
{
	int n;
	long long now=0, max=-2e9;
	scanf("%d",&n);
	for ( int i=0; i<n; i++ )
	{
		scanf("%d",&ant[i]);
		now += ant[i];
		if ( now >= max )
			max = now;
		if ( now < 0 )
			now = 0;
	}
	printf("%lld\n",max);
	return 0;
}
