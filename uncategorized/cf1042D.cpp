#include <iostream>
#define int long long
#define maxn 200005
using namespace std;
int n, t, pre[maxn], tmp[maxn];
int merge_sort(int l, int r) {
	if ( l == r )	return 0;
	int cnt = 0, mid = l+r>>1;
	cnt += merge_sort(l,mid);
	cnt += merge_sort(mid+1,r);
	int pt = l, ptl = l, ptr = mid+1;
	for ( ; ptl<=mid; ++ptl ) {
		while ( ptr <= r && pre[ptr]-pre[ptl] < t )	ptr++;
		cnt += r-ptr+1;
	}
	ptl = l, ptr = mid+1;
	while ( pt <= r ) {
		if ( ptl > mid || ( ptr <= r && pre[ptl] > pre[ptr]) )
			tmp[pt++] = pre[ptr++];
		else	tmp[pt++] = pre[ptl++];
	}
	for ( int i=l; i<=r; ++i )	pre[i] = tmp[i];
	return cnt;
}
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, t;
	cin >> n >> t;
	for ( int i=1, x; i<=n; ++i ) {
		cin >> x;
		pre[i] = pre[i-1] + x;
	}
	cout << (n*(n+1))/2 << '\n';
	cout << merge_sort(1,n) << '\n';
//	cout << (n*(n+1))/2-merge_sort(1,n) << '\n';
	return 0;
}

