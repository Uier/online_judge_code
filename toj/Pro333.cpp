#include <iostream>
using namespace std;
int a[10000005]={0}, b[10000005]={0};
int main(int argc, char const *argv[])
{
	int n;
	long long ans=0;
	scanf("%d", &n);
	if ( n == 1 )
	{
		scanf("%d", &n);
		printf("%d\n", n);
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
			if ( i == n-1 )
				b[i-1] = max(a[i-1], a[i]);
			else if ( i )
				b[i-1] = a[i-1] - a[i];
		}
		for (int i = 0; i < n-1; ++i)
		{
			if ( b[i] > 0 )
				ans += b[i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}