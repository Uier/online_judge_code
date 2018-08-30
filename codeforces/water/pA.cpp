#include <iostream>
#include <math.h>
using namespace std;
int a[400], pre[400];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, ans = 360;
	cin >> n;
	for ( int i=1; i<=n; ++i ) {
		cin >> a[i];
		pre[i] = pre[i-1] + a[i];
	}
	for ( int i=1; i<=n; ++i ) {
		for ( int j=i; j<=n; ++j ) {
			int tmp = pre[j]-pre[i-1];
			ans = min(ans,abs(360-tmp*2));
		}
	}
	cout << ans << '\n';
	return 0;
}

