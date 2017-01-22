#include <iostream>
#include <math.h>
using namespace std;
long long a[55], b[55], n, k, p;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for ( int i=0; i<=50; i++ )
		a[i] = pow(2,i);
	cin >> n >> k;
	while ( k ) {
		for ( int i=0; i<n; i++ )
			if ( k < a[i+1] && k >= a[i] )
				p = i;
		k -= pow(2,p);
	}
	cout << p+1 << '\n';
	return 0;
}

