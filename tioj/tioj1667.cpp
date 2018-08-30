#include <iostream>
#define maxn 100005
using namespace std;
int arr[maxn], tmp[maxn];
long long ans;
void merge_sort(int l, int r) {
	if ( l == r )	return;
	int mid = (l+r)/2;
	merge_sort(l,mid);
	merge_sort(mid+1,r);
	int pt = l, ptl = l, ptr = mid+1;
	while ( pt <= r )
		if ( ptl > mid || ( ptr <= r && arr[ptl] > arr[ptr]) ) {
			tmp[pt++] = arr[ptr++];
			ans += ptr-pt;
		}
		else	tmp[pt++] = arr[ptl++];
	for ( int i=l; i<=r; ++i )	arr[i] = tmp[i];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while ( cin >> n ) {
		ans = 0;
		for ( int i=0; i<n; ++i )	cin >> arr[i];
		merge_sort(0,n-1);
		cout << ans << '\n';
	}
	return 0;
}

