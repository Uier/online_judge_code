#include <iostream>
#define maxa 10000001
using namespace std;
typedef long long ll;
int npr[maxa];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for ( ll i=2; i<maxa; ++i )
		if ( !npr[i] )
			for ( ll j=i*i; j<maxa; j+=i )
				npr[j] = i;
	int n, a;
	cin >> n;
	while ( n-- && cin >> a ) {
		if ( !npr[a] )	cout << 1 << ' ' << a << '\n';
		else {
			int c = 1, d = 1;
			while ( npr[a] ) {
				if ( npr[a] > d ) {
					c = d;
					d = npr[a];
				} else if ( npr[a] > c && npr[a] != d )
					c = npr[a];
				a /= npr[a];
			}
			if ( a > d ) {
				c = d;
				d = a;
			} else if ( a > c && a != d )
				c = a;
			cout << c << ' ' << d << '\n';
		}
	}
	return 0;
}

