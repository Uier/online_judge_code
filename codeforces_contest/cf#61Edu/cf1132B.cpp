#include <iostream>
#include <algorithm>
#define maxn 300005
#define int long long
using namespace std;
int arr[maxn];
main() {
	ios::sync_with_stdio(false);
	//   sync_with_YinHsuan(true);
	cin.tie(0);
	int n, m;
	int sum = 0;
	cin >> n;
	for ( int i=0; i<n; ++i ) {
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr,arr+n);
	cin >> m;
	for ( int i=0, x; i<m; ++i ) {
		cin >> x;
		cout << sum-arr[n-x] << '\n';
	}
	return 0;
}

