#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int arr[505];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, t;
	cin >> t;
	while ( t-- && cin >> n ) {
		for ( int i=0; i<n; ++i )	cin >> arr[i];
		sort(arr,arr+n);
		int ans = 0;
		for ( int i=0; i<n; ++i ) ans += abs(arr[n>>1]-arr[i]);
		cout << ans << '\n';
	}
	return 0;
}

