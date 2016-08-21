#include<iostream>
using namespace std;
int main()
{
	long long m, n, p, ans=1;
	cin >> n >> m >> p;
	for ( int i=2; i<=n; i++ )
	{
		if ( ans > p )
			ans %= p;
		ans *= i;
	}
	ans %= p;
	long long god=9999999999999%p;
	for ( int i=0; i<m; i++ )
	{
		if ( ans > p )
			ans %= p;
		ans += god;
	}
	cout << ans%p << endl;
	return 0;
}

