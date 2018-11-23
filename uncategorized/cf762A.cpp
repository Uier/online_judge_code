#include <iostream>
#include <math.h>
#include <vector>
#define int long long
using namespace std;
vector<long long> d;
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n, k;
	cin >> n >> k;
	long long m = sqrt(n);
	for ( int i=1; i<=m; ++i )
		if ( n%i == 0 )
			d.emplace_back(i);
	long long len = d.size(), sum = d.size()*2;
	if ( m*m == n )	sum--;
	if ( k <= len )	cout << d[k-1] << '\n';
	else if ( k > sum )	cout << -1 << '\n';
	else {
		k -= len;
		if ( m*m == n )	len--;
		cout << n/d[len-k] << '\n';
	}
	return 0;
}

