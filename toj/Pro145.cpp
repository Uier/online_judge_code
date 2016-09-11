#include <iostream>
using namespace std;
int n, m, k, q, a[1005][1005], x, xx, y, yy;
int sum(int i, int x) {
	int s=0;
	while ( x > 0 ) {
		s += a[i][x];
		x -= x&-x;
	}
	return s;
}
void add(int i, int x, int v) {
	while ( x <= n ) {
		a[i][x] += v;
		x += x&-x;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k >> q;
	while ( k-- ) {
		cin >> x >> y;
		add(x+1,y+1,1);	
	}
	while ( q-- ) {
		int ans = 0;
		cin >> x >> y >> xx >> yy;
		for ( int i=x+1; i<=xx+1; i++ )
			ans += sum(i,yy+1)-sum(i,y);
		cout << ans << '\n';
	}	
	return 0;
}

