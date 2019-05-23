#include <iostream>
#include <algorithm>
using namespace std;
int arr[1005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=0; i<n; ++i )	cin >> arr[i];
	int idx = -1, idxans = 0;
	for ( int i=1; i<=100; ++i ) {
		int ans = 0;
		for ( int j=0; j<n; ++j ) {
			if ( arr[j] > i )	ans += arr[j]-(i+1);
			else if ( arr[j] < i )	ans += i-1-arr[j];
		}
		if ( idx == -1 || ans < idxans ) {
			idx = i;
			idxans = ans;
		}
	}
	cout << idx << ' ' << idxans << '\n';
//	sort(arr,arr+n);
//	int m = arr[n/2], ans = 0;
//	for ( int i=0; i<n; ++i ) {
//		if ( arr[i] < m )	ans += m-1-arr[i];
//		else if ( arr[i] > m )	ans += arr[i]-(m+1);
//	}
//	if ( n&1 == 0 ) {
//		int mm = arr[n/2-1], newans = 0;
//		for ( int i=0; i<n; ++i ) {
//			if ( arr[i] < m )	newans += m-1-arr[i];
//			else if ( arr[i] > m )	newans += arr[i]-(m+1);
//		}
//		if ( newans < ans )	return cout << mm << ' ' << ans << '\n', 0;
//	}
//	cout << m << ' ' << ans << '\n';
	return 0;
}

