#include <iostream>
#include <algorithm>
#define maxn 100005
using namespace std;
int arr[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	long long sum = 0;
	cin >> n >> m;
	for ( int i=0; i<n; ++i ) {
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr,arr+n);
	long long ans = sum-max(n,arr[n-1]), d = arr[n-1]-n;
	if ( d >= 0 ) 
		for ( int i=n-1; i>0; --i )
			if ( arr[i]-arr[i-1]-1 > d )
				ans -= arr[i]-arr[i-1]-1;
	cout << ans << '\n';
//	long long mx = arr[n-1]-1, ans = 0, cnt = 0, i;
//	for ( i=n-1; i>0&&cnt<mx; --i ) {
//		if ( arr[i] == 1 )	break;
//		if ( arr[i] == arr[i-1] ) {
//			ans += arr[i]-1;
//			cnt += 1;
//		} else {
//			ans += arr[i]-(arr[i]-arr[i-1]);
//			cnt += arr[i]-arr[i-1];
//		}
//	}
//	if ( cnt >= mx ) {
//		for ( ; i>=0; --i )	ans += arr[i]-1;
//	}
//	cout << ans << '\n';
	return 0;
}

