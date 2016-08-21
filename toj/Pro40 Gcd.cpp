#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long a, b;
	while ( cin >> a >> b ) {
		long long gcd=__gcd(a,b);
		cout << a/gcd*b << '\n';
	}
	return 0;
}

