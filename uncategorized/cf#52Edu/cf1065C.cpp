#include <iostream>
#include <algorithm>
#define maxn 200005
using namespace std;
int arr[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k, mn = -1, mx = -1;
	cin >> n >> k;
	for ( int i=0, x; i<n; ++i ) {
		cin >> arr[i];
		if ( mn == -1 || arr[i] < mn )	mn = arr[i];
		if ( mx == -1 || arr[i] > mx )	mx = arr[i];
	}
	sort(arr,arr+n);
	int ans = 0, i = mn;
	while ( i < mx ) {
		int cnt = n-(upper_bound(arr,arr+n,i)-arr);
		while ( i < mx && cnt <= k ) {
			i++;
			cnt += n-(upper_bound(arr,arr+n,i)-arr);
		}
		ans++;
	}
	cout << ans << '\n';
	return 0;
}
