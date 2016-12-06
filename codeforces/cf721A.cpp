#include <iostream>
using namespace std;
int ans[100];
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n, x=0;
	string s;
	cin >> n >> s;
	for ( int i=0; i<n; i++ )
		if ( s[i] == 'B' )
			for ( int j=i; j<n; j++ ) {
				if ( s[j] == 'B' )
					ans[x]++;
				else {
					x++;
					i = j;
					break;
				}
				if ( j == n-1 ) {
					x++;
					i = n;
				}
			}
	cout << x << '\n';
	if ( x != 0 ) {
		for ( int i=0; i<x-1; i++ )
			cout << ans[i] << ' ';
		cout << ans[x-1] << '\n';
	}
	return 0;
}

