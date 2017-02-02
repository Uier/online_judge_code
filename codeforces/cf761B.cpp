#include <iostream>
#include <algorithm>
using namespace std;
int a[100], k[100], s[100];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, l;
	cin >> n >> l;
	for ( int i=0; i<n; i++ ) {
		cin >> a[i];
		if ( i ) {
			k[i-1] = a[i] - a[i-1];
		}
	}
	k[n-1] = l-(a[n-1]-a[0]);
	for ( int i=0; i<n; i++ ) {
		cin >> a[i];
		if ( i ) {
			s[i-1] = a[i] - a[i-1];
		}
	}
	s[n-1] = l-(a[n-1]-a[0]);
	bool ans = false;
	int m = n, x=0, y=0;
	while ( m-- ) {
		int fk = n;
		while ( k[x] != s[y] && fk-- )	x=(x+1)%n;
		if ( !fk )	break;
		int c = n;
		bool flag = true;
		while ( c-- ) {
			if ( k[x] != s[y] )	flag = false;
			x = (x+1)%n;	y = (y+1)%n;
		}
		if ( flag )	{
			ans = true;
			break;
		}
		else x=(x+1)%n;
	}
	if ( ans || n == 1 )	cout << "YES\n";
	else	cout << "NO\n";
	return 0;
}

