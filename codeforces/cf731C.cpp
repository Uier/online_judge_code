#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[200010], p[200010], n, m, k, l, r, ans;
vector<int> s[200010];
void init() {
	for ( int i=0; i<=n; i++ ) {
		p[i] = i;
		s[i].clear();
	}
}
int find(int x) {
	return (p[x]==x) ? x : (p[x]=find(p[x]));
}
void U(int x, int y) {
	p[find(x)] = find(y);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for ( int i=1; i<=n; i++ )
		cin >> a[i];
	init();
	for ( int i=0; i<m; i++ ) {	
		// socks which wear on same day will be united
		cin >> l >> r;
		if ( find(l) != find(r) )
			U(l,r);
	}
	//	push the color of same-day-wear socks into a same vector
	for ( int i=1; i<=n; i++ )
		s[find(i)].push_back(a[i]);
	for ( int i=1; i<=n; i++ ) {
		if ( s[i].size() <= 1 )	continue;
		// after sort, the same color will line up
		sort(s[i].begin(),s[i].end());
		// to search the color which is found the most time of all
		int x=s[i][0], maxx=0, now=0;
		for ( int y : s[i] ) {
			if ( x == y )	now++;
			else {
				maxx = max(maxx,now);
				now = 1;
				x = y;
			}
		}
		maxx = max(maxx,now);
		// add
		ans += (s[i].size()-maxx);
	}
	cout << ans << '\n';
	return 0;
}

