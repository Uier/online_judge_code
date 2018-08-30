#include <iostream>
#include <algorithm>
#define maxn 100005
using namespace std;
struct leg {
	int l, d;
} a[maxn], s[maxn];
inline bool cmp(leg x, leg y) {
	if ( x.d == y.d )	return x.l < y.l;
	return x.d > y.d;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, sum = 0, mn = 1e5, mx = 1;
	cin >> n;
	for ( int i=0; i<n; ++i ) {
		cin >> a[i].l;
		if ( a[i].l < mn )	mn = a[i].l;
		if ( a[i].l > mx )	mx = a[i].l;
	}
	for ( int i=0; i<n; ++i ) {
		cin >> a[i].d;
		s[a[i].l].l++;
		s[a[i].l].d += a[i].d;
		sum += a[i].d;
	}
	sort(a,a+n,cmp);
	int ans = 1e9;
	for ( int i=mn; i<=mx; ++i ) {
		if ( s[i].l == 0 )	continue;
		int rem = s[i].l-1, tmp = 0;
		if ( rem > n/2 ) {
			return cout << 0 << '\n', 0;
		}
		for ( int j=0; j<n&&rem; ++j ) {
			if ( a[j].l >= i )	continue;
			tmp += a[j].d;
			rem--;
		}
		ans = min(ans,sum-s[i].d-tmp);
	}
	cout << ans << '\n';
	return 0;
}

