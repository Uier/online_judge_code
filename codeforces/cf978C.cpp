#include <iostream>
#define maxn 200005
#define int long long
using namespace std;
int a[maxn];
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m >> a[0];
	for ( int i=1; i<n; ++i ) {
		cin >> a[i];
		a[i] += a[i-1];
	}
	int x;
	for ( int i=0; i<m; ++i ) {
		cin >> x;
		int pos = lower_bound(a,a+n,x)-a;
		cout << pos+1 << ' ';
		if ( pos == 0 )
			cout << x << '\n';
		else
			cout << x-a[pos-1] << '\n';
	}
	return 0;
}

