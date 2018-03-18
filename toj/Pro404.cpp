#include <iostream>
#include <algorithm>
using namespace std;
int a[105];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=0; i<n; ++i )
		cin >> a[i];
	sort(a,a+n);
	bool ans = true;
	for ( int i=1; i<n; ++i )
		if ( a[i] != a[i-1]+1 )
			ans = false;
	if ( ans )	cout << a[0] << ' ' << a[n-1] << " yes\n";
	else	cout << a[0] << ' ' << a[n-1] << " no\n";
	return 0;
}

