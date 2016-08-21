#include<iostream>
using namespace std;

long long pow_(long long x, long long y, int z)
{
	long long ans=1, base=x;
	while ( y )
	{
		if ( y%2 == 1 )
			ans *= base;
		base *= base;
		base %= z;
		ans %= z;
		y /= 2;
	}
	return ans%z; 
}

int main()
{
	long long a, b, c;
	cin >> a >> b >> c;
	cout << pow_(a, b, c) << endl;
	return 0;
}

