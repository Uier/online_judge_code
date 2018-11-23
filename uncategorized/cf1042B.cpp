#include <iostream>
#include <string.h>
#include <algorithm>
#define int long long
using namespace std;
int a[2][2][2];
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x;
	string s;
	for ( int i=0; i<2; ++i )
		for ( int j=0; j<2; ++j )
			for ( int k=0; k<2; ++k )
				a[i][j][k] = 1e6;
	cin >> n;
	for ( int i=0; i<n; ++i ) {
		cin >> x >> s;
		if ( s.size() == 3 ) {
			a[1][1][1] = min(a[1][1][1],x);
		} else if ( s.size() == 1 ) {
			if ( s[0] == 'A' ) {
				a[1][0][0] = min(a[1][0][0],x);
			} else if ( s[0] == 'B' ) {
				a[0][1][0] = min(a[0][1][0],x);
			} else {
				a[0][0][1] = min(a[0][0][1],x);
			}
		} else {
			sort(s.begin(),s.end());
			if ( s[0] == 'A' ) {
				if ( s[1] == 'B' ) {
					a[1][1][0] = min(a[1][1][0],x);
				} else {
					a[1][0][1] = min(a[1][0][1],x);
				}
			} else {
				a[0][1][1] = min(a[0][1][1],x);
			}
		}
	}
	for ( int i=0; i<2; ++i )
		for ( int j=0; j<2; ++j )
			for ( int k=0; k<2; ++k )
				for ( int p=0; p<2; ++p )
					for ( int q=0; q<2; ++q )
						for ( int r=0; r<2; ++r )
							a[i|p][j|q][k|r] = min(a[i|p][j|q][k|r],a[i][j][k]+a[p][q][r]);
//				a[i][j][k] = 1e6;
//	a[1][1][1] = min(a[1][1][1],a[1][0][0]+a[0][1][0]+a[0][0][1]);
//	a[1][1][1] = min(a[1][1][1],a[1][0][0]+a[0][1][1]);
//	a[1][1][1] = min(a[1][1][1],a[0][1][0]+a[1][0][1]);
//	a[1][1][1] = min(a[1][1][1],a[0][0][1]+a[1][1][0]);
	if ( a[1][1][1] >= 1e6 )	cout << -1 << '\n';
	else	cout << a[1][1][1] << '\n';
	return 0;
}

