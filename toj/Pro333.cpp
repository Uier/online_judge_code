#include <iostream>
using namespace std;
int a[10000005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	long long ans=0;
	cin >> n >> a[0];
	if ( n == 1 )
		cout << a[0] << '\n';
	else {
		for ( int i=1; i<n-1; i++ ) {
			cin >> a[i];
			if ( a[i-1]-a[i] > 0 )
				ans += a[i-1]-a[i];
		}
		cin >> a[n-1];
		ans += max(a[n-2],a[n-1]);
		cout << ans << '\n';
	}
	return 0;
}

