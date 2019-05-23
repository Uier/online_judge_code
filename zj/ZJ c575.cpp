#include <iostream>
#include <algorithm>
#define maxn 50005
using namespace std;
int n, k, arr[maxn];
bool check(int r) {
	int l = 0, coda = k;
	while ( coda-- ) {
		l = upper_bound(arr,arr+n,arr[l]+r)-arr;
		if ( l == n )	return true;
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for ( int i=0; i<n; ++i )	cin >> arr[i];
	sort(arr,arr+n);
	int l = 1, r = 1e9; 
	while ( l < r ) {
		int mid = l+r>>1;
		if ( check(mid) ) {
			r = mid;
		} else {
			if ( l == mid )	l = r;
			else	l = mid;
		}
	}
	cout << l << '\n';
	return 0;
}

