#include <iostream>
using namespace std;
int a[101];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i=0, x; i<n; ++i ) {
		cin >>x;
		a[x]++;
	}
	int cnt = 0, idx = 0;
	for ( int i=1; i<101; ++i ) {
		if ( a[i] )	cnt++;
	}
	if ( cnt == 2 ) {
		bool flag = 1;
		int x = 0, y = 0;
		for (int i=1; i<101; ++i ) {
			if ( a[i] ) {
				if ( x ) {
					if ( a[i] != a[x] )
						flag = 0;
					else
						y = i;
				} else {
					x = i;
				}
			}
		}
		if ( flag )	cout << "YES\n" << x << ' ' << y << '\n';
		else	cout << "NO\n";
	} else {
		cout << "NO\n";
	}
	return 0;
}

