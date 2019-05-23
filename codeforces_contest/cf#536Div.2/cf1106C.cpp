#include <iostream>
#include <algorithm>
#define maxn 300005
using namespace std;
long long arr[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	long long sum = 0, x, y;
	for ( int i=0; i<n; ++i )	cin >> arr[i];
	sort(arr,arr+n);
	for ( int i=0; i<n/2; ++i ) {
		sum += (arr[i]+arr[n-1-i])*(arr[i]+arr[n-1-i]);
	}
	cout << sum << '\n';
	return 0;
}

