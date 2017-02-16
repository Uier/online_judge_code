#include <iostream>
#include <map>
using namespace std;
int a[1005];
bool npr[3000005];
int main() {
	npr[0] = npr[1] = true;	//	build prime table
	for ( int i=2; i<3000005; i++ )
		if ( !npr[i] )
			for ( int j=i+i; j<3000005; j+=i )
				npr[j] = true;
	int n, one = 0;
	cin >> n;
	for ( int i=0; i<n; i++ ) {
		cin >> a[i];
		if ( a[i] == 1 )
			one++;
	}
	int first = 0;
	if ( n == 1 )
		cout << 1 << '\n' << a[0] << '\n';
	else if ( one >= 2 ) {
		for ( int i=0; i<n; i++ )
			if ( a[i] != 1 && !npr[a[i]+1] )
				first = a[i];
		cout << ((first) ? one+1 : one) << '\n';
		for ( int i=0; i<one; i++ )
			cout << 1 << ' ';
		if ( first ) cout << first;
		cout << '\n';
	}
	else {
		for ( int i=0; i<n&&!first; i++ )
			for ( int j=i+1; j<n&&!first; j++ )
				if ( !npr[a[i]+a[j]] && a[i] != a[j] ) {
					cout << 2 << '\n' << a[i] << ' ' << a[j] << '\n';
					first = 1;
				}
		if ( !first )
			cout << 1 << '\n' << a[0] << '\n';
	}
	return 0;
}
