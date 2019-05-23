#include <iostream>
#define maxn 1505
using namespace std;
int arr[maxn], tmp[maxn];
bool ans;
void merge_sort(int l, int r) {
	if ( l == r )	return;
	int mid = l+r>>1;
	merge_sort(l,mid); 
	merge_sort(mid+1,r);
	int pt = l, ptl = l, ptr = mid+1;
	while ( pt <= r ) {
		if ( ptr > r || (ptl <= mid && arr[ptl] < arr[ptr]) ) {
			tmp[pt++] = arr[ptl++];
		} else {
			if ( (mid-ptl+1)&1 )	ans ^= 1;
			tmp[pt++] = arr[ptr++];
		}
	} 
	for ( int i=l; i<=r; ++i )	arr[i] = tmp[i];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q, l, r;
	cin >> n;
	for ( int i=0; i<n; ++i )	cin >> arr[i];
	merge_sort(0,n-1);
	cin >> q;
	while ( q-- && cin >> l >> r ) {
		int len = r-l+1;
		if ( (len/2)&1 )	ans ^= 1;
		cout << (ans ? "odd\n" : "even\n");
	}
	return 0;
}

