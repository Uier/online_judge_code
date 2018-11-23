#include <iostream>
#define int long long
#define maxn 100005
using namespace std;
int cn2[maxn];
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, mn = 0, mx = 0;
	cin >> n >> m;
	for ( int i=2; i<=n; ++i )	cn2[i] = (i*(i-1))/2;
	if ( m*2 < n )	mn = n-m*2;
	int pos = lower_bound(cn2,cn2+1+n,m)-cn2;
	mx += pos;
	cout << mn << ' ' << n-mx << '\n';
	return 0;
}

