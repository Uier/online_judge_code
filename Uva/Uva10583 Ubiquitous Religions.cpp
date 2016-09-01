#include <iostream>
using namespace std;
int p[50010];
int find(int x) {
	return (p[x]==x) ? x : (p[x]=find(p[x]));
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, x=0;
	while ( cin >> n >> m ) {
		if ( n == 0 )
			break;
		int ans=n;
		for ( int i=1; i<=n; i++ ) p[i] = i;
		while ( m-- ) {
			int a, b;
			cin >> a >> b;
			if ( find(a) != find(b) )
				ans--;
			p[find(a)] = find(b);
		}
		x++;
		cout << "Case " << x << ": " << ans << '\n';
	}
	return 0;
}

