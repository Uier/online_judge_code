#include <iostream>
#include <algorithm>
using namespace std;
int a[100005], dp[100005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x;
	long long ans=0;
	cin >> n >> x;
	for ( int i=0; i<n; i++ )
		cin >> a[i];
	sort(a,a+n);
	for ( int i=0; i<n; i++ ) {
		int y = (x^a[i]);
		ans += upper_bound(a+i+1,a+n,y)-lower_bound(a+i+1,a+n,y);
	}
	cout << ans << '\n';
	return 0;
}

