#include <iostream>
#define maxn 20005
using namespace std;
int n, k, arr[maxn], pre[maxn], tmp[maxn], ans;
int merge_sort(int l, int r, int p) {
	if ( l == r )	return 0;
	int cnt = 0, mid = l+r>>1;
	cnt += merge_sort(l,mid,p);
	cnt += merge_sort(mid+1,r,p);
	int pt = l, ptl = l, ptr = mid+1;
	for ( ; ptl<=mid; ++ptl ) {
		while ( ptr <= r && pre[ptr]-pre[ptl] <= p )	ptr++;
		cnt += r-ptr+1;
	}
	ptl = l, ptr = mid+1;
	while ( pt <= r )
		if ( ptr <= r && (ptl > mid || pre[ptr] < pre[ptl]) )
			tmp[pt++] = pre[ptr++];
		else
			tmp[pt++] = pre[ptl++];
	for ( int i=l; i<=r; ++i )	pre[i] = tmp[i];
	return cnt;
}
void merge_find(int l, int r, int p) {
	if ( l == r )	return;
	int mid = l+r>>1;
	merge_find(l,mid,p);
	merge_find(mid+1,r,p);
	int pt = l, ptl = l, ptr = mid+1;
	for ( ; ptl<=mid; ++ptl ) {
		while ( ptr <= r && pre[ptr]-pre[ptl] < p )	ptr++;
		if ( ptr <= r )	ans = min(ans,pre[ptr]-pre[ptl]);
	}
	ptl = l, ptr = mid+1;
	while ( pt <= r )
		if ( ptr <= r && (ptl > mid || pre[ptr] < pre[ptl]) )
			tmp[pt++] = pre[ptr++];
		else
			tmp[pt++] = pre[ptl++];
	for ( int i=l; i<=r; ++i )	pre[i] = tmp[i];
}
inline bool check(int p) {
	int cnt = 0;
	for ( int i=1; i<=n; ++i ) {
		pre[i] = pre[i-1]+arr[i];
		if ( pre[i] > p )	cnt++;
	}
	return cnt+merge_sort(1,n,p) > k-1;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while ( cin >> n >> k && (n || k) ) {
		for ( int i=1; i<=n; ++i )	cin >> arr[i];
		int l = -2e8, r = 2e8;
		while ( l < r ) {
			int mid = l+r>>1;
			if ( check(mid) )	l = mid;
			else	r = mid;
			if ( l+1 == r )	l = r;
		}
		ans = 2e9;
		for ( int i=1; i<=n; ++i ) {
			pre[i] = pre[i-1] + arr[i];
			if ( pre[i] >= l && pre[i] < ans )	ans = pre[i];
		}
		merge_find(1,n,l);
		cout << ans << '\n';
	}	
	return 0;
}

