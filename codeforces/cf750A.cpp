#include <iostream>
using namespace std;
int a[15];
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	a[0] = 0;
	for ( int i=1; i<11; i++ )
		a[i] = a[i-1] + 5;
	int all = 240, n, k, j=0, l=1;
	cin >> n >> k;
	all -= k;
	all -= a[l++];
	while ( all >= 0 ) {
		j++;
		all -= a[l++];
	}
	if ( j > n )	cout << n << '\n';
	else	cout << j << '\n';
	return 0;
}

