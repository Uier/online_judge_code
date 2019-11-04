#include <iostream>
#include <math.h>
#define int long long
#define maxn 105
using namespace std;
int arr[maxn];
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n, m, k;
	cin >> t;
	while ( t-- && cin >> n >> m >> k ) {
		for ( int i=1; i<=n; ++i )	cin >> arr[i];
		bool flag = true;
		for ( int i=1; i<n; ++i ) {
			if ( abs(arr[i]-arr[i+1]) <= k ) {
				if ( arr[i] > arr[i+1] ) {
					m += arr[i]-arr[i+1]+min(k,arr[i+1]);
				} else {
					m += min(k-(arr[i+1]-arr[i]),arr[i]);
				}
			} else if ( arr[i] > arr[i+1] ) {
				m += arr[i]-arr[i+1]+min(k,arr[i+1]);
			} else {
				m -= arr[i+1]-(arr[i]+k);
			}
			if ( m < 0 ) {
				flag = false;
				break;
			}
		}
		if ( flag )	cout << "YES\n";
		else	cout << "NO\n";
	}
	return 0;
}
/*
1
3 0 7
2 6 16

*/