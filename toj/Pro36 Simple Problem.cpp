#include<iostream>
using namespace std;
int main()
{
	int c;
	long long a, b, ans=1;
	cin >> a >> b >> c;
	for ( int i=0; i<b; i++ )
	{
		if ( ans >= 2147483647 )
		{
			ans %= c;
			a = ans;
			if ( b%2 != 0 )
				ans *= a;
			b /= 2;
			i=1;
		}
		ans *= a;
	}
	cout << ans%c << endl;
	return 0;
}

