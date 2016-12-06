#include <iostream>
using namespace std;
int a[100010];
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n, c, ans=1;
	cin >> n >> c >> a[0];
	for ( int i=1; i<n; i++ ) {
		cin >> a[i];
		ans++;
		if ( a[i]-a[i-1] > c )
			ans = 1;
	}
	cout << ans << '\n';
	return 0;
}

