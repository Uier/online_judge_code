#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
#define maxn 1005
using namespace std;
int arr[maxn];
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=0; i<n; ++i )	cin >>arr[i];
	sort(arr,arr+n);
	cout << arr[n-1]-arr[0]+1-n << '\n';
	return 0;
}

