#include <iostream>
using namespace std;
int a[605], n, k;
bool check(int ans) {
	int sum = 0, res = 0;
	for ( int i=0; i<=n; i++ ) {
		sum += a[i];
		if ( sum > ans )
			sum = a[i], res++;
	}
	if ( sum )	res++;
	return	res <= k;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while ( cin >> n >> k ) {
		k++;	// zone = nights + 1;
		int l = 0, r = 1e6, m;
		for ( int i=0; i<=n; i++ ) {
			cin >> a[i];
			l = max(l,a[i]);
		}
		while ( l <= r ) {
			m = (l+r)/2;
			if ( check(m) )	r = m-1;
			else	l = m+1;
//			cout << "l: " << l << " r: " << r << " m: " << m << '\n';
		}
		cout << r+1 << '\n';
	}
	return 0;
}

