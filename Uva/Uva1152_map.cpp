#include <iostream>
#include <unordered_map>
using namespace std;
int t, n, x, a[4005], b[4005], c[4005], d[4005], ans;
unordered_map<int,int> k;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while ( t-- ) {
		ans = 0;
		k.clear();
		cin >> n;
		for ( int i=0; i<n; i++ )
			cin >> a[i] >> b[i] >> c[i] >> d[i];
		for ( int i=0; i<n; i++ )
			for ( int j=0; j<n; j++ )
				k[a[i]+b[j]]++;
		for ( int i=0; i<n; i++ )
			for ( int j=0; j<n; j++ )
				ans += k[-c[i]-d[j]];
		cout << ans << '\n';
		if ( t )	cout << '\n';
	}
	return 0;
}

