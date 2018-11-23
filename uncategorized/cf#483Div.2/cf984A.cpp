#include <iostream>
#include <algorithm>
using namespace std;
int arr[1005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=0; i<n; ++i ) {
		cin >> arr[i];
	}
	sort(arr,arr+n);
	if ( n&1 )	cout << arr[n/2] << '\n';
	else	cout << arr[n/2-1] << '\n';
	return 0;
}

