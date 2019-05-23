#include <iostream>
#include <algorithm>
#define maxn 105
using namespace std;
int arr[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, ans = 0;
	cin >> n;
	for ( int i=0; i<n; ++i )	cin >> arr[i];
	sort(arr,arr+n);
	for ( int i=0; i<n; i+=2 ) {
		ans += arr[i+1]-arr[i];
	}
	cout << ans << '\n';
	return 0;
}


