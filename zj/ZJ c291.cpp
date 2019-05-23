#include <iostream>
using namespace std;
int p[50005];
int find(int x) {
	return (p[x]==x ? x : (p[x]=find(p[x])));
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=0; i<n; ++i )	p[i] = i;
	int ans = n;
	for ( int i=0, x; i<n; ++i ) {
		cin >> x;
		int ti = find(i), tx = find(x);
		if ( ti != tx ) {
			ans--;
			p[tx] = ti;
		}
	}
	cout << ans << '\n';
	return 0;
}

