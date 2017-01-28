#include <iostream>
#include <algorithm>
using namespace std;
int a[1005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while ( cin >> n ) {
		for ( int i=0; i<n; i++ )
			cin >> a[i];
		sort(a,a+n);
		for ( int i=0; i<n-1; i++ )
			cout << a[i] << ' ';
		cout << a[n-1] << '\n';
	}
	return 0;
}

