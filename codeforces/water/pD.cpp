#include <iostream>
using namespace std;
int a[105];
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n, cnt = 0, l = 0, r = 0;
	cin >> n;
	for ( int i=1; i<=n; ++i ) {
		cin >> a[i];
		if ( a[i]%2 == 0 ) {
			if ( l != 0 ) {
				r = i;
			} else {
				l = i;
			}
		}
	}
	if ( l == 0 ) {
		if ( n%2 )	cout << "Yes\n";
		else	cout << "No\n";
	} else if ( r == 0 ) {
		if ( l == 1 || l == n )	cout << "No\n";
		else {
			int pl = (l-2), pr = (n-l-1);
			if ( pl%2 && pr%2 )	cout << "Yes\n";
			else if ( pl%2 == 0 && pr%2 == 0 )	cout << "Yes\n";
			else	cout << "No\n";
		}
	} else {
		if ( l == 1 || r == n )	cout << "No\n";
		else {
			int pl = (l-2), pr = (n-l-1);
			if ( ((r+1)-(l+1)+1)%2 == 0 && r == n-1 && l == 2 )	cout << "No\n";
			else if ( ((r+1)-(l+1)+1)%2 == 0 ) {
				if ( l != 2 )	pl--;
				else pr--;
				if ( pl%2 && pr%2 )	cout << "Yes\n";
				else if ( pl%2 == 0 && pr%2 == 0 )	cout << "Yes\n";
				else	cout << "No\n";
			}
		}
	}
	return 0;
}

