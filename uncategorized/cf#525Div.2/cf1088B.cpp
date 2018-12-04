#include <iostream>
#include <algorithm>
#define maxn 100005
using namespace std;
int arr[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for ( int i=0; i<n; ++i )	cin >> arr[i];
	sort(arr,arr+n);
	long long sum = 0, pre = 0;
	for ( int i=0; i<k; ++i ) {
		int pos = upper_bound(arr,arr+n,sum)-arr;
		if ( pos < n ) {
			cout << arr[pos]-sum << '\n';
			sum += arr[pos]-pre;
			pre = arr[pos];
		} else	cout << 0 << '\n';
	}
	return 0;
}

