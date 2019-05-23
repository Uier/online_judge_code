#include <iostream>
#include <string.h>
#define maxn 200005 
using namespace std;
int arr[maxn], tmp[maxn], inv[maxn];
void mrg_sort(int l, int r) {
	if ( l >= r )	return;
	int mid = l+r>>1;
	mrg_sort(l,mid);
	mrg_sort(mid+1,r);
	int pt = l, ptl = l, ptr = mid+1, cnt = 0;
	while ( pt <= r ) {
		if ( ptr > r || (ptl <= mid && arr[ptl] < arr[ptr]) ) {
			inv[arr[ptl]] += cnt;
			tmp[pt++] = arr[ptl++];
		} else {
			cnt++;
			tmp[pt++] = arr[ptr++];
		}
	}
	for ( int i=l; i<=r; ++i )	arr[i] = tmp[i];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, x;
	while ( cin >> n >> m ) {
		for ( int i=0; i<n; ++i )	cin >> arr[i];
		memset(inv,0,sizeof(inv));
		mrg_sort(0,n-1);
		long long sum = 0;
		for ( int i=1; i<=n; ++i )	sum += inv[i];
		while ( m-- && cin >> x ) {
			cout << sum << '\n';
			sum -= inv[x];
		}
	}
	return 0;
}

