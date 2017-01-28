#include <iostream>
using namespace std;
int t, n, m, p[30005], cnt[30005], a, b, ans;
int find(int x) {
	return (p[x]==x) ? x : (p[x]=find(p[x]));
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while ( t-- && cin >> n >> m ) {
		for ( int i=1; i<=n; i++ ) {
			p[i] = i;
			cnt[i] = 0;
		}
		while ( m-- && cin >> a >> b )
			p[find(b)] = find(a);
		for ( int i=1; i<=n; i++ )
			cnt[find(i)]++;
		ans = 0;
		for ( int i=1; i<=n; i++ )
			ans = max(ans,cnt[i]);
		cout << ans << '\n';
	}
	return 0;
}

