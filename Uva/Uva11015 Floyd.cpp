#include <iostream>
using namespace std;
typedef long long ll;
string a[25];
const ll INF=10000000;
ll d[235][235];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, x=0;
	while ( cin >> n >> m ) {
		if ( n == 0 )
			break;
		x++;
		for ( int i=1; i<=n; i++ )
			cin >> a[i];
		for ( int i=1; i<235; i++ )
			for ( int j=1; j<235; j++ )
				if ( i == j )
					d[i][j] = 0;
				else
					d[i][j] = INF;
		while ( m-- ) {
			int a, b, c;
			cin >> a >> b >> c;
			d[a][b] = c;
			d[b][a] = c;
		}
		for ( int k=1; k<=n; k++ )
			for ( int i=1; i<=n; i++ )
				for ( int j=1; j<=n; j++ )
					d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
		long long sum, ans=INF, anum=-1;
		for ( int i=1; i<=n; i++ ) {
			sum = 0;
			for ( int j=1; j<=n; j++ )		
				sum += d[i][j];
			if ( (sum < ans) || (sum == ans && anum > i) ) {
				ans = sum;
				anum = i;
			}
		}
		cout << "Case #" << x << " : ";
		cout << a[anum] << '\n';
	}
	return 0;
}

