#include <iostream>
using namespace std;
long long n;
int k, a[100005];
bool greater_(int m) {
	long long L = 0, R = 0, cnt = 0, sum = 0;
	while ( L <= R ) {
		if ( a[R] > m && L == R )	L = R = L+1;
		while ( R < n && m >= sum+a[R] )	sum += a[R++];
		cnt += R-L;
		sum -= a[L++];
	}
	return (n*(n-1)/2+n-cnt+1) > k;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for ( int i=0; i<n; ++i )	cin >> a[i];
	int l = 1, r = 1e9, mid;
	while ( l < r ) {
		mid = (l+r)/2;
		if ( greater_(mid) )	l = mid;
		else	r = mid;
		if ( l+1 == r ) {
			if ( greater_(l) )	l = r;
			break;
		}
	}
	int L = 0, R = 0, ans = 0, sum = 0;
	while ( L <= R ) {
		if ( a[R] > l && L == R )	L = R = L+1;
		while ( R < n && l >= sum+a[R] )	sum += a[R++];
		ans = max(ans,sum);
		sum -= a[L++];
	}
	cout << ans << '\n';
	return 0;
}

