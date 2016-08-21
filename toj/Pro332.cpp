#include <stdio.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int m, n, a;
	long long t=1, ans=1;
	scanf("%d%d", &m, &n);
	for (int i = 0; i < m; ++i)
	{
		scanf("%d", &a);
		t *= a;
		t %= 100000007;
		if ( t < 0 )
			t += 100000007;
	}
	for (int i = 0; i < n; ++i)
	{
		ans *= t;
		ans %= 100000007;
		if ( ans < 0 )
			ans += 100000007;
	}
	t = 1;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a);
		t *= a;
		t %= 100000007;
		if ( t < 0 )
			t += 100000007;
	}
	for (int i = 0; i < m; ++i)
	{
		ans *= t;
		ans %= 100000007;
		if ( ans < 0 )
			ans += 100000007;
	}
	printf("%lld\n", ans);
	return 0;
}