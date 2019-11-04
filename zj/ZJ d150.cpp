#include <iostream>
#include <algorithm>
#define maxn 20005
using namespace std;
int arr[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n;
	cin >> t;
	while ( t-- && cin >> n ) {
		for ( int i=0; i<n; ++i )	cin >> arr[i];
		sort(arr,arr+n);
		reverse(arr,arr+n);
		int ans = 0;
		for ( int i=2; i<n; i+=3 )	ans += arr[i];
		cout << ans << '\n';
	}
	return 0;
}