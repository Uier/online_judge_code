#include<bits/stdc++.h>
using namespace std;

long long pow_(long long a, long long b, long long c)
{
	__int128 ans=1, base=a;
	while ( b )
	{
		if ( b%2 == 1 )
			ans *= base;
		base *= base;
		base %= c;
		ans %= c;
		b /= 2;	
	}
	return ans%c;
}

int main ()
{
	int n;
	cin >> n;
	while ( n-- )
	{
		long long a, b, c;
		cin >> a >> b >> c;
		cout << pow_(a, b, c) << endl;
	}

	return 0;
}
