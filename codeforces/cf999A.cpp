#include <iostream>
using namespace std;
int a[105];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for ( int i=0; i<n; ++i ) {
		cin >> a[i];
	}
	int pt = 0, ans = 0;
	for ( int i=0; i<n; ++i ) {
		if ( a[i] <= k )	ans++;
		else	break;
	}
	if ( ans != n )	 {
		for ( int i=n-1; i>=0; --i ) {
			if ( a[i] <= k )	ans++;
			else break;
		}
	}
	cout << ans << '\n';
	return 0;
	
}

