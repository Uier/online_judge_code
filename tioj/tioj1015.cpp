#include <stdio.h>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	long long m, n;
	while ( scanf("%lld %lld", &m, &n) )
	{
		long long ans=0, a=0;
		if ( m==0 )
			break;
		if ( m > n )
			swap(m,n);
		ans += m*(m+1)*(2*m+1);
		a=ans/6;
		ans = 0;
		ans += (n-m)*(m*(1+m)/2);
		a += ans;
		printf("%lld\n", a);
	}
	return 0;
}