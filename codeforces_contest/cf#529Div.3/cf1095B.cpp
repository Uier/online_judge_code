#include <iostream>
#include <algorithm>
#define maxn 100005
using namespace std;
int arr[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=0; i<n; ++i )	cin >> arr[i];
	sort(arr,arr+n);
	cout << min(arr[n-1]-arr[1],arr[n-2]-arr[0]) << '\n';
	return 0;
}


