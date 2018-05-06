#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int a[200005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	memset(a,-1,sizeof(a));
	for ( int i=0; i<n; ++i )	cin >> a[i];
	sort(a,a+n);
	if ( k == 0 ) {
		if ( a[0] == 1 )	cout << -1 << '\n';
		else	cout << 1 << '\n';
	}
	else if ( a[k-1] != a[k] ) cout << a[k-1] << '\n';
	else	cout << -1 << '\n';
	return 0;
}

