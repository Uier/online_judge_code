#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll INF=1000000000;
ll d[105][105];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while ( t-- ) {
		int n, m;
		cin >> n >> m;
		for ( int i=1; i<=n; i++ )
			for ( int j=1; j<=n; j++ ) {
				if ( i == j )
					d[i][j] = 0;
				else
					d[i][j] = INF;
			}
		while ( m-- ) {
			int a, b, c;
			cin >> a >> b >> c;
			if ( a != b && d[a][b] > c )
				d[a][b] = c;
		}
		for ( int k=1; k<=n; k++ )
			for ( int i=1; i<=n; i++ )
				for ( int j=1; j<=n; j++ )
					d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
		int q;
		cin >> q;
		while ( q-- ) {
			int a, b;
			cin >> a >> b;
			if ( d[a][b] >= INF )
				cout << -1 << '\n';
			else
				cout << d[a][b] << '\n';
		}
	}
	return 0;
}

