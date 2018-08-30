#include <iostream>
#define maxn 200005
#define int long long
using namespace std;
int a[maxn], cnt[maxn];
/*
WA WA WA WA WA
*/
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for ( int i=0; i<n; ++i ) {
		cin >> a[i];
		cnt[a[i]%m]++;
	}
	int pt = 0, ans = 0;
	for ( int i=0; i<n; ++i )
		if ( cnt[a[i]%m] > n/m ) {
			while ( cnt[pt] >= n/m )	pt++;
			cnt[a[i]%m]--;
			cnt[pt]++;
			int tmp = (pt-(a[i]%m)+m)%m;
			a[i] += tmp;
			ans += tmp;
		}
	cout << ans << '\n';
	for ( int i=0; i<n; ++i )	cout << a[i] << ' ';
	cout << '\n';
	return 0;
}

