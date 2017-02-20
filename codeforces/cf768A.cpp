#include <iostream>
#include <algorithm>
using namespace std;
int a[100005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, ans = 0;
	cin >> n;
	for ( int i=0; i<n; i++ )
		cin >> a[i];
	sort(a,a+n);
	int l = a[0], r = a[n-1];
	for ( int i=1; i<n-1; i++ )
		if ( a[i] > l && a[i] < r )
			ans++;
	cout << ans << '\n';
	return 0;
}

