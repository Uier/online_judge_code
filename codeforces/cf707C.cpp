#include <iostream>
#include <cmath>
using namespace std;
bool ans=true;
inline void f(long long n) {
	if ( n == 1 || n == 2 ) {
		cout << -1 << '\n';
		return;
	}
	else {
		for ( long double i=3; i<=1000000000; i++ ) {
			if ( i != n ) {
				long double k=0;
				if ( n > i )
					k = sqrt(n*n-i*i);
				else if ( n < i )
					k = sqrt(i*i-n*n);
				if ( (long long)k == k ) {
					cout << (long long)i << ' ' << (long long)k << '\n';
					ans = false;
					break;
				}
			}
		}
		if ( ans )
		{
			for ( long double i=3; i<=1000000000; i++ ) {
				if ( i != n ) {
					long double j=sqrt(i*i+n*n);
					if ( j<=1000000000000000000 && (long long)j == j ) {
						cout << i << ' ' << (long long)j << '\n';
						break;
					}
				}
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n;
	cin >> n;
	f(n);
	return 0;
}

