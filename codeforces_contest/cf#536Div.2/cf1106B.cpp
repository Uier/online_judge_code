#include <iostream>
#include <algorithm>
#define maxn 100005
#define int long long
using namespace std;
struct item {
	int x, c, idx;
} v[maxn], s[maxn];
int mp[maxn];
bool cmp(item x, item y) {
	if ( x.c == y.c )	return x.idx < y.idx;
	return x.c < y.c;
}
main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, a, b, pt = 1;
	cin >> n >> m;
	for ( int i=1; i<=n; ++i )	cin >> v[i].x;
	for ( int i=1; i<=n; ++i ) {
		cin >> v[i].c;
		v[i].idx = i;
		s[i] = v[i];
	}
	sort(s+1,s+1+n,cmp);
//	for ( int i=1; i<=n; ++i )
//		cout << s[i].x << ' ' << s[i].c << ' ' << s[i].idx << '\n';
	for ( int i=1; i<=n; ++i ) {
		mp[s[i].idx] = i;
	}
	int ans = 0;
	while ( m-- && cin >> a >> b ) {
		int sum = 0;
		bool fail = false;
		if ( v[a].x >= b ) {
			v[a].x -= b;
			s[mp[a]].x -= b;
			sum += v[a].c*b;
		} else {
			b -= v[a].x;
			sum += v[a].c*v[a].x;
			v[a].x = 0;
			s[mp[a]].x = 0;
			while ( b > 0 ) {
//				cout << "b,pt: " << b << ' ' << pt << '\n';
				while ( pt <= n && s[pt].x <= 0 )	pt++;
				if ( pt > n ) {
					fail = true;
					break;
				}
				if ( s[pt].x >= b ) {
					s[pt].x -= b;
					v[s[pt].idx].x -= b;
					sum += s[pt].c*b;
					b = 0;
				} else {
					b -= s[pt].x;
					sum += s[pt].x*s[pt].c;
					s[pt].x = 0;
					v[s[pt].idx].x = 0;
				}
			}
		}
		if ( fail )	cout << 0 << '\n';
		else	cout << sum << '\n';
	}
	return 0;
}

